# Python 3
import sys

class Rectangle:
    def __init__(self, x1, y1, x2, y2):
        self.x1 = x1
        self.y1 = y1
        self.x2 = x2
        self.y2 = y2
        
    def pointWithin(self, x, y):
        if x >= self.x1 and x <= self.x2:
            if y >= self.y2 and y <= self.y1:
                return True
        return False

test_cases = open(sys.argv[1], 'r')
for test in test_cases:
    coord = test.strip().split(',')
    
    for i in range(len(coord)):
        coord[i] = int(coord[i])
        
    minXVal = min(coord[0], coord[2], coord[4], coord[6])
    minYVal = min(coord[1], coord[3], coord[5], coord[7])
    #print("Minimum x and y: ", minXVal, minYVal)
    
    if minXVal < 0:
        minXVal = minXVal * -1
    if minYVal < 0:
        minYVal = minYVal * -1
        
    coord[0] = coord[0] + minXVal
    coord[2] = coord[2] + minXVal
    coord[4] = coord[4] + minXVal
    coord[6] = coord[6] + minXVal
    
    coord[1] = coord[1] + minYVal
    coord[3] = coord[3] + minYVal
    coord[5] = coord[5] + minYVal
    coord[7] = coord[7] + minYVal
    
    #for i in coord:
    #    print(i)
    
    r1 = Rectangle(coord[0], coord[1], coord[2], coord[3])
    r2 = Rectangle(coord[4], coord[5], coord[6], coord[7])
    print(r1.pointWithin(r2.x1, r2.y1) or r1.pointWithin(r2.x2, r2.y2) or r1.pointWithin(r2.x2, r2.y1) or r1.pointWithin(r2.x1, r2.y2))

test_cases.close()