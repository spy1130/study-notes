class Ticket:
    def __init__(self, weekend=False, child=False):
        self.exp =100#票价
        if weekend:
            self.inc =1.2#120%
        else:
            self.inc = 1
        if child:
            self.discount = 0.5
        else:
            self.discount = 1
    def calcPrice(self,num):
        return self.exp * self.inc * self.discount * num
        
