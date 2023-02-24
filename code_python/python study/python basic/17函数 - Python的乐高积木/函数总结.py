def Myfirstfunction(name):
    'name是形参，只是一个形式，表示占据一个位置(函数文档)'
    return (name+'欢迎登录')
print(Myfirstfunction('spy'))#'spy'是实参，Ta是一个具体的参数
print(Myfirstfunction.__doc__)
help(Myfirstfunction)


def add(num1,num2):
    print (num1+num2)#返回num1+num2'()'可省略
add(232,535)


def SaySome(name,words):
    return (name+'---'+words)
print(SaySome('spy[滑稽]','让编程改变世界'))
print(SaySome(words='spy[滑稽]',name='让编程改变世界'))#关键字参数
def SaySome(name='spy[滑稽]',words='让编程改变世界'):
    print(name+'---'+words)
SaySome('让世界爱上编程！','lizr')


def test(*params,exp=8):
    '收集参数'
    print('参数长度是:',len(params),exp)
    print('第二个参数是：',params[1])
test(1,'spy',3321,312312,42354346,5435432,exp=8)

def hello():
    print('Hello spy')
temp=hello()
print(temp)
print(type(temp))

def back():
    return[1,'spy',3.14]
print(back())
def back():
    return 1,'spy',3.14
print(back())

#我的地盘我做主：
#1.局部变量（final_price）:只能在函数里有效
#2.全局变量（old_price,rate,new_price）:在全部代码有效
def discounts(price,rate):
    final_price = price * rate
    print('这里试图打印全局变量rate的值',rate)
    old_price =50 #这里python创建了一个名叫old_price的局部变量
    print('修改后old_price的值是（局部）',old_price)
    return final_price

old_price = float(input('请输入原价：'))
rate = float(input('请输入折扣率：'))
new_price = discounts(old_price,rate)
print('打折后的价格是：',new_price)
print('修改后old_price的值是（全局）',old_price)
#print('这里试图打印局部变量final_price的值：',end=' ')
#print(final_price)

#屏蔽（Shadowing）
count = 5#全局变量
def myfun():
    count=10#局部变量
    print(10)
myfun()#输出局部变量
print(count)#输出全局变量

#global 关键字
def Myfun():
    global count#让count做好心理准备，变成全局变量
    count = 10
    print(count)
Myfun()
print(count)

#内嵌函数/内部函数：允许在函数内部创建另一个函数
def fun1():
    print('fun1()正在被调用...')
    def fun2():
        print('fun2()正在被调用...')
    fun2()
fun1()
#fun2()不能在fun1()外调用

#闭包（）：函数式编程的一个重要的语法结构
def funx(x):
    '''在内部函数（funy()）对外作用域（funx()）的变量（x）进行引用,
    则这个内部函数[funy()]就是一个闭包'''
    def funy(y):
        return x*y
    return funy
i = funx(8)
print(type(i))
print(i(5))
print(funx(8)(5))
print(funx.__doc__)
#和内部函数一样funy()不能在funx外部调用

#Python认为在内部函数的x是局部变量的时候外部函数就被遮蔽起来了，
#执行x *=x时，在右边根本找不到局部变量x的值
#def fun1():
#   x = 5
#   def fun2():
#       x *=x
#       return x
#    return fun2
#改进：python3之前，列表容器类型
def Fun1():
    x = [5]
    def Fun2():
        x[0] *= x[0]
        return x[0]
    return Fun2()
print(Fun1())
#python3后 nonlocal 强制申明不是一个局部变量
def funX():
    x = 5
    def funY():
        nonlocal x
        x *= x
        return x
    return funY
print(funX()())

#匿名函数， 即lambda表达式，语法 -> lambda 参数 : 参数的表达式 （参数可以不唯一), 例如：
def ds(x):
        return 2 * x + 1
ds(5)
#相当于
lambda x : 2 * x + 1
g = lambda x : 2 * x + 1
print(g(5))
#两个参数
def fun_A(x, y):
        return x * y
fun_A(3,4)
#或者
g = lambda x, y : x * y#g是一个被临时赋值的对象，只是一个载体作用
print(g(3,4))

#filter()函数 ： 筛选器， 语法 -> filter(function or None, iterable(可迭代对象)) 
# 会将可迭代对象中的元素送入函数体（可以没有函数体， 则直接对可迭代对象进行筛选）， 
#若为True则留下， 若为False则删掉，筛选出结果为True的元素， 返回一个对象 例如：
temp = filter(None,[1,0,False,True])
print(list(temp))#把它变为列表
#筛选奇数
def odd(x):
    return x % 2
temp=range(10)
show = filter(odd,temp)
list(show)
#一行实现
print(list(filter(lambda x : x%2,range(10))))
#map()函数： 映射， 语法 -> map(function, *iterables)， 
# 其中map() 可以有多个可迭代对象（取决于函数体参数的个数）， 类似filter()，  
# 将可迭代对象中的元素送入函数体， 返回结果， map（）返回值为对象， 例如
print(list(map(lambda x :x*2, range(10))))

#递归:表现为函数调用本身
import sys
sys.setrecursionlimit(100)#将递归限制设置为100层
#递归需满足两个条件：
#设置了正确的返回条件
#函数调用自身
#写一个求阶层的函数
#普通函数
def recursion(n):
    result= n
    for i in range(1,n):
        result *= i
    return result
number = 5
result=recursion(number)
print('%d的阶乘是%d'%(number,result))
#递归版本
def factorial(n):
    if n == 1:
        return 1
    else:
        return n*factorial(n-1)
number1 = 5
result1=factorial(number1)
print('%d的阶乘是%d'%(number1,result1))

#这帮小兔崽子（斐波那契数列）
#迭代实现
def f(n):
    n1 = 1
    n2 = 1
    n3 = 1
    
    if n<1:
        print('输入有误')
        return -1
    
    while (n-2)>0:
        n3 = n2+n1
        n1 = n2#为后面循环做准备
        n2 = n3
        n -= 1#看列表跟头变尾，尾变头一样的虫子一样

    return n3

result = f(100)
if result !=-1:
    print('总共有%d对小兔崽子诞生'%result)
#递归实现
def fab(n):
    if n<1:
        print('输入有误')
        return -1
    
    if n == 1 or n == 2:
        return 1
    else:
        return fab(n-1)+fab(n-2)

result = fab(20)
if result !=1:
    print('总共有%d对小兔崽子诞生'%result)
#分治思想
#汉诺塔
def haooi(n,x,y,z):#（圆盘数量，起始位置，闲置位置，终点位置）
    if n == 1:
        print(x,'---->',z)#如果只有一层，直接从x移动到z
    else:
        haooi(n-1,x,z,y)#将前一个n-1个盘子从x移动到y
        print(x,'---->',z)#将最底下的最后一个盘子从x移动到z上
        haooi(n-1,y,x,z)#将y上的n-1个盘子移动到z上
n = int(input('请输入汉诺塔的层数：'))
haooi(n,'X','Y','Z')
#递归当然只能以递归的思路理解，把它展开纯属自讨苦吃。
#递归思路，说白了是如下三步：
#1、对于问题N，如果N-1已经解决了，那么N是否很容易解决。
#甲：想上天？你先给我找个天一样高的梯子！
#乙：想要天一样高的梯子？你先给我弄棵天一样高的树！
#甲：想要天一样高的树？你先给我弄把能顶到天的锯子！
#……
#举例来说，如果要把一个N层汉诺塔从A搬到C，那么：
#如果前N-1层可以找别人搞定，咱只管搬第N层，会不会变得非常容易？

#你看，这一下就简单了：这时当它只有两层就好了，先把前N-1层看作一个整体，把它搬到B
# ；然后把最下面的第N层搬到C；然后再把前N-1层从B搬到C。

#类似的，假如接到“搬前N-1层”这个任务的是我们，怎么搬呢？

#简单，像前东家一样，把前N-2层外包出去，我们只搬第N-1层——其实和前面讨论过的“外包N-1层，
# 只搬第N层”完全一样嘛。

#依此类推，一层层“外包”下去——我不管你们有多伤脑筋，反正只要你们把我外包给你的活干了，
# 我就能干了我的活！

#注意，这里千万别管“接到外包工作的家伙有多伤脑筋”——丢给他就让他头疼去，我们就别再捡回来痛苦
# 自己了。

#这一步就是“递推”。
#注意这里的搬法：搬第N层，就需要把前N-1层搬两次，另外再把第N层搬一次；搬第N-1层，
#又需要把前N-2层搬两次，然后再把N-1层搬一次，依此类推。

#很容易知道，一共需要搬2^N-1次。
#2、一步步递推下去，终究会有个“包工头”，接到“搬第一层”的任务。
#第一层怎么搬？
#太简单了，让搬哪搬哪。
#换句话说，到此，“递推”就到了极限，简单粗暴直接做就可以了。

#3、既然第一层搬了，那么第二层当然就可以搬了；第二层搬了，第三层又可以搬了……依次类推，
#直到第N层。于是问题搞定。

#这一步就是“回归”。
#如上三步加起来，就是“递归”。

#推而广之，任何问题，不管规模为N时有多复杂，只要把N-1那块“外包”给别人做之后，
#我们在这个基础上可以轻易完成N，那么它很可能就适合用“递归”解决。

#那么，怎么最终确定它能不能用“递归”做呢？
#看当N取1或2之类最简情况时，问题是否可以解决——然后写程序解决它。

#容易看出，“递归”其实和“数学归纳法”的思路非常像：证明N=1时成立；证明若N=n-1成立，
#则N=n时也成立；如上两步得证，则命题在n>1时一定成立（n为自然数）。

#你看，我们没必要从1开始逐一验证每个自然数，只要证明了“基础条件”、再证明了“递推条件”，
#大自然的规律会帮我们搞定一切。

#换句话说，只要我们：
#1、写程序告诉电脑“如何分解一个问题”
#2、写程序告诉电脑“当该问题分解到最简时如何处理”
#那么，“具体如何递推、如何回归”这个简单问题就不要再操心了，电脑自己能搞定。

#——写出问题分解方法、写出分解到最简后如何解决，这是我们的任务；把问题搞定，是电脑的任务。
# 这就是递归的魅力。

#正是由于这种“我提供思路你搞定细节”的特点，“一切皆递归”的函数系语言才被称为“声明式编程”
# （而不是必须一步一步指导电脑如何做的“命令式编程”）。

#这么简单轻松的事，非要自己吭哧吭哧一步步做出来——O(2^N)规模啊——难怪你们要陷入困境。     







        

