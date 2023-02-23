import pickle

def save_file(boy,girl,count):
    file_name_boy = 'boy_' + str(count) +'.txt'
    file_name_girl = 'girl_'+ str(count) +'.txt'

    boy_file = open(file_name_boy,'wb')
    girl_file = open(file_name_girl,'wb')

    pickle.dump(boy,boy_file)
    pickle.dump(girl,girl_file)  

    boy_file.close()
    girl_file.close()

def spilt_file(filr_name):
    boy =[]
    girl =[]
    count = 1

    f=open(filr_name)

    for each_line in f:
        if each_line[:6] != '======':
            (role,line_spoken)= each_line.split(':',1)#以冒号为分割点分割一次并分别输入role和line_spokenl两个参数之中
            if role == '小甲鱼':
                boy.append(line_spoken)
            if role == '小客服':
                girl.append(line_spoken)
        else:
            save_file(boy,girl,count)

            boy =[]
            girl =[]
            count += 1
            
    save_file(boy,girl,count)

    f.close()

spilt_file('record.txt')