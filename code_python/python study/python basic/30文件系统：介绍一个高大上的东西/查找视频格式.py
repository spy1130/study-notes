import os 

def search_file(start_dir,target):
    os.chdir(start_dir)

    for each_file in os.listdir(os.curdir):
        ext = os.path.splitext(each_file)[1]#分离文件名与扩展名
        if ext in target:
            vedio_list.append(os.getcwd()+os.sep+each_file+os.linesep)
            #os.linesep字符串给出当前平台使用的行终止符。例如，Windows使用'\r\n'，Linux使用'\n'而Mac使用'\r'。
        if os.path.isdir(each_file):
            search_file(each_file,target)#递归调用
            os.chdir(os.pardir)
start_dir = input('请输入待查找的初始目录：')
program_dir = os.getcwd()

target =['.mp4','.avi','.rmvb','.flv']
vedio_list = []
search_file(start_dir,target)

f = open(program_dir+ os.sep + 'vediolist.txt','w')
f.writelines(vedio_list)
f.close()

