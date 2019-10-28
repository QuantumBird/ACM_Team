from math import *

def log(a, b):
    return log10(b) / log10(a)

def make_table(n):
    for a in range(2, n + 1):
        for b in range(a, n + 1):
            print(ceil(log(a, b)), end=" ")
        print()

n = int(input())
make_table(n)


