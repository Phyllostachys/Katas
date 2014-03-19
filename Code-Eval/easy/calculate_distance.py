# Python 3
import sys
import math

test_cases = open(sys.argv[1], 'r')
for test in test_cases:
    if test == '':
        continue
    
    test = test.strip()
    
    x1 = int(test.split(',')[0].strip('('))
    y1 = int(test.split(',')[1].split(')')[0].strip())

    x2 = int(test.split(',')[1].split(')')[1].strip().strip('('))
    y2 = int(test.split(',')[-1].strip(')'))

    print(int(math.sqrt((x1 - x2)**2 + (y1 - y2)**2)))

test_cases.close()
