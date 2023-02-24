# coding=gbk
import ddddocr
import requests
import urllib
import re
from bs4 import BeautifulSoup
import os
import time

txtUserName = "username"
TextBox2 = "password"


# 配置
def readset():
    global txtUserName, TextBox2
    if os.path.exists("./set.txt"):
        with open("./set.txt", "r")as file:
            path = file.read().split("\n")
            if (len(path) == 2):
                txtUserName = path[0]
                TextBox2 = path[1]
                return True
    with open("./set.txt", "w")as file:
        file.write("username\npassword")
    return False


def replaceChinese(text):
    chinese = re.findall("([\u4e00-\u9fa5]+)", text)
    return text.replace(chinese[0], urllib.parse.quote(chinese[0], 'gbk'))


# 登录
def Login():
    # global txtUserName, TextBox2
    # check = requests.get("http://api.ealodi.cn/name.txt").text.split("\n")
    # while ((txtUserName in check) == False):
    #     time.sleep(2)
    #     print("该账号不在可使用范围内！")
    url = "http://zfxk.jou.edu.cn/"
    rep = requests.get(url)
    url = rep.url
    url_yzm = url.replace("default2.aspx", "CheckCode.aspx")
    ocr = ddddocr.DdddOcr(show_ad=False)
    res = ocr.classification(requests.get(url_yzm).content)
    html = BeautifulSoup(requests.get(url).text, 'html.parser')
    __VIEWSTATE = html.find("input").get("value")

    data = {
        "__VIEWSTATE": __VIEWSTATE,
        "txtUserName": txtUserName,
        "TextBox2": TextBox2,
        "txtSecretCode": res,
        "RadioButtonList1": "%D1%A7%C9%FA",
        "Button1": "",
        "lbLanguage": "",
        "hidPdrs": "",
        "hidsc": ""
    }
    resp = requests.post(url, data=data)  # 主页
    if (resp.url[-4:] == "aspx"):
        print("登录失败！请检查账号密码并重新登录!")
        return None
    else:
        return resp


# 选择到选课界面
def GetBMapi(resp):
    rep = BeautifulSoup(resp.text, 'html.parser')
    tts = [(ise.get_text(), ise["href"]) for ise in rep.find("ul", {"class", "sub"}).find_all("a")]
    for i in range(len(tts)):
        print(f"{i}.", tts[i][0])
    ch = input("请选择:")
    return tts[int(ch)]


# 获取选板块需要的viewstate
def Get__Viewstate(tt, resp):
    ht = resp.url[0:int(resp.url.rfind("/")) + 1]
    url = replaceChinese(ht + tt[1])  # 最后要post的url
    header = {
        "Referer": resp.url
    }
    hj = requests.get(url, headers=header).text
    # 获取__VIEWSTATE
    text = BeautifulSoup(hj, 'html.parser')
    choosions = text.find_all("option")
    for i in range(len(choosions)):
        print(f"{i}.", choosions[i]["value"])
    bk = input("请选择需要的板块：")

    __VIEWSTATE = text.find_all("input")[2]["value"]
    return (__VIEWSTATE, url, choosions[int(bk)]["value"])


def postData(data, headers, url):
    last_text = requests.post(url, data=data, headers=headers).text
    print("发送请求完成！")
    print(re.findall("<script language='javascript'>alert\(\'([\u4e00-\u9fa5！？]+)\'\);", last_text)[0])


# 获取可选课
def GetClassion(__VIEWSTATE, url, bk):
    payload = f"__EVENTTARGET=kj&__EVENTARGUMENT=&__VIEWSTATE={urllib.parse.quote(__VIEWSTATE)}&kj={bk}"
    header2 = {
        "Content-Type": "application/x-www-form-urlencoded",
        "Referer": url,
        "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/105.0.0.0 Safari/537.36 Edg/105.0.1343.27"
    }
    res = requests.post(url, headers=header2, data=payload).text
    __VIEWSTATE2 = BeautifulSoup(res, 'html.parser').find_all("input")[2]["value"]
    names = re.findall("left=200,top=50\'\)\">([\u4e00-\u9fa5]+)</a>", res)
    teachers = re.findall("left=120,top=60\'\)\">([\u4e00-\u9fa5]+)</a>", res)
    ids = re.findall("type=\"checkbox\" name=\"(kcmcGrid:_ctl[0-9]+:xk)\" />", res)
    for i in range(len(names)):
        print(f"{i}.", names[i], " ", teachers[i])
    ch = input("选择要抢的课:")
    data = f"__EVENTTARGET=&__EVENTARGUMENT=&__VIEWSTATE={urllib.parse.quote(__VIEWSTATE2)}&kj={bk}&{urllib.parse.quote(ids[int(ch)])}=on&Button1=+%CC%E1+%BD%BB+"
    while True:
        postData(data, header2, url)


if __name__ == "__main__":
    # %B0%E5%BF%E9%A3%A810%A3%A9
    # print(urllib.parse.quote("板块（10）".encode("gbk")))
    readset()
    rep = Login()
    while rep == None:
        rep = Login()
    res = Get__Viewstate(GetBMapi(rep), rep)
    GetClassion(res[0], res[1], urllib.parse.unquote(res[2].encode("gbk").decode("latin-1")))
