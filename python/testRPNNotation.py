from rpnNotation import calculateRPN
import pytest


def test12():
    assert 3 == calculateRPN("1 2 +")


def test123():
    assert 6 == calculateRPN("1 2 + 3 +")


def testPlusPlus():
    assert 6 == calculateRPN("1 2 3 + +")


def testPlusAndMinus():
    assert 5 == calculateRPN("5 5 5 + -")


def testMultiAndDiv():
    assert 5 == calculateRPN("2 2 5 * /")


def testAllOperations():
    assert 62 == calculateRPN("4 3 6 * + 5 8 * +")
