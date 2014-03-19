# Python 3
import sys

test_cases = open(sys.argv[1], 'r')
for test in test_cases:
    if test == '':
        continue

    set1 = set(test.strip().split(';')[0].split(','))
    set2 = set(test.strip().split(';')[1].split(','))

    union_set = set1 & set2
    #print(union_set)
    
    union_list = list(union_set)
    union_list.sort()
    if len(union_list) != 0:
        print(','.join(c for c in union_list))
    
test_cases.close()