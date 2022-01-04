def fibo(x):
    if x == 1 or x == 2:
        return 1
    return fibo(x - 1) + fibo(x - 2)


print(fibo(4))

d = [0] * 100


def fiboRecursion(x):
    if x == 1 or x == 2:
        return 1

    # 이미 계산한 적 있는 문제라면 그대로 반환
    if d[x] != 0:
        return d[x]

    # 아직 계산되지 않은 문제라면 점화식에 따라 결과 반환
    d[x] = fiboRecursion(x - 1) + fiboRecursion(x - 2)
    return d[x]


print(fiboRecursion(99))

d = [0] * 100

def fiboFor(x):
    d = [0] * 100
    d[1] = 1
    d[2] = 1
    n = 99

    for i in range(3, n + 1):
        d[i] = d[i - 1] + d[i - 2]

    print(d[n])
