n = int(input())
whole = list(map(int, input().split()))
whole.sort()
m = int(input())
req = list(map(int, input().split()))
results = []

# 이진탐색
def search(target, start, end):
    if start > end:
        return "no"
    mid = (start + end) // 2

    if target == whole[mid]:
        return "yes"
    elif target > whole[mid]:
        return search(target, mid + 1, end)
    else:
        return search(target, start, mid - 1)


for i in req:
    results.append(search(i, 0, n - 1))

for result in results:
    print(result, end=" ")
