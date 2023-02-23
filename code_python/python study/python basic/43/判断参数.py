class C:
    def __init__(self,*args):
        if not args:
            print('no face!')
        else:
            print('input%d个参数,分别是：'%len(args),end='')
            for i in args:
                print(i,end=" ")
    