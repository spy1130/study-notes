import easygui as g

msg='请填写以下联系方式'
title ='账号中心'
fieldnmaes= ['*用户名','*真实姓名','固定电话','*手机号','QQ','*E-mail']
fieldvalues =[]
fieldvalues = g.multenterbox(msg,title,fieldnmaes)

while 1:
    if fieldvalues == None:
        break
    errmsg = ''
    for i in range(len(fieldnmaes)):
        option = fieldnmaes[i].strip()
        if fieldvalues[i].strip() == '' and option[0] == '*':
            errmsg +=('[%s]为必填项。\n\n' % fieldnmaes[i])
        if errmsg == '':
            break
        fieldvalues = g.multenterbox(errmsg,title,fieldnmaes,fieldvalues)

print('用户资料如下：%s' % str(fieldvalues))