def get_ans(a, b, m):
    if b == 0:
        return 1
    ite = 1
    for i in range(b):
        print(ite)
        ite = a**ite
    return ite % m

print(get_ans(5, 4 ,233))
