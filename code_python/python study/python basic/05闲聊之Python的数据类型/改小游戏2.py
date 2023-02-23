import random 
times = 3 
secret = random.randint(1,10)
print('--------------------spy------------------------')

guess = 0
print('不妨猜猜我想的是哪个数字：', end=' ')
while (guess != secret) and (times > 0):
    temp = input()
    if temp.isdigit():
        guess = int(temp)
        if guess == secret:
            print('woc,你是我的蛔虫么？')
            print('哼(￢︿̫̿￢☆)，猜中也没有奖励')
        else:
            if guess > secret:
                print('别,大了大了')
            else:
                print('(｡･∀･)ﾉﾞ嘿，小了小了')
            if times > 1:
                print('再试一次吧：', end=' ')
            else:
                print('没机会啦(ˉ▽ˉ；)...')
    else:
        print('抱歉，输入有误，请输入一个整数：', end='')
    times = times - 1
print('游戏结束，不玩了(*^_^*)')

#s.isalnum()  所有字符都是数字或者字母，为真返回 True，否则返回 False。
#s.isalpha()   所有字符都是字母，为真返回 True，否则返回 False。
#s.isdigit()     所有字符都是数字，为真返回 True，否则返回 False。
#s.islower()    所有字符都是小写，为真返回 True，否则返回 False。
#s.isupper()   所有字符都是大写，为真返回 True，否则返回 False。
#s.istitle()      所有单词都是首字母大写，为真返回 True，否则返回 False。
#s.isspace()   所有字符都是空白字符，为真返回 True，否则返回 False。
#例如：
#>>> s = 'I LOVE FISHC'
#>>> s.isupper()
#>>> True
