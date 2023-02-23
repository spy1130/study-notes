from selenium import webdriver


wd = webdriver.Chrome(r'f:\webdrivers\chromedriver.exe')
wd.implicitly_wait(10)

wd.get('http://f.python3.vip/webauto/sample3.html')

# 点击打开新窗口的链接
link = wd.find_element_by_tag_name("a")
link.click()

# wd.title属性是当前窗口的标题栏 文本
print(wd.title)