from selenium import webdriver

wd = webdriver.Chrome(r'f:\webdrivers\chromedriver.exe')

wd.get('http://f.python3.vip/webauto/sample2.html')


# 先根据name属性值 'innerFrame'，切换到iframe中
wd.switch_to.frame('innerFrame')

# 根据 class name 选择元素，返回的是 一个列表
elements = wd.find_elements_by_class_name('plant')

for element in elements:
    print(element.text)