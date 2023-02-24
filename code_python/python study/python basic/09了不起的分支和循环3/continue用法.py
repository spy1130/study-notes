for i in range(10):
    if i%2 !=0:
        print(i)
        continue
    i +=2
    print(i)
#i从range里抽出1，if条件成立，打印1，回到for而不执行i+=2，然后i抽取2，
#if条件不成立，执行continue继续执行i+=2并打印4，当抽取偶数时i+=2并打印，
#当抽取奇数时直接打印i（注意：这里for条件的i是从range里取 所以不受下面
#自增2的影响，所以for条件的i的取值依次是0,1,2,3,......,9
