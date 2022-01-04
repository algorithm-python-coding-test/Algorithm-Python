n = int(input())
array = list(map(int, input().split()))

# dp테이블
d = [0] * 100

# 경우의 수 두가지 탐색
def steal(array):

    # 리스트 개수 1일 경우
    if len(array) == 1:
        d[1] = array[0]
    
    # 리스트 개수 2일 경우
    if len(array) == 2:
        d[2] = max(array[0], array[1])

    if d[len(array)] == 0:
        d[len(array)] = max(array[0] + steal(array[2:]), array[1] + steal(array[3:]))
    
    return d[len(array)]
    
print(steal(array))

