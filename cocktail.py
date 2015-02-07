import time
import random
def cocktailSort(A):
    up = range(len(A)-1)
    while True:
        for indices in (up, reversed(up)):
            swapped = False
            for i in indices:
                if A[i] > A[i+1]:  
                    A[i], A[i+1] =  A[i+1], A[i]
                    swapped = True
            if not swapped:
                return

test1 = [random.randint(1,100000) for _ in range(100000)]
print test1
t = time.clock()
cocktailSort(test1)
t = time.clock() - t
print test1
print t

 
