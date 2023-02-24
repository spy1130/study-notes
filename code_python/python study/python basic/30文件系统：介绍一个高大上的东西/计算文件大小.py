import os

all_files = os.listdir(os.curdir)
file_dict = dict()

for each_file in all_files:
    if os.path.isfile(each_file):#os.path.file判断某一路径是否为文件
        file_size = os.path.getsize(each_file)#os.path.getsize获取文件大小
        file_dict[each_file] = file_size

for each in file_dict.items():
    print('%s[%dBytes]'% (each[0],each[1]))
