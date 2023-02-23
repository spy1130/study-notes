class  FileObject:
    def __init__(self,filename='sample.txt'):
        self.new_file = open(filename,'r+')

    def __del__(self):
        self.new_file.close()
        del self.new_file

