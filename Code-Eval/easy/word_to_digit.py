# Python 3
import sys

numWordMap = {"zero": 0,
              "one": 1,
              "two": 2,
              "three": 3,
              "four": 4,
              "five": 5,
              "six": 6,
              "seven": 7,
              "eight": 8,
              "nine": 9}
              
test_cases = open(sys.argv[1], 'r')

for test in test_cases:
    if test == "":
        continue
    
    words = test.strip().split(';')
    out = ''.join(str(numWordMap[c]) for c in words)
    
    #for i in range(len(words)):
    #    out = out + str(numWordMap[words[i]])
    
    print(out)
    

test_cases.close()