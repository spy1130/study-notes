def count(*param):
    length = len(param)
    for i in range(length):
        letters = 0
        space = 0
        digit = 0
        others = 0
        for each in param[i]:
            if each.isalpha():
                letters +=1
            elif each.isdigit():
                digit +=1
            elif each == ' ':
                space +=1
            else:
                others+=1
        print('第%d个字符串有：%d个文字，%d个数字，%d个空格和%d个其他'%(i+1,letters,digit,space,others))
count('l am spy','my name is spy','life is short , l need python')
