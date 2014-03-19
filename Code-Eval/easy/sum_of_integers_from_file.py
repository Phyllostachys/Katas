# Python 3
import sys

test_cases = open(sys.argv[1], 'r')
sum = 0
for test in test_cases:
    if test == "":
      continue
    
    sum = sum + int(test)

print(sum)
test_cases.close()