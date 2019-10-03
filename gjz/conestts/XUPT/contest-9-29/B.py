#from itertools import reduce
from math import gcd
def find_prime(n):
    chk = [True] * (n + 1)
    chk[0] = chk[1] = False
    for i in range(2, int(n**(0.5)) + 1):
        if chk[i]:
            for j in range(i + i, n + 1, i):
                chk[j] = False
    return [i for i in range(n + 1) if chk[i]]

def solve(n, pme_table):
    ansa, ansb = 1, 1
    for p in pme_table:
        ansa = ansa * p
        ansb = ansb * (p + 1)
        if ansa > n:
            aa = ansa // p
            ab = ansb // (p + 1)
            t = gcd(aa, ab)
            ans = "{}/{}".format(aa // t, ab // t)
            return ans

def main(pme_table):
    T = int(input())
    for i in range(T):
        n = int(input())
        print(solve(n, pme_table))

if __name__ == "__main__":
    pme = find_prime(1000)
    main(pme)


