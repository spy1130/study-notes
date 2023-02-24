def file_compare(file1,file2):
    f1 =open(file1)
    f2 =open(file2) 
    count = 0
    differ = []

    for line1 in f1:
        line2 = f2.readline()
        count +=1
        if line1 != line2:
            differ.append(count)
    
    return differ

    f1.close()
    f2.close()

file1 =input('请输入第一个文件：')
file2 =input('请输入第二个文件：')

differ =file_compare(file1,file2)

if len(differ)==0:
    print('两个文件完全一样！')
else:
    print('两个文件共有%d处不同'%len(differ))
    for each in differ:
        print('第%d行不同。'%each)
