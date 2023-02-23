def findstr(desstr,substr):
    count = 0
    length=len(desstr)
    if substr not in desstr:
        print('未在字符串中找到目标文字！')
    else:
        for each1 in range(length-1):
            if desstr[each1] == substr[0]:
                if desstr[each1+1] == substr[1]:
                    count +=1
    
        print('目标文字在字符串中出现了%d次'% count)

desstr = input('请输入目标字符串：')
substr = input('请输入子字符串（两个字符）：')
findstr(desstr,substr)
            


