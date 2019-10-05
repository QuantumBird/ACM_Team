def check(n):
    s = bin(n)[2:]
    return sum([1 for c in s if c == '0']) == sum([1 for c in s if c == '1'])


for i in range(10000):
    if check(i):
        print(i)
