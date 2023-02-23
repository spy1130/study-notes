
def getNum():                                               #获取用户不定长度的输入
    nums=[]
    test=input("请输入要存储的数据(回车退出)：")
    while test != "":
        nums.append(eval(test))
        test=input("请继续输入其他数据(结束回车退出)：")      
    
    return nums

def mean(means_n):                                          #求平均值
    s=0
    mean_result=0
    for i in means_n:
        s=s+i
    mean_result=s/len(means_n)
    return mean_result

def median(numbers):                                       #求中位数
    tem_s=sorted(numbers)    #临时排序
    size=len(numbers)                                     
              
    if size%2==0:
        med=(tem_s[size//2-1]+tem_s[size//2])/2
    else:
        med=(tem_s[size//2])
    print(tem_s)                #打印排序后的列表
    return med

def dev(numbers,mean):                                   #计算方差
    sdev=0
    s1 = 0
    for num in numbers:
        sdev+=num**2
        s1 +=num
    var= float(sdev)/len(numbers)-(float(s1)/len(numbers))**2
    return var

def zhong(ns):                   #计算众数
    dict = {}
    for r in ns:
        dict[ns.count(r)] = r #方法用于统计某个元素在列表中出现的次数    
        list =dict.keys() #以列表返回一个字典所有的键
    return dict[max(list)]
n=getNum()
means=mean(n)
medians=median(n)
var=dev(n,means)
duo = zhong(n)
print("列表:{},平均值:{:.2f},中位数:{:.2f},方差：{}，众数：{}".format(n,means,medians,var,duo))