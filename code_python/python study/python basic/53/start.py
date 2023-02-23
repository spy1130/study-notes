import urllib.request as re
res = re.urlopen('http://jxjy.sjzz.org.cn/') 
re1 = res.read()
re1 = re1.decode('UTF-8')
print(re1)