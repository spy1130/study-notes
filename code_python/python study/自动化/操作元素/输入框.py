from selenium import webdriver

# 创建 WebDriver 实例对象，指明使用chrome浏览器驱动
wd = webdriver.Chrome(r'f:\webdrivers\chromedriver.exe')

# WebDriver 实例对象的get方法 可以让浏览器打开指定网址
wd.get('http://f.python3.vip/webauto/test3.html')
element = wd.find_element_by_id("input1")

element.clear() # 清除输入框已有的字符串
element.send_keys('白月黑羽') # 输入新字符串
