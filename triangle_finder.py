import pprint

biggestNum = 500
solutions = {}

for a in range(1, biggestNum):
    for b in range(1, a):
        for c in range(1, a+b):
            fa, fb, fc = sorted([a, b, c])
            if fa + fb <= fc:
                continue
            #if fa**2 + fb**2 < fc**2:
            if fa**2 + fb**2 == fc**2:
            #if fa**2 + fb**2 > fc**2:
                solutions[a*b*c] = sorted([fa, fb, fc])

pp = pprint.PrettyPrinter(indent=4)
pp.pprint(solutions)
