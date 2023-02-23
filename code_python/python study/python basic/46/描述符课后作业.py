class MyDes:
    def __init__(self，initval = None,name =None):
        self.val = initval
        self.name = name
    def __get__(self,instance,owner):
        print('the var is geting:',self.name)
        return self.val
    def __set__(self,instance,value):
        print('the value is seting:',self.name)
        self.val = value
    
    def __delete__(self,instance):
        print('the var is deleting:',self.name)
        print("Can't!")