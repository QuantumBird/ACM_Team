def apart(n):
    return [i for i in range(1, n) if n % i == 0]

n = int(input())
print(apart(10))

