import os

def search_file(start_dir,target):
    os.chdir(start_dir)#改变当前工作目录到start_dir(是一个可变的函数)指定的路径。

    for each_file in os.listdir(os.curdir):
        if each_file == target:
            print(os.getcwd() + os.sep+ each_file)#使用os.sep的话，就不用考虑路径应该写'\'还是'/'了，
                                                  #os.sep根据你所处的平台，自动采用相应的分隔符号
        if os.path.isdir(each_file):
            search_file(each_file,target)#递归调用    
            os.chdir(os.pardir)#递归调用后切记返回上一层目录

start_dir = input('请输入待查找的初始目录：')
target = input('请输入需要查找的文件目标：')
search_file(start_dir,target)          

