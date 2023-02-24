class Countlist(list) :#继承list
    def __init__ (self,*args) :
        super().__init__(args)#当需要继承父类构造函数中的内容，且子类需要在父类的基础上补充时，使用super().__init__()方法。
        self.count  = []
        for i in args :
            self.count.append(0)

    def __len__ (self) :
        return len(self.count)
    
    def __getitem__ (self,key) :
        self.count[key] += 1 
        return super().__getitem__(key)
    
    def __setitem__(self,key,value) :
        self.count[key] += 1
        super().__setitem__(key,value)
    
    def __delitem__(self,key) :
        del self.count[key]
        super().__delitem__(key)
    
    def counter (self,key) :#当需要对 list 中的大量数据进行计数时，可以直接使用 Counter ，而不用新建字典来计数
        return self.count[key]#此类返回一个以元素为 key 、元素个数为 value 的 Counter 对象集合
    
    def append (self,value) :
        self.count.append(0) 
        super().append(value)
    
    def pop (self,key = -1) :#pop() 函数用于移除列表中的一个元素（默认最后一个元素），并且返回该元素的值。
        del self.count[key]
        return super().pop(key)
    
    def remove (self,value) :#remove() 函数用于移除列表中某个值的第一个匹配项。
        key = super().index(value)#index() 方法检测字符串中是否包含子字符串 str ，如果指定 beg（开始） 和 end（结束） 范围，则检查是否包含在指定范围
        del self.count[key] #如果包含子字符串返回开始的索引值，否则抛出异常
        super().remove(value)

    def insert (self,key,value) :#insert() 函数用于将指定对象插入列表的指定位置。
        self.count.insert(key,0) 
        super().insert(key,value)

    def clear (self) :#clear() 函数用于清空列表，类似于 del a[:]
        self.count.clear()
        super().clear()
 
    def reverse (self) :#函数用于反向列表中元素
        self.count.reverse()
        super().reverse()