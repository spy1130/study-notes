import os
import pickle


class MyDes:
    saved = [ ]
    
    
    def __init__(self,name=None):
        self.name=name
        self.filename=self.name+'.pkl'
    
    def __get__(self,instance,owner):
        if self.name not in MyDes.saved:
            raise AttributeError("%s属性还没有赋值！"% self.name)#当程序出现错误，python会自动引发异常，也可以通过raise显示地引发异常。一旦执行了raise语句，raise后面的语句将不能执行
        
        with open(self.filename,'rb') as f:
            value=pickle.load(f)#pickle.load(文件)，将file中的对象序列化读出。
        
        return value
    def __set__(self,instance,value):
        with open(self.filename,'wb') as f:
            
            pickle.dump(value,f)#将要持久化的数据“对象”，保存到“文件”中
            MyDes.saved.append(self.name)
    
    def __delete__(self,instance):
        os.remove(self.filename)#文件删除
        MyDes.saved.remove(self.name)#list删除
#"r"   以读方式打开，只能读文件 ， 如果文件不存在，会发生异常      
#"w" 以写方式打开，只能写文件， 如果文件不存在，创建该文件；如果文件已存在，先清空，再打开文件   
#"rb"   以二进制读方式打开，只能读文件 ， 如果文件不存在，会发生异常      
#"wb" 以二进制写方式打开，只能写文件， 如果文件不存在，创建该文件；如果文件已存在，先清空，再打开文件
