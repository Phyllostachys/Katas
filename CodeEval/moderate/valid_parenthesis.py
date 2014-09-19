# Python 3
import sys

match = {'(': ')', '{': '}', '[': ']'}
test_cases = open(sys.argv[1], 'r')
for test in test_cases:
    if test == '':
        continue
    parens = list(test.strip())
    pStack = []
    answer = "True"
    
    for p in parens:
        if p == '(' or p == '{' or p == '[':
            pStack.append(p)
        elif p == ')' or p == '}' or p == ']':
            if len(pStack) == 0 or p != match[pStack[-1]]:
                #print(p, pStack)
                answer = "False"
                break
            else:
                pStack.pop()
    if len(pStack) != 0:
        answer = "False"
    print(answer)
    

test_cases.close()
