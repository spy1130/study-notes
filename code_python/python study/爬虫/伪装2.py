import requests
url = 'https://www.amazon.cn/dp/B07PRDGYTW/ref=lp_1484580071_1_2?s=pc&ie=UTF8&qid=1579942664&sr=1-2'
try:
    kv ={'user-agent':'Mozilla/5.0'}
    r = requests.get(url,headers=kv)
    r.raise_for_status()
    r.encoding = r.apparent_encoding
    print(r.text)
except:
    print('爬取失败')
