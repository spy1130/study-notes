def file_view(file_name,line_num):
    print('\n文件%s的前%s的内容如下：'%(file_name,line_num))
    f = open(file_name)
    if line_num !=int:
        print('您输入的不是数字！')
    for i in range(int(line_num)):
        print(f.readline(),end= '')

    f.close()

file_name=input('请输入文件名：')
line_num =input('请输入想要查阅到的行数：')
file_view(file_name,line_num)    

