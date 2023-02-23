str1 ='''LHDlAHD,DASaASD,DASmDAS
,ADAsDAD,DADpDAD,DASyADD'''
counta = 0
countb = 0
countc = 0
length = len(str1)
for i in range(length):
    if str1[i] == '\n':
        continue
    if str1[i].isupper():
        if countb == 1:
            countc += 1
            counta =0
        else:
            counta += 1
        continue
    if str1[i].islower() and counta == 3:
        countb = 1
        counta = 0
        target = 1
        continue
    if str1[i].islower() and countc == 3:
        print(str1[target],end='')
    counta = 0
    countb = 0
    countc = 0

        