n = int(input())
list = []

for i in range(n):
    list.append(int(input()))

# 퀵정렬
def quick_sort(array):
    pivot = array[0]
    tail = array[1:]

    left_side = [x for x in tail if x < pivot]
    right_side = [x for x in tail if x > pivot]

    return quick_sort(left_side) + [pivot] + quick_sort(right_side)


print(quick_sort(list))
