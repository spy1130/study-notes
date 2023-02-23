try:
    f =open('my_file.txt')#不存在
    print(f.read())
except OSError as reason:
    print('出错啦：' + str(reason))
finally:
    if 'f' in locals():# 如果文件对象变量存在当前局部变量符号表的话，说明打开成功
        f.close()