import math
from itertools import groupby
data =[27,39,33,24,28,19,32,41,33,27,35,12,36,41,27,13,22,23,18,46,32,22]
#茎叶图
#参数data为数据集，n=10表示以个位数字为叶子
#sorted(data)表示对data进行排序
#lambda x为一个匿名函数，x表示sorted(data)中的元素
#math.floor(x/n) 表示取x的百位和十位数作，并向下取整作为茎；lst中为数据的个位数，作为叶子
def stem(data,n):
    for k,g in groupby(sorted(data),key = lambda x: math.floor(x/n)):
        lst = map(str, [d % n for d in list(g)])
        print(k, '|', ' '.join(lst))
#调用函数   
if __name__ == '__main__':
    stem(data,10)