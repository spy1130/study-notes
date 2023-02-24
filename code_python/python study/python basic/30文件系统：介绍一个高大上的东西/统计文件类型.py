import os#导入os模块

def my_file():
    my_dict = {}#创建空字典
    all_files = os.listdir(os.curdir)#os.curdir表示当前目录;os.listdir表示将当前目录的文件名列举成一个列表
    
    for each_file in all_files:
        if os.path.isdir(each_file):#os.path.isdir判断指定路径是否存在且是一个目录  #判断是否存在文件夹
            my_dict.setdefault("文件夹",0)#dict.setdefault如果字典中包含有给定键，则返回该键对应的值，否则返回为该键设置的值。
            my_dict["文件夹"] +=1         #如果键不存在于字典中，将会添加键并将值设为默认值。这里创建了一个{文件夹：0}的字典     
        #索引文件夹的对应值并+1
        else:#判断文件类型
            ext = os.path.splitext(each_file)[1]#分离文件名与扩展名，返回(f_name, f_extension)元组,索引后者
            my_dict.setdefault(ext,0)
            my_dict[ext]+=1#同上
    
    for  k in my_dict.keys():#dict.keys()返回一个字典所有的键。
        print('该文件夹下共有类型为【%s】的文件 %d 个' % (k,my_dict[k]))#%s打印字符串 %d打印整数
my_file()
