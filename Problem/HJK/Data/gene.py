top = 2*10**5
fileName = 'data'

n = int(input("number of datafile: "))

from random import randint

def geneAs(n):
    return [randint(1, 10**9) for _ in range(n)]

def geneNs(q):
    while True:
        ans = [randint(1, top // 10000) for _ in range(q)]
        # print(sum(ans))
        if sum(ans) <= top:
            return ans

for i in range(n):
    print("{}/{}".format(i + 1, n))
    with open(fileName + str(i + 1) + '.in', 'w') as f:
        q = randint(1, top // 1000)
        # print(q)
        f.write("{}\n".format(q))
        ns = geneNs(q)
        for n in ns:
            k = randint(1, n)
            f.write("{} {}\n".format(n, k))
            ans = geneAs(n)
            f.write(str(ans[0]))
            for a in ans[1:]:
                f.write(" {}".format(a))
            f.write('\n')

print("CMPL")





