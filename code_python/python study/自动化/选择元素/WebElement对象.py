from selenium import webdriver

wd = webdriver.Chrome(r'f:\webdrivers\chromedriver.exe')

wd.get('http://f.python3.vip/webauto/sample1.html')

element = wd.find_element_by_id('container')

# 限制 选择元素的范围是 id 为 container 元素的内部。
spans = element.find_elements_by_tag_name('span')
for span in spans:
    print(span.text)