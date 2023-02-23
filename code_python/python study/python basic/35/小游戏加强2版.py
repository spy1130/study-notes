import easygui as g
import random

secret = random.randint(1,10)
temp = g.enterbox('不妨猜猜我想的是哪个数字：')
try:
    guess = int(temp)
except (ValueError,EOFError,KeyboardInterrupt):
    g.msgbox('输出错误！')
    guess = secret
while guess != secret:
    temp = g.enterbox('哎呀，猜错了请重新输入吧：')
    guess = int(temp)
    if guess == secret:
        g.msgbox('woc,你是我的蛔虫么？')
        g.msgbox('哼(￢︿̫̿￢☆)，猜中也没有奖励')
    else:
        if guess > secret:
            g.msgbox('别,大了大了')
        else:
            g.msgbox('(｡･∀･)ﾉﾞ嘿，小了小了')
g.msgbox('游戏结束，不玩了(*^_^*)')
        
