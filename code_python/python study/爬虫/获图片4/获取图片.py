import requests
import os
url ='https://img.moegirl.org/common/4/44/%E4%BA%8C%E5%90%91%E7%AE%94.jpg'
root = 'F://python学习//爬虫//获图片//'
path = root+ url.split('/')[-1]#=%E4%BA%8C%E5%90%91%E7%AE%94.jpg
try:
    if not os.path.exists(root):#如果没文件夹
        os.mkdir(root)#创建文件夹
    if not os.path.exists(path):#如果没有图片文件
        r = requests.get(url)
        with open(path,'wb') as f:
            f.write(r.content)#写入二进制图片文件
            f.close()
            print('文件保存成功')
    else:
        print('文件已存在')
except:
    print('爬取失败')
