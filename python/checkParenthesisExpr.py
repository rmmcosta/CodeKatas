from myStack import MyStack

def isParenthesisExprValid(expr):
    parenthesisMatch = {')':'(', ']':'[', '}':'{'}
    parenthesisOpen = parenthesisMatch.values()
    parenthesis = MyStack()
    for each in expr:
        if(each in parenthesisOpen):
            parenthesis.push(each)
        elif(each in parenthesisMatch):
            if parenthesis.pull() != parenthesisMatch[each]:
                return False
        else:
            pass #do nothing
    return parenthesis.isEmpty()
