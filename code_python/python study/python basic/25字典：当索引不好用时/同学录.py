print('丨---欢迎进入同学录程序---丨')
print('丨---1：查询同学资料---丨')
print('丨---2：插入新的同学---丨')
print('丨---3:删除已有同学---丨')
print('丨---4：退出同学录程序---丨')

a=dict()#姓名
while 1:
    instr= int(input('\n请输入相关的指令代码：'))
     
    if instr==1:
         name = input('请输入同学姓名：')
         if name in a:
             print('年龄:'+a[name])
         else:
             print('您输入的姓名不在同学录中！')
             continue

    if instr==2:
        name = input('请输入姓名：')
        if name in a:
            print('这同学已经在里头了--》》',end='')
            print('年龄:'+a[name])
            if input('是否修改用户资料（yes/no）：')=='yes':
                a[name]=input('请输入你的年龄：')
        else:
            a[name]=input('请输入你的年龄：')
            continue
                

    if instr ==3:
        name = input('请输入同学姓名：')
        if name in a:
            del(a[name])
        else:
            print('您输入的联系人不存在！')
            continue

    if instr == 4:
        break

print('丨--感谢使用同学录--丨')
                   





         