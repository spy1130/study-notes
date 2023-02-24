str1='i am spy'
print(str1)
str1=str1.capitalize()#把字符串的第一个字符改为大写
print(str1)
print('-------------------------------------------------')
str2='DDdwaudaod'
print(str2)
str2=str2.casefold()#把整个字符串的所有字符改为小写
print(str2)
print('--------------------------------------')
str2=str2.center(40)#center(width)将字符串居中，并使用空格填充至长度 width 的新字符串
print(str2)
print('----------------------------------------------------------')
number=str2.count('d')#count(sub[, start[, end]])返回 sub 在字符串里边出现的次数，start 和 end 参数表示范围，可选。
print(number)
print('----------------------------------')
bool1=str(str2.endswith('spy'))#endswith(sub[, start[, end]])检查字符串是否以 sub 子字符串结束，如果是返回 True，否则返回 False。start 和 end 参数表示范围，可选。
print(bool1)
print('-----------------------------------------------------------------------')
str3 = 'I\tam\tspy'
spy=str3.expandtabs()#expandtabs([tabsize=8])把字符串中的 tab 符号（\t）转换为空格，如不指定参数，默认的空格数是 tabsize=8。
print(spy)
print('--------------------------------------------------------------')
spy2=str3.find('spy')#find(sub[, start[, end]])检测 sub 是否包含在字符串中，如果有则返回索引值，否则返回 -1，start 和 end 参数表示范围，可选。
print(spy2)
print('----------------------------------------------')
spya=str3.rfind('s')#rfind(sub[, start[, end]])类似于 find() 方法，不过是从右边开始查找。
print(spya)
print('--------------------------------------------------------')
spyb=str3.isalnum()#isalnum()如果字符串至少有一个字符并且所有字符都是字母或数字则返回 True，否则返回 False。
print(spyb)
stra='123spy'
stra.isalpha()#isalpha()如果字符串至少有一个字符并且所有字符都是字母则返回 True，否则返回 False。
print('--------------------------------')
strb='101101101'
spy34=strb.isdecimal()#isdecimal()如果字符串只包含十进制数字则返回 True，否则返回 False。
print(spy34)
print('-----------------------------------------------------------------------')
spy24=stra.isdigit()#isdigit()如果字符串只包含数字则返回 True，否则返回 False。
print(spy24)
print('---------------------------------')
str4 = '小甲鱼'
spy3=str4.islower()#islower()如果字符串中至少包含一个区分大小写的字符，并且这些字符都是小写，则返回 True，否则返回 False。
print(spy3)
print('------------------------')
strc='SADASDASDADSADAS'
spyc=strc.lower()#lower()转换字符串中所有大写字符为小写。
print(spyc)
print('--------------------------------------')
strd='+=++'
spy19=strd.isnumeric()#isnumeric()如果字符串中只包含数字字符，则返回 True，否则返回 False。
print(spy19)
print('---------------------------------------------------------------')
stre='                '
spyd=stre.isspace()#isspace()如果字符串中只包含空格，则返回 True，否则返回 False。
print('spyd')
print('-------------------------------------')
str5 = 'Spy'
spy4=str5.istitle()#istitle()如果字符串是标题化（所有的单词都是以大写开始，其余字母均小写），则返回 True，否则返回 False。
print(spy4)
print('------------------------------------')
spye=strc.isupper()#isupper()如果字符串中至少包含一个区分大小写的字符，并且这些字符都是大写，则返回 True，否则返回 False。
print(spye)
print('------------------------------------------------------')
spy5=str5.join('12345')#join(sub)以字符串作为分隔符，插入到 sub 中所有的字符之间。
print(spy5)
print('-------------------------------------------------')
strf='I am spy'
spyf=strf.ljust(10)#ljust(width)返回一个左对齐的字符串，并使用空格填充至长度为 width 的新字符串。
print(spyf)
print('-------------------------------------------------')
spyf=strf.rjust(10)#rjust(width)返回一个右对齐的字符串，并使用空格填充至长度为 width 的新字符串。
print(spyf)
print('-------------------------------------------------------')
str6='     spy'
spy6=str6.lstrip()#lstrip()去掉字符串左边的所有空格
print(spy6)
print('------------------------')
strg='spy          '
spyg=strg.rstrip()#rstrip()删除字符串末尾的空格。
print(spyg)
print('------------------------------------------')
str6 = 'i am spy'
spy7=str6.partition('a')#partition(sub)找到子字符串 sub，把字符串分成一个 3 元组 (pre_sub, sub, fol_sub)，如果字符串中不包含 sub 则返回 ('原字符串', '', '')
print(spy7)
print('-------------------------------------------------------------------')
str6 = 'i am spy'
spy7=str6.rpartition('a')#rpartition(sub)类似于 partition() 方法，不过是从右边开始查找。
print(spy7)
print('------------------------------------------')
spy8=str6.replace('spy','SPY')#replace(old, new[, count])把字符串中的 old 子字符串替换成 new 子字符串，如果 count 指定，则替换不超过 count 次。
print(spy8)
print('------------------------------------')
spyh=str6.rindex('a')#rindex(sub[, start[, end]])类似于 index() 方法，不过是从右边开始。返回参数在字符串中的位置
print(spyh)
print('---------------------------------------------------------')
print(str6)
spy9=str6.split()#split(sep=None, maxsplit=-1)不带参数默认是以空格为分隔符切片字符串，如果 maxsplit 参数有设置，则仅分隔 maxsplit 个子字符串，返回切片后的子字符串拼接的列表
spy10=str6.split('i')
print(spy9,'                         ',spy10)
print('---------------------------------------------')
strh='s\np\ny\n'
spyi=strh.splitlines()#splitlines(([keepends]))在输出结果里是否去掉换行符，默认为 False，不包含换行符；如果为 True，则保留换行符。。
print(spyi)
print('----------------------------------------------------')
spyi=str6.startswith('i')#startswith(prefix[, start[, end]])检查字符串是否以 prefix 开头，是则返回 True，否则返回 False。start 和 end 参数可以指定范围检查，可选。
print(spyi)
print('--------------------------------')
str7 ='           sssssaaaasssss       '
spy11=str7.strip()#strip([chars])删除字符串前边和后边所有的空格，chars 参数可以定制删除的字符，可选。
print(spy11)
str8='Spy'
spy12=str8.strip('s')
print(spy12)
print('---------------------------------------------------------')
spy13=str8.swapcase()#swapcase()翻转字符串中的大小写
print(spy13)
print('------------------------------')
spyj=str6.title()#title()返回标题化（所有的单词都是以大写开始，其余字母均小写）的字符串。
print(spyj)
print('--------------------------------------------------------------')
str9='sasasasasasa'
spy14=str9.translate(str.maketrans('a','b'))#translate(table)根据 table 的规则（可以由 str.maketrans('a', 'b') 定制）转换字符串中的字符。
print(spy14)
print('---------------------------')
spyk=str7.upper()#upper()转换字符串中的所有小写字符为大写。
print(spyk)
print('-------------------------------------------------------------------------')
strl='asf'
spyl=strl.zfill(1)#zfill(width)返回长度为 width 的字符串，原字符串右对齐，前边用 0 填充。
print(spyl)
