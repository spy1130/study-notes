#爱因斯坦曾出过这样一道有趣的数学题：有一个长阶梯，
#若每步上 2 阶，最后剩 1 阶； 若每步上 3 阶，最后剩 2 阶；
#若每步上 5 阶，最后剩 4 阶；若每步上 6 阶，最后剩 5 阶；
#只有每步上 7 阶，最后刚好一阶也不剩。
#（小甲鱼温馨提示：步子太大真的容易扯着蛋 ~~~）
#题目：请编程求解该阶梯至少有多少阶？

x =7#阶梯数
i =1#次数
flag =0#判断变量

while i<=100:
    if(x%2 == 1)and (x%3 ==2)and(x%5 ==4)and(x%6==5):
        flag=1
    else:
            x=7*(i+1) # 根据题意， x 一定是 7 的整数倍，所以每次乘以 7
    i+=1
if flag == 1:
    print('阶梯数是',x)
else:
    print("在程序限定的范围内找不到答案！")
            
