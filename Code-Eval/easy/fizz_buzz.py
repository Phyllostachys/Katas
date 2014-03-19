# Python 3
import sys

test_cases = open(sys.argv[1], 'r')

for test in test_cases:
    if(test == ''):
        continue
    
    line_list = test.strip().split()
    a = int(line_list[0])
    b = int(line_list[1])
    n = int(line_list[2])
    out = ""

    for i in range(1,n+1):
        fizz = (i % a == 0)
        buzz = (i % b == 0)
        if(fizz and buzz):
            out = out + ' FB'
        elif(fizz):
            out = out + ' F'
        elif(buzz):
            out = out + ' B'
        else:
            out = out + ' ' + repr(i)
    
    out = out[1:]
    print(out)

test_cases.close()