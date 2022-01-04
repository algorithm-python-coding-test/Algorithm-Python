n = int(input())
array = list(map(int, input().split()))

# 경우의 수 두가지 탐색
def steal(array):
    if len(array) == 0:
        return 0
    # 리스트 개수 1일 경우
    if len(array) == 1:
        return array[0]
    
    # 리스트 개수 2일 경우
    if len(array) == 2:
        if array[0] > array[1]:
            return array[0]
        else:
            return array[1]
    
    case1 = array[0] + steal(array[2:])
    case2 = array[1] + steal(array[3:])

    if case1 > case2:
        return case1
    else:
        return case2

print(steal(array))

