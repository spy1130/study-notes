from selenium import webdriver

wd = webdriver.Chrome(r'f:\webdrivers\chromedriver.exe')

wd.get('http://f.python3.vip/webauto/sample1.html')

element = wd.find_element_by_css_selector('#searchtext')
element.send_keys('你好')