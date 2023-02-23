class temperature(float):
    def __new__(cls, arg=0.0):
        return float.__new__(cls,arg * 1.8 +32)
print(temperature(66))