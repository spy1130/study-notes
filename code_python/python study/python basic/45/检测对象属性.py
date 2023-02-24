class C:
    def __init__(self):
        super().__setattr__('c',0)
    def __setattr__(self,name,value):
        super().__setattr__('c',self.c +1)
        super().__setattr__(name,value)
    def __delattr__(self, name):
        super().__setattr__("c",self.c - 1)
        super().__delattr__(name)