class Word(str):
#储存单词的类，定义比较单词的几种方法

    def __new__(cls,word):
    #注意我们必须要用到————new————方法，因为str是不可变类型
    #所以我们要在初始化的时候将它初始化
        if ' ' in word:
            print('Value contains spaces. Truncating to first space.')
            word = word[:word.index()]# index() 方法检测字符串中是否包含子字符串 str ，如果指定 beg（开始） 和 end（结束） 范围，则检查是否包含在指定范围内
            return str.__new__(cls,word)
    
    def __gt__(self, other):
        return len(self) > len(other)
    #定义大于号的行为：x > y 调用 x.__gt__(y)
    def __lt__(self, other):
        return len(self) < len(other)
    #定义小于号的行为：x < y 调用 x.__lt__(y)
    def __ge__(self, other):
        return len(self) >= len(other)
    #定义大于等于号的行为：x >= y 调用 x.__ge__(y)
    def __le__(self, other):
        return len(self) <= len(other)
    #定义小于等于号的行为：x <= y 调用 x.__le__(y)