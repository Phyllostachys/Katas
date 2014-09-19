# python 3

import sys
test_cases = open(sys.argv[1], 'r')
for test in test_cases:
    if test == "":
        continue
    number = test.strip().split(' ')[0]
    pattern = test.strip().split(' ')[1]
    #print(number, pattern)
    try:
        index = pattern.index('+')
        op = '+'
    except:
        index = pattern.index('-')
        op = '-'
    #print(index, op)
    num1 = int(number[:index])
    num2 = int(number[index:])
    #print(num1, num2)
    if op == '+':
        print(num1 + num2)
    elif op == '-':
        print(num1 - num2)

test_cases.close()