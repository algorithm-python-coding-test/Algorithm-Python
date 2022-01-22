# 동적 계획법 사용 가능
# 대각선 두 방향을 분리하여 판단해야하기 때문에 테이블 두개로 나눔

from itertools import permutations

def check(graph):
    # dp 테이블 준비 : 북동-남서 
    dpNorthEast = [False] * (2 * len(graph) - 1)
    # dp 테이블 준비 : 북서-남동
    dpNorthWest = [False] * (2 * len(graph) - 1)
    for i in range(len(graph)):
        for j in range(len(graph)):
            if graph[i][j] == 1:
                # 해당 대각선에 퀸이 있으면 False 리턴
                if dpNorthEast[i + j] or dpNorthWest[i - j]:
                    return False
                # 해당 대각선에 퀸이 없으면 현재 퀸이있는 대각선을 True로 저장
                else:
                    dpNorthEast[i + j] = True
                    dpNorthWest[i - j] = True
    # 겹치는 대각선이 없을 경우 True 리턴
    return True
                

def solution(n):
    # 모든 경우의 수 구하기
    # 각 행마다 겹치지 않게 컬럼을 결정하여 퀸 두기
    # 이렇게 하면 조건 체크할 때 상하좌우는 체크할 필요없이 대각선만 체크하면 됨
    
    # 각 행마다 순서대로 설치할 컬럼의 순서를 정함 (1행의 x, 2행의 x, 3행의 x, 4행의 x)
    xCases = list(permutations([i for i in range(n)], n))
            
    answer = 0
    # 모든 경우의 수에 대하여 정해진 체스 위치에 퀸 두기
    for x in xCases:
        graph = [[0] * n for _ in range(n)]
        for i in range(n):
            graph[i][x[i]] = 1

        # 해당 경우가 조건에 맞는지 확인
        if check(graph):
            answer += 1

    return answer

print(solution(4))