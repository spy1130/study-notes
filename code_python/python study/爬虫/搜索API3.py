import requests
url = 'https://www.baidu.com/s'
keyword ={'wd':'spy'}#搜索内容
try:
    r =requests.get(url,params=keyword)
    r.raise_for_status()
    r.encoding = r.apparent_encoding
    print(len(r.text))
    print(r.request.url)
except:
    print('异常')