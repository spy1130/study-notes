str1 ='i am spy'
list1 = []
for each in str1:
    if each not in list1:
        if each == '\n':
            print('\\n',str1.count(each))
        else:
            print(each,str1.count(each))
        list1.append(each)