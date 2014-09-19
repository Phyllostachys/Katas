# Python 3
import sys

test_cases = open(sys.argv[1], 'r')
for test in test_cases:
    s = ""
    words = test.strip().split()
    for i in range(len(words)):
        s = s + ' ' + words.pop()
    s.strip()
    print(s)

test_cases.close()