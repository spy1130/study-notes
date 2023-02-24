import requests
from bs4 import BeautifulSoup
r = requests.get('http://xianxx.tsinghuax.com/airschool/student/index?serverName=xianxx.tsinghuax.com&size=0')
demo = r.text
soup = BeautifulSoup(demo,'html.parser')
print(soup.title)#头标签
print(soup.a)#链接标签
print(soup.a.parent.name)#a的父亲的名字
print(soup.a.parent.parent.name)#a的爷爷的名字
tag = soup.a
print(tag.attrs)#a标签的属性
print(tag.attrs['href'])#索引链接
print(soup.a.string)#a标签的链接文本
#下行遍历
print(soup.a.contents)#获得下一层节点的信息
#迭代类
for i in soup.a.children:#获得下一层节点的信息
    print(i)
for i in soup.a.descendants:#获得后续所有节点的信息
    if i is None:
        print(i)
    else:
        print(i.name)  
#上行遍历
print(soup.a.parent)#获得上一层节点的信息
#迭代类
for i in soup.a.parents:#获得前续所有节点的信息
    if i is None:
        print(i)
    else:
        print(i.name)  
#平行遍历
for i in soup.a.next_siblings:#遍历后续节点
    print(i)
for i in soup.a.previous_siblings:#遍历前续节点
    print(i)    
print(soup.a.pretiffy())#更好的显示
