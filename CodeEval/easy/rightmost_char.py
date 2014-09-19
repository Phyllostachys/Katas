# Python 3
import sys

test_cases = open(sys.argv[1], 'r')
for test in test_cases:
    if test == "":
        continue
    
    #strip off spaces and newlines
    test = test.strip()
    index = 0

    # get last char
    t = test[-1]
    #print("t:", t)

    #get all but last two chars
    test = test[:-2]
    testLength = len(test)
    #print("line after poping last two:", test)

    while test != '':
        if test[-1] == t:
            print(testLength - index - 1)
            break
        else:
            # pop off last element
            test = test[:-1]
            index = index + 1
            if test == "":
              print(-1)
    
test_cases.close()