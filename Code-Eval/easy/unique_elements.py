# Python 3
import sys

test_cases = open(sys.argv[1], 'r')
for test in test_cases:
    if test == '':
        continue

    num_list = test.strip().split(',')
    #print(num_list)
    
    num_set = set()

    for c in num_list:
        num_set.add(int(c))
        #print(num_set)

    num_list = list(num_set)
    num_list.sort()
    print(','.join(str(c) for c in num_list))

test_cases.close()