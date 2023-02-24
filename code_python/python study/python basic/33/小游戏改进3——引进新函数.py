def int_input(prompt=''):
    while True:
        try:
            int(input(prompt))
            break
        except ValueError:
            print('出错，您输入的不是整数！')

import random

secret = random.randint(1,10)
print('--------------------spy------------------------')
temp = int_input('不妨猜猜我想的是哪个数字：')
guess = int(temp)

while guess != secret:
    temp = int_input('哎呀，猜错了请重新输入吧：')
    guess = int(temp)
    if guess == secret:
        print('woc,你是我的蛔虫么？')
        print('哼(￢︿̫̿￢☆)，猜中也没有奖励')
    else:
        if guess > secret:
            print('别,大了大了')
        else:
            print('(｡･∀･)ﾉﾞ嘿，小了小了')

print('游戏结束，不玩了(*^_^*)')


        