f1 = open('threebody.mp3','rb')
f2 = open('fayi.txt','xb+')
f2.write(f1.read())
f2.close()
f1.close()    