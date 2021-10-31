import pytest
from checkParenthesisExpr import isParenthesisExprValid


def testCorrectExpr1():
    assert isParenthesisExprValid("(5+2)")

def testCorrectExpr2():
    assert isParenthesisExprValid("[5,2]")

def testCorrectExpr3():
    assert isParenthesisExprValid("{'xpto':2}")

def testCorrectExprMix():
    assert isParenthesisExprValid("{'xpto':2}(5+2)[5,2]")

def testIncorrectExpr1():
    assert not isParenthesisExprValid("(5+2")

def testIncorrectExpr2():
    assert not isParenthesisExprValid("[5,2")

def testIncorrectExpr3():
    assert not isParenthesisExprValid("{'xpto':2")

def testIncorrectExpr4():
    assert not isParenthesisExprValid("(5+2]")

def testIncorrectExpr5():
    assert not isParenthesisExprValid("[5,2}")

def testIncorrectExpr6():
    assert not isParenthesisExprValid("{'xpto':2)")

def testIncorrectExprMix():
    assert not isParenthesisExprValid("{'xpto':2](5+2}[5,2)")