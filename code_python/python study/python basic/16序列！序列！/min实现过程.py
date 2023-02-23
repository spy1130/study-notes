#猜想一下 min() 这个 BIF 的实现过程
def min(x): 
    least = x[0] 

    for each in x: 
        if each < least: 
            least = each 
    return least
print(min('123456789')) 
