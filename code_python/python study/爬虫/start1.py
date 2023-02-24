import requests 
import time
def Gethtml(url):
    try:
        re =requests.get(url,timeout=30)
        re.raise_for_status()#如果状态不是200，引发HTTPError异常
        re.encoding = re.apparent_encoding
        print(re.text)
    except:
        print('发生异常！')

if __name__ =='__main__':
    url = 'https://www.baidu.com/'
    start = time.perf_counter()
    for i in range(100):
        rs = Gethtml(url)
    t = (time.perf_counter()-start)
    print('使用时间：',t,'s')

