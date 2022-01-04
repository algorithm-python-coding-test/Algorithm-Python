def ans1():
    n, m = map(int, input().spli())

    result = 0

    for i in range(n):
        data = list(map(int, input().split()))
        min_value = min(data)
        result = max(result, min_value)

    print(result);

def ans2():
    n, m = map(int, input().spli())

    result = 0

    for i in range(n):
        data = list(map(int, input().split()))
        min_value = 10001
        for a in data:
            min_value = min(min_value, a)
        result = max(result, min_value)
    
    print(result)

