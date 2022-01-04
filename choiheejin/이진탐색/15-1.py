n, x = map(int, input().split())
array = list(map(int, input().split()))
count = 0
xEnd = -1
xStart = -1


def search(start, end):
    global x
    global count
    global xEnd
    global xStart

    if start > end:
        return None

    mid = (start + end) // 2
    if array[mid] == x:
        if mid == n - 1:
            xEnd = mid
        elif array[mid + 1] != x:
            xEnd = mid
        if mid == 0:
            xStart = mid
        elif array[mid - 1] != x:
            xStart = mid
        search(start, mid - 1)
        search(mid + 1, end)
    elif array[mid] < x:
        search(mid + 1, end)
    else:
        search(start, mid - 1)


search(0, n - 1)
if xEnd == -1:
    print(-1)
else:
    print(xEnd - xStart + 1)
