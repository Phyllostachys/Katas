# Python 2
import sys

ones = {1: "One",   2: "Two",   3: "Three",
        4: "Four",  5: "Five",  6: "Six",
        7: "Seven", 8: "Eight", 9: "Nine"}

tens = {10: "Ten",      11: "Eleven",   12: "Twelve",  13: "Thirteen",
        14: "Fourteen", 15: "Fifteen",  16: "Sixteen", 17: "Seventeen",
        18: "Eighteen", 19: "Nineteen", 20: "Twenty",  30: "Thirty",
        40: "Forty",    50: "Fifty",    80: "Eighty"}

def getOnesWord(number):
    return ones[number]

def getTensWord(number):
    if number < 10:
        return getOnesWord(number)
    try:
        return tens[number]
    except KeyError:
        try:
            return tens[number - (number % 10)] + getOnesWord(number % 10)
        except KeyError:
            quot = number / 10
            rem = number % 10
            return getOnesWord(quot) + "ty" + getOnesWord(rem)

def getHundredsWord(number):
    if number < 100:
        return getTensWord(number)
    s = ''
    s = getOnesWord(number / 100) + "Hundred"
    if number % 100 != 0:
        return s + getTensWord(number % 100)
    else:
        return s

def intToDollars(number):
    res = ""
    
    # get millions
    if number / 1000000 > 0:
        res = getHundredsWord(number / 1000000) + "Million"
        number = number % 1000000
    
    # get thousands
    if number / 1000 > 0:
        res = res + getHundredsWord(number / 1000) + "Thousand"
        number = number % 1000
    
    # get hundreds and less
    if number > 0:
        res = res + getHundredsWord(number)

    return res + "Dollars"

test_cases = open(sys.argv[1], 'r')
for test in test_cases:
    if test == '':
        continue

    print intToDollars(int(test))

test_cases.close()
