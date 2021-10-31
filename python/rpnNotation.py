from myStack import MyStack


def calculateRPN(expr):
    exprValues = expr.split()
    stackNums = MyStack()
    for each in exprValues:
        try:
            num = int(each)
            stackNums.push(num)
        except ValueError:
            if each == '+':
                value1 = stackNums.pull()
                value2 = stackNums.pull()
                stackNums.push(value1+value2)
            if each == '-':
                value1 = stackNums.pull()
                value2 = stackNums.pull()
                stackNums.push(value1-value2)
            if each == '*':
                value1 = stackNums.pull()
                value2 = stackNums.pull()
                stackNums.push(value1*value2)
            if each == '/':
                value1 = stackNums.pull()
                value2 = stackNums.pull()
                stackNums.push(value1/value2)
    return stackNums.pull()
