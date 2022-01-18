# 1. 모든 대기실의 위치를 확인하여 맨헤튼 거리가 2이하인 대기실 쌍을 찾기 (5C2 - 조합)
# 2. 대기실 쌍에 대해서 사이에 파티션이 있는지 확인
from itertools import combinations

# 각 대기실에 대하여 거리두기 성공인지 확인하는 함수
def check(place):
    
    # 모든 p의 위치 찾기 
    p = []
    for i in range(5):
        for j in range(5):
            if place[i][j] == 'P':
                p.append((i, j))
    
    # p의 리스트에 대한 모든 조합 찾기 
    allCouples = list(combinations(p, 2))
    
    # 각조합에 대하여 거리두기를 지켰는지 확인
    success = True
    for couple in allCouples:
        a, b = couple
        # 두 p의 거리 구하기 
        distance = abs(a[0] - b[0]) + abs(a[1] - b[1])
        # 거리가 1이면 실패
        if distance == 1:
            success = False
            break
        # 거리가 2이면 
        elif distance == 2:
            # 두 p가 일직선에 있을 경우 (가로로), 사이에 파티션 확인 
            if a[0] == b[0]:
                if place[a[0]][(a[1] + b[1]) // 2] != 'X':
                    success = False
                    break
            # 두 p가 일직선에 있을 경우 (세로로), 사이에 파티션 확인 
            elif a[1] == b[1]:
                if place[(a[0] + b[0]) // 2][a[1]] != 'X':
                    success = False
                    break
            # 두 p가 대각선 위치에 있을 경우, 정해진 자리에 파티션 확인
            elif place[a[0]][b[1]] != 'X' or place[b[0]][a[1]] != 'X':
                success = False
                break
    # 거리두기 지켰으면 1 리턴, 아니면 0 리턴 
    if success:
        return 1
    else:
        return 0     

def solution(places):
    answer = []
    for place in places:
        answer.append(check(place))

    return answer