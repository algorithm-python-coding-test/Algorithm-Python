n = int(input())
array = list(map(int, input().split()))


def search(start, end):
    if start > end:
        return -1

    mid = (start + end) // 2

    if array[mid] == mid:
        return mid
    elif array[mid] < mid:
        return search(mid + 1, end)
    else:
        return search(start, mid - 1)


print(search(0, n - 1))
