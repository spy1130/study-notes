class Rectangle():
    width = 4
    length = 5

    def setRect(self):
        print('请输入矩形的长和宽...')
        self.length = float(input('长：'))
        self.width =float(input('宽：'))

    def getRect(self):
        print('这个矩形长是：%.2f,宽是：%.2f' %(self.width,self.length))
    
    def getArea(self):
        return self.length * self.width
        