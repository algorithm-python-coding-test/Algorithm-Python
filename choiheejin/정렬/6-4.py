array = [5, 7, 9, 0, 3, 1, 6, 2, 4, 8]

def quick_sort(array, start, end):
    # 원소가 1개일 경우 종료
    if start >= end:
        return
    pivot = start
    left = start + 1
    right = end

    # 왼쪽 오른쪽 탐색이 겹치기전까지
    while left <= right:
        while left <= end and array[left] <= array[pivot]:
            left += 1
        while right >= start and array[right] >= array[pivot]:
            right -= 1
        # 겹쳤다면?
        while left > right:
            array[right], array[pivot] = array[pivot], array[right]
        else:
            array[left], array[right] = array[right], array[left]
        
    # 분할 이후 왼쪽 부분과 오른쪽 부분에서 각각 정렬 수행
    quick_sort(array, start, right - 1)
    quick_sort(array, right + 1, end)

quick_sort(array, 0, len(array) -1)
print(array)