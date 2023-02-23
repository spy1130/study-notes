import random
import easygui as g

list = ['SPY','搞Y波（秘籍：Y波相吸！！！）','老马儿~~~~哐嘡，哐嘡，宇~~~~~']
indexes = random.randint(0,2)
g.msgbox(list[indexes])
