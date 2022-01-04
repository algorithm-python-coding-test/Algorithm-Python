n, m = map(int, input().split())
ddeuks = list(map(int, input().split()))
result = 0


def check(height):
    global m
    result = 0
    for ddeuk in ddeuks:
        if ddeuk <= height:
            continue
        result += ddeuk - height
    if result < m:
        return -1
    else:
        return 1


def search(start, end):
    global result

    if start > end:
        return None

    mid = (start + end) // 2
    if check(mid) == 1:
        result = mid
        search(mid + 1, end)
    else:
        search(start, mid - 1)


search(0, 19)
print(result)
