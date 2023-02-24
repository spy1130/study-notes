from selenium import webdriver

# 创建 WebDriver 对象，指明使用chrome浏览器驱动
wd = webdriver.Chrome(r'f:\webdrivers\chromedriver.exe')

# 调用WebDriver 对象的get方法 可以让浏览器打开指定网址
wd.get('https://www.baidu.com')

# 根据id选择元素，返回的就是该元素对应的WebElement对象
element = wd.find_element_by_id('kw')

# 通过该 WebElement对象，就可以对页面元素进行操作了
# 比如输入字符串到 这个 输入框里
element.send_keys('白月黑羽\n')