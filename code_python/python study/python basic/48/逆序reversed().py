class Myrev:
    def __init__(self,date):
        self.date = date
        self.index = len(date)

    def __iter__(self):
        return self
    
    def __next__(self):
        if self.index == 0:
            raise StopIteration

        self.index = self.index - 1
        return self.date[self.index]
