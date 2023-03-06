import requests,bs4,os,time,tqdm,traceback
#卡住了就随便摁一下键盘，要是还没反应就重连一下网络，然后等待几分钟

try:
    #请求头，建议修改为自己的浏览器头部
    headers = {'user-agent':'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/107.0.0.0 Safari/537.36 Edg/107.0.1418.35'}

    #壁纸存放路径，不存在则创建，可以自行修改
    date = time.strftime('%Y-%m-%d',time.localtime()) #获取今日日期
    path = f"C:\\Downloads\\Video\\{date}\\"
    if not os.path.exists(path):
        os.makedirs(path)

    all_size = 0
    print('正在获取数据，请稍候...（若长时间未响应，请重新启动）', end = '\r')

    #获取今日Top壁纸总页数
    print('正在爬取网页...', end = '\r')
    res = requests.get('https://wallhaven.cc/search?categories=110&purity=100&topRange=1d&sorting=toplist&order=desc&page=2',headers=headers)
    soup = bs4.BeautifulSoup(res.text,'html.parser')
    page = int(soup.find('div',id='thumbs').section.header.h2.text.split('/ ')[1])

    for I in range(page):
        print(f' —————————————————————————————————————————————————————————\n                  正在下载 | 第{I+1}页/共{page}页\n —————————————————————————————————————————————————————————')

        #解析网页源码，查找壁纸
        print('正在爬取网页...', end = '\r')
        res = requests.get(f'https://wallhaven.cc/search?categories=110&purity=100&topRange=1d&sorting=toplist&order=desc&page={I+1}',headers=headers)
        soup = bs4.BeautifulSoup(res.text,'html.parser')
        images = soup.find_all('figure')
        i = 0

        #分别对每张壁纸进行查找链接
        for each in images:
            i += 1
            datas = each.img['data-src'].split('/') #分割关键数据
            if(each.find('span',class_='png') == None): #判断图片格式，并组装下载链接
                url = f'https://w.wallhaven.cc/full/{datas[4]}/wallhaven-{datas[5].split(".")[0]}.jpg'
            else:
                url = f'https://w.wallhaven.cc/full/{datas[4]}/wallhaven-{datas[5].split(".")[0]}.png'

            #下载壁纸（附进度条）
            name = url.split('-')[1]
            print('准备下载图片...', end = '\r')
            image = requests.get(url,stream=True,headers=headers)
            file_size = int(image.headers['Content-length'])
            all_size += file_size #统计文件大小
            pbar = tqdm.tqdm(total=file_size,initial=0,unit='B',unit_scale=True,desc='（%02d/%02d）正在下载 | %s | '%(i,len(images),name))
            with open(path + name,'wb') as f:
                for chunk in image.iter_content(chunk_size=1024):
                    if chunk:
                        f.write(chunk)
                        pbar.update(1024)
            pbar.close()

        #清空终端
        print("\033[H\033[2J", end = '')
        
    #下载完毕
    print(' ————————————————————————————————————————————————————————\n                   下载完成，共计%.2fMB\n'%(all_size/1024/1024))
    input()
except:
    traceback.print_exc()
    input()
