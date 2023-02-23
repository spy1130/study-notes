import requests
url = 'http://www.ip138.com/iplookup.asp?ip='
try:
    r = requests.get(url+'172.29.46.115')
    r.raise_for_status()
    r.encoding = r.apparent_encoding
    print(r.text[1:1000])
except:
    print('爬取失败')