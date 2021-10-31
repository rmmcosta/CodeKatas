import pytest

from myStack import MyStack

def testNewStackIsEmpty():
    stack1 = MyStack()
    assert stack1.isEmpty()

def testNotEmptyAfterInsertion():
    stack1 = MyStack()
    stack1.push(5)
    assert not stack1.isEmpty()

def testEmptyAfterPushPull():
    stack1 = MyStack()
    stack1.push(5)
    stack1.pull()
    assert stack1.isEmpty()

def testPushPull():
    stack1 = MyStack()
    stack1.push(5)
    assert 5 == stack1.pull()

testNewStackIsEmpty()