#视频中我们说 sum() 这个 BIF 有个缺陷， 就是如果参数里有字符串类型的话就会报错， 请写出一个新的实现过程，自动 “无视 ”参数里的字符串并返回正确的计算结果
def sum(x): 
    result = 0 

    for each in x: 
        if (type(each) == int) or (type(each) == float): 
            result += each 
        else: 
            continue 
    return result 
print(sum([1, 2.1, 2.3, 'a', '1', True]))
