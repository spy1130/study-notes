import random
secret = random.randint(1,10)
print('--------------------spy------------------------')
temp = input('不妨猜猜我想的是哪个数字：')
try:
    guess = int(temp)
except (ValueError,EOFError,KeyboardInterrupt):
    print('输出错误！')
    guess = secret
while guess != secret:
    temp = input('哎呀，猜错了请重新输入吧：')
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
        