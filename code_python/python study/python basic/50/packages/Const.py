#该模块用于让 python 支持常量操作
class Consts:
    def __setattr__(self, name, value):#当实例对象属性被修改时
        if name in self.__dict__:#检查该属性是否存在
            print('常量名无法改变！')
            raise TypeError
        if not name.isupper():#检测字符串中所有的字母是否都为大写。
            print('常量名必须由大写字母组成！')
            raise  TypeError
        self.__dict__[name]= value
