class Nstr(str):
    def __lshift__(self,other):
        return self[other:] + self[:other]
    def __rehift__(self,other):
        return self[:-other] + self[-other:]
            