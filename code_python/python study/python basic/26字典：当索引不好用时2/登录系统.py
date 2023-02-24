user_date ={}

def new_user():#新用户登录模块
    prompt ='请输入用户名:'
    while True:
        name = input(prompt)
        if name in user_date:
            prompt = '此用户名已经被使用，请重新输入：'
            continue
        else:
            break

    password = input('请输入密码：')
    user_date[name] = password
    print('注册成功，赶紧试试登录吧(*^_^*)')

def old_user():#旧用户登录模块
    prompt ='请输入用户名:'
    while True:
        name = input(prompt)
        if name not in user_date:
            prompt = '您输入的用户名不存在，请重新输入'
            continue
        else:
            break

    password = input('请输入密码：')
    pwd = user_date.get(name)
    if password ==pwd:
        print('欢迎进入同学录！')
    else:
        print('密码错误')
def menu():
    prompt = '''
丨--- 新建用户：N/n---丨
丨--- 登录账号：E/e---丨
丨--- 退出程序：Q/q---丨
丨--- 请输入指令代码：'''

    while True:
        chosen =False
        while not chosen:
            choice = input(prompt)
            if choice not in 'NeEeQq':
                print('您输入的指令代码错误，请重新输入：')
            else:
                chosen = True

        if  choice == 'q' or choice =='Q':
            break
        if  choice == 'n' or choice =='N':
            new_user()
        if choice == 'e'  or choice =='E':
            old_user()
menu()

