from selenium import webdriver

wd = webdriver.Chrome((r'f:\webdrivers\chromedriver.exe')

# 设置最大等待时长为 10秒
wd.implicitly_wait(10)

wd.get('https://www.baidu.com')

element = wd.find_element_by_id('kw')

element.send_keys('黑羽魔巫宗\n')
# id 为 1 的元素 就是第一个搜索结果
element = wd.find_element_by_id('1')

print (element.text)