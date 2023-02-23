#程序开始
import random # 导入random
times = 3 # 定义一个次数变量
secret = random.randint(1,10)# 定义一个随机变量（random.randint随机变量范围定义。。。额代码吧)
print('--------------------spy------------------------')# 程序第一行打印
# 这里先给guess赋值（赋一个绝对不等于secret的值）
guess = 0
# print()默认是打印完字符串会自动添加一个换行符，end=" "参数告诉print()用空格代替换行
print('不妨猜猜我想的是哪个数字：', end=' ')# 第二行打印
while (guess != secret) and (times > 0):# 循环块
    temp = input()# 给temp变量定义为用户输入的
    guess = int(temp)# 将temp的值通过BIF（int)加工为guess可被定义的数
    times = times - 1# 用户每输入一次，可用机会就-1
    if guess == secret:#条件模块组（第一大块，如果 guess的值等于secret的值）
        print('woc,你是我的蛔虫么？')
        print('哼(￢︿̫̿￢☆)，猜中也没有奖励')#打印内容
    else:#第一大块，否则
        if guess > secret:#第二分支，如果大于
            print('别,大了大了')
        else:#第二分支，否则
            print('(｡･∀･)ﾉﾞ嘿，小了小了')
        if times > 0:#第二分支第二小支，如果times的值大于0（尝试次数大于0）
            print('再试一次吧：', end=' ')
        else:#第二分支第二小支，否则
            print('没机会啦(ˉ▽ˉ；)...')
print('游戏结束，不玩了(*^_^*)')#最后打印
#程序结束
