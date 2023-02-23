import time 

class Record:
    def __init__(self，initval = None,name =None):
        self.val = initval
        self.name = name
        self.filename = "record.txt"

    def __get__(self,instance,owner):
        with open(self.filename,'a',encoding='utf-8') as f:#with后面接的对象返回的结果赋值给f。此例当中open函数返回的文件对象赋值给了f.with会自已获取上下文件的异常信息
            f.write("%s 变量于北京时间 %s 被读取,%s= %s\n"%\
                (self.name,time.ctime(),self.name,str(self.val)))#%s,表示格式化一个对象为字符  time ctime() 函数把一个时间戳（按秒计算的浮点数）转化为Tue Dec 11 18:07:14 2008的形式。
                return self.val

    def __set__(self,isinstance,value):
        filename = "%s_record.txt" % self.name
        with open(self.filename,'a',encoding='utf-8') as f:
            f.write('%s 变量于北京时间 %s 被修改, %s = %s\n'%\
                (self.name,time.ctime(),self.name,str(value)))
            self.val = value 