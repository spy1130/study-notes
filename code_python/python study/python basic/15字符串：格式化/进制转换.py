q = True 
while q: 
    num = input(' 请输入一个整数 (输入 Q结束程序 ) ：') 
    if num != 'Q': 
        num = int(num) 
        print(' 十进制 -> 十六进制 : %d -> 0x%x' % (num, num)) 
        print(' 十进制 -> 八进制 : %d -> 0o%o' % (num, num)) 
        print(' 十进制 -> 二进制 : %d -> ' % num, bin(num)) 
    else: 
        q = False 



