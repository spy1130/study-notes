from selenium import webdriver
driver = webdriver.Chrome(r'f:\webdriver\chromedriver.exe')
driver.implicitly_wait(5)
driver.get('http://f.python3.vip/webauto/test4.html')


# --- alert ---
driver.find_element_by_id('b1').click()

# 打印 弹出框 提示信息
print(driver.switch_to.alert.text) 

# 点击 OK 按钮
driver.switch_to.alert.accept()