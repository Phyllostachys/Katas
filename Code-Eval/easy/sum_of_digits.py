# Python 3
import sys

test_cases = open(sys.argv[1], 'r')
for test in test_cases:
    if test == '':
        continue
    
    nums = []
    for c in test:
        if c != '\n':
            nums.append(int(c))

    print(sum(nums))

test_cases.close()