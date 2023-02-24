def file_view(file_name,line_num):
    if line_num.strip() == ':':
        begin = '1'
        end = '-1'


    (begin,end) = line_num.split(':')

    if begin == '':
        begin ='1'
    if end == '':
        end = '-1'

    if begin == '1' and end == '-1':
        prompt = '的全文'
    elif begin == '1':
        prompt = '从开始到%s' % end
    elif end == '-1':
        prompt = '从%s到结束' % begin    
    else:
        prompt = '从第%s行到第%s行'%(begin,end)

    print('\n文件%s%s的内容如下：\n' % (file_name,prompt))

    begin = int(begin) -1
    end = int(end)
    lines =end -begin

    f =open(file_name)

    for i in range(begin):#用于消耗掉begin之前的内容
        f.readline()

    if lines < 0:
        print(f.read())
    else:
        for j in range(lines):
            print(f.readline(),end='')

    f.close()

file_name =input(r'请输入要打开的文件：')
line_name =input('请输入需要显示的行数【格式： 13：21  ：21  ：13】：')
file_view(file_name,line_name)

