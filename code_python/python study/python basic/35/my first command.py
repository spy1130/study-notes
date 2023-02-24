import easygui as g

s =g.passwordbox('请输入密码：')#第一次
times = 2
while times>0 :
    if s == None:
        break
    elif s == '123456':
        g.msgbox('登录成功',ok_button='欢迎光临！')
        break
    elif s != '123456' and '*' not in s:
        g.msgbox('输入密码错误!')
        s = g.passwordbox('请重新输入密码：')
        times -= 1
        continue
    elif '*' in s:
        s = g.passwordbox('密码中没有*请重新输入密码：')
        continue
if times ==0:
    g.msgbox('对不起三次次数已用完！')


    