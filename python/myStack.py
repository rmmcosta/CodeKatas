class MyStack:
    def __init__(self):
        self.stack = []
    def push(self, element):
        self.stack = [element] + self.stack
    def pull(self):
        pass
        try:
            top = self.stack[0]
            del(self.stack[0])
            return top
        except IndexError:
            return ValueError('Wrong operation. The stack is empty')
    def isEmpty(self):
        return self.stack == []
    def __str__(self):
        if(self.stack==[]):
            return '==='
        rep = ''
        for each in self.stack:
            rep = rep + ' ' + each + '\n'
        rep = rep + '==='
        return rep
