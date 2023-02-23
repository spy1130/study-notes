class C:
    def __init__(self, *args):#*args当传入的参数个数未知，且不需要知道参数名称时
        self.values = [x for x in args]#eg:vec = [2, 4, 6] >>>[3*x for x in vec]>>>[6, 12, 18]
        self.count = {}.fromkeys(range(len(self.values)),0)#romkeys() 函数用于创建一个新字典，以序列 seq 中元素做字典的键，value 为字典所有键对应的初始值。dict.fromkeys(seq[, value])
    def __len__(self):
        return len(self.values)
    def __getitem__(self,key):
        self.count[key] += 1
        return self.values[key]
