count = 3
password ='spy'

while count:
    passwd=input('请输入密码：')
    if passwd == password:
        print('密码正确，进入程序.....')
        break
    elif '*'in passwd:
        print('密码中不能含有"*"号！您还有',count-1,'次机会！',end='')
        continue
    else:
        print('密码输入错误！您还有',count-1,'次机会',end='')
    count -=1
