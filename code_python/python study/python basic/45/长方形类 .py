 class Spy:
    def __init__(self,long=0,short=0):
        self.long = long
        self.short = short
    def __setattr__(self, name, value):#定义一个属性被被设置时的行为
        if name == 'square':
            self.long = value
            self.short = value
        else:
            super().__setattr__(name,value)#调用基类
    
    def Getarea(self):
        return self.long * self.short
        
          
     