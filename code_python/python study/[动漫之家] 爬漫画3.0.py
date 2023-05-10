# 按步骤说明一下下面代码的作用：
# 1. 通过输入关键词，获取搜索结果
# 2. 展示搜索结果，让用户选择
# 3. 获取每一话的链接
# 4. 获取每一话所有图片的加密链接（字典）
# 5. 解密图片链接
# 6. 下载图片
# 7. 报告下载结果

from concurrent.futures import ThreadPoolExecutor, as_completed
import threading
import bs4
import requests
import json
import time
import re
import os
import tqdm

MAX_WORKERS = 5
headers = {'user-agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/111.0.0.0 Safari/537.36 Edg/111.0.1661.54'}
executor = ThreadPoolExecutor(MAX_WORKERS)
lock = threading.Lock()
elapsed_times = []


def open_url(url: str):  # 返回查询结果
    res = requests.get(url, headers=headers)
    return res


def display(text: str):  # 展示查询结果
    comics = []
    data = re.findall('\{[^{}]*\}', text)
    print("\033[H\033[2J", end='')
    print('The search results are as follows:\n')
    length = len(data)
    for i in range(length):
        comic = json.loads(data[i])
        comics.append(comic)
        print(f'————————————————————————————< {i+1}/{length} >———————————————————————————————\n{"名称"}: \033[33m{comic["comic_name"]}\033[0m\n{"作者"}: {comic["comic_author"]}\n{"最新章节"}: {comic["last_update_chapter_name"]}')
    id = int(input('————————————————————————————< end >———————————————————————————————\nWhich comic do you want?\n')) - 1
    print("正在获取链接，请稍候...")
    return comics[id]


def get_page_url(comic: dict[str, str]):  # 获取每一话的链接
    page_urls = {}
    comic_text = open_url('https:' + comic['comic_url']).text # "//www.dmzj.com/info/benghuai3rd.html"
    soup = bs4.BeautifulSoup(comic_text, 'html.parser')
    if 'info' in comic['comic_url']:
        result = soup.select('.zj_list>.tab-content:nth-child(4) a')
        prefix = ''
        mode = 0
        # TODO 有可能没版权，所以要判断一下
    else:
        result = soup.find('div', class_="cartoon_online_border")
        result = result.find_all('a') if result else None
        prefix = 'https://manhua.dmzj.com'
        mode = 1
    if result:
        i = 1
        for each in result:
            page_urls[f'{each.text}_{i}'] = prefix + each['href']
            i += 1
        return page_urls, mode
    else:
        return None

def get_img_url(page_urls: dict[str, str], mode: int):  # 21.55s -> 3.36s 快了6倍
    img_urls_dict = {}
    index_data = {}
    value = {}
    img_count = 0

    def task1(data: tuple[str, str]):  # 线程任务
        chapter, url = data
        res = open_url(url).text
        soup = bs4.BeautifulSoup(res, 'html.parser')
        script = soup.find('script').text
        value = eval(f'''[{re.search("(?<=';',).*(?=,')", script).group()}]''')  # 获取一对参数
        index_data = re.search("(?<=\d,').*(?='\.split)", script).group()  # 获取索引
        img_urls_list = eval(re.search("(?<=\w=\\\\\\').*?(?=\\\\\\')", script).group())  # 获取图片url (?<='\w \w=\\').*?(?=\\')
        return chapter, img_urls_list, index_data, value

    def task2(data: tuple[str, str]):  # 线程任务
        chapter, url = data
        res = open_url(url).text
        soup = bs4.BeautifulSoup(res, 'html.parser')
        script = soup.find('script').text
        value = eval(f'''[{re.search("(?<=';',).*(?=,')", script).group()}]''')  # 获取一对参数
        index_data = re.search("(?<=\d,').*(?='\.split)", script).group()  # 获取索引
        string = re.search('''(?<={"\w":"\w","\w":"\w","\w":").*?(?=")''', script).group()
        img_urls_list = eval(f"str('{string}')").split("\\r\\")  # 获取图片url (?<='\w \w=\\').*?(?=\\')
        return chapter, img_urls_list, index_data, value

    for result in executor.map(task1 if mode else task2, zip(page_urls.keys(), page_urls.values())):
        chapter, img_urls_dict[chapter], index_data[chapter], value[chapter] = result
        img_count += len(img_urls_dict[chapter])

    return img_urls_dict, index_data, img_count, value

def f(str, arg1, arg2, table, zero, empty):  # 解密函数
    def base36(number):
        assert isinstance(number, int), 'number must be an integer'
        assert number >= 0, 'number must be positive'
        if number == 0:
            return '0'
        alphabet = '0123456789abcdefghijklmnopqrstuvwxyz'
        base36 = ''
        while number != 0:
            number, i = divmod(number, 36)
            base36 = alphabet[i] + base36
        return base36

    def zero(c): return (zero(int(c / arg1)) if c >= arg1 else '') + (chr(c % arg1 + 29) if c % arg1 > 35 else base36(c % arg1))
    while arg2:
        arg2 -= 1
        empty[zero(arg2)] = table[arg2] or zero(arg2)
    return re.sub(r'\b\w+\b', lambda c: empty[c.group()], str)

def index_decode(img_urls_dict: dict[str, str], index_data: dict[str, str], values: dict[str, str]):  # 解密图片链接
    for chapter in img_urls_dict:  # 每一话
        img_urls, index_table, value = img_urls_dict[chapter], index_data[chapter].split('|'), values[chapter]
        # 's\\/%0%7%i%2%9%r%0%7%i%1%5%n%2%9%f%4%o%6%2%m%c%3%q%7%0%t%5%1%5%e%0%k%6%0%a%g%d%6%l%4%h%p%3%z%u%3%b%c%d%C%E%0%G%8%2%D%b%1%a%A%4%w%8%4%e%j\\/%1%g%j%1%h%f%0%B%v%3%x%y\\/K.F'
        sample = img_urls[0]

        # 拼接模板
        # 's\\/%0%7%i%2%9%r%0%7%i%1%5%n%2%9%f%4%o%6%2%m%c%3%q%7%0%t%5%1%5%e%0%k%6%0%a%g%d%6%l%4%h%p%3%z%u%3%b%c%d%C%E%0%G%8%2%D%b%1%a%A%4%w%8%4%e%j/%1%g%j%1%h%f%0%B%v%3%x%y'
        datas = sample[:sample.rfind('\\/')].replace('\\/', '/')
        decode_url = f"https://images.dmzj.com/" + f(datas, value[0], value[1], index_table, 0, {}) + "/" # https://images.dmzj.com/img/chapterpic/41662/150599/16801607277604.jpg

        # 加上页数
        decode_urls = []
        for url in img_urls:  # 每一张
            suffix = f(url[url.rfind('/')+1:], value[0], value[1], index_table, 0, {})  # 图片格式 - K.F
            decode_urls.append(decode_url + suffix)

        img_urls_dict[chapter] = decode_urls

    return img_urls_dict


# 下载图片
def download(comic_name: str, img_urls_dict: dict[str, str], img_count: int, pbar = None):
    assert os.path.exists(
        "D:\\Downloads\\dmzj\\"), 'Please ensure this path exists: "D:\\Downloads\\dmzj\\"'

    print("\033[H\033[2J", end='')
    path = f"D:\\Downloads\\dmzj\\{comic_name}"
    if not os.path.exists(path):
        os.makedirs(path)

    err_urls = {}

    def task(chapter: str): # 下载每一话
        err_url = {}
        No = chapter.split('_')
        file_path = f'{path}\\【{No[1]}】{No[0]}\\'
        if not os.path.exists(file_path):
            os.makedirs(file_path)

        i = 0
        for img_path in img_urls_dict[chapter]:  # 每一张
            count = 0
            i += 1
            name = img_path.split('/')[-1]
            image = requests.get(img_path, headers=headers)
            while image.status_code != 200 and count < 3:
                image = requests.get(img_path, headers=headers)
                count += 1
            if image.status_code != 200 or "Code" in image.text:
                err_url[f'{chapter}({i})'] = img_path  # 记录错误链接的章节页码
            else:
                with open(file_path + name, 'wb') as f:
                    f.write(image.content)
            if pbar:
                with lock:  # 死锁高发区
                    pbar.update(1)
        return err_url

    thread_list = []
    for chapter in img_urls_dict.keys():
        thread = executor.submit(task, chapter)
        thread_list.append(thread)

    for future in as_completed(thread_list):
        err_urls |= future.result()
    
    executor.shutdown()

    return img_count, len(err_urls), err_urls


def report(img_count: int, err_count: int, err_urls: dict, elapsed_times: list):
    print('—————————————————————————————————————————————————————————————————————————————————————————')
    print(f'Total: \033[33m{img_count}\033[0m images | Success: \033[32m{img_count - err_count}\033[0m images | Failure: \033[31m{err_count}\033[0m images')
    print('—————————————————————————————————————————————————————————————————————————————————————————')
    print('This run takes \033[33m%.2f\033[0m seconds: ' % (elapsed_times[2]))
    print('  · \033[36mget_img_url\033[0m: \033[33m%.2fs\033[0m' % (elapsed_times[0]))
    print('  · \033[36mdownload\033[0m: \033[33m%.2fs\033[0m' % (elapsed_times[1]))
    print('  · \033[36melse\033[0m: \033[33m%.2fs\033[0m' % (elapsed_times[2] - elapsed_times[0] - elapsed_times[1]))
    print('—————————————————————————————————————————————————————————————————————————————————————————\nThese \033[31merror links\033[0m are as follows:' if err_count else '')
    for each in err_urls:
        print(f'{each}: \033[36m{err_urls[each]}\033[0m')

# 计时器
def timer(func):
    def wrapper(*args):
        start_time = time.time()
        res = func(*args)
        end_time = time.time()
        elapsed_times.append(end_time - start_time)
        return res
    return wrapper

# 测试一下在不同最大线程数的情况下，get_img_url函数的运行时间
# def test():
#     print("\033[H\033[2J", end='')
#     global MAX_WORKERS
#     for i in range(1, 11):
#         MAX_WORKERS = i
#         print('当前最大线程数为：', i)
#         timer(get_img_url)(page_urls)
#         print('—————————————————————————————————————————————————————————————————————————————————————————')

def progress_bar(func, total: int): # 开启进度条
    def run(*args):
        pbar = tqdm.tqdm(total=total, desc='Total download progress', unit='image')
        res = func(*args, pbar)
        pbar.close()
        return res
    return run

if __name__ == '__main__':
    open_pbar = True # <-------------------------------------------------------------------- 是否开启进度条（无进度条的速度会快一点）
    key_word = input("Please enter the keyword you want to search:\n")
    res_text = open_url(f'https://sacg.dmzj.com/comicsum/search.php?s={key_word}').text
    while True:
        reception = display(res_text)
        comic_name = reception['comic_name']
        start = time.time()
        page_urls = get_page_url(reception)
        if page_urls:
            img_urls_dict, index_data, img_count, value = timer(get_img_url)(page_urls[0], page_urls[1])
            img_count, err_count, err_urls = progress_bar(timer(download), img_count)(comic_name, index_decode(img_urls_dict, index_data, value), img_count) if open_pbar else download(comic_name, index_decode(img_urls_dict, index_data, value), img_count)
            end = time.time()
            elapsed_times.append(end - start)
            report(img_count, err_count, err_urls, elapsed_times)
            input('\nPress Enter to continue...')
            break
        else:
            print('This comic is \033[31mnot copyrighted\033[0m to watch \033[33mor\033[0m this is an \033[32mexternal link\033[0m comic.')
            if input('Do you want to choose one again? (y/n):\n') == 'y':
                print("\033[H\033[2J", end='')
                continue
            else:
                break
# 搜"夏娜"，选"3"
# 单线程用时  538.18秒
# 多线程用时  313.36秒 | 使用as_completed优化后  278.47秒
# 多线程（无进度条）用时  245.25秒

# 搜"崩坏"，选"1"
# 多线程用时  589.43秒
