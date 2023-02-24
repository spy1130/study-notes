def pali(n,start,end):
    if start> end:
        return 1
    else:
        return pali(n,start+1,end-1) if n[start] == n[end] else 0

string = input('请输入一串字符串：')
length = len(string)-1

if pali(string,0,length):
    print('\"%s\"是回文联！'% string)
else:
    print('\"%s\"不是回文字符串！'% string)
