# - input
#   - 학생들의 수(N), 두 학생듸 성적을 비교한 횟수/간선 개수(M), 성적 비교
# - output
#   - 성적 순위를 정확히 알 수 있는 학생의 수
# - constraint
#   - 2 <= n <= 500
#   - 2 <= m <= 10000
# - edge case
#   - 
# - solution (어떻게 해서 문제를 풀 것인지)
#   - data structure
#     - 플로이드 워셜을 이용
#   - algorithm
#     - 인접 행렬 방식으로 A < B 일시 A -> B 표현
#     - 대소 관계가 있다면 True, 없다면 False으로 표시 (편의를 위해 자기 자신은 True)
#     - 점화식 (A -> B & B -> C이면 A -> C)을 통해 인접 행렬 그래프 갱신
#     - 각 학생에 대하여 자신을 제외한 모든 학생들과 대소 관계를 가진 학생의 수를 구함
#   - time complexity
#   - space complexity

n, m = map(int, input().split())

# 인접 행렬
graph = [[False] * (n + 1) for _ in range(n + 1)]

# 자기자신은 True
for i in range(1, n + 1):
    graph[i][i] = True

# 간선 입력 받기
for _ in range(m):
    a, b = map(int, input().split())
    graph[a][b] = True

# 플로이드 워셜
for i in range(1, n + 1):
    for a in range(1, n + 1):
        for b in range(1, n + 1):
            if graph[a][i] and graph[i][b]:
                graph[a][b] = True

# 각 학생에 대해서 모든 다른 학생들과 간선이 연결되어있지 않은 학생이 존재할떄마다 count -= 1
count = n

for i in range(1, n + 1):
    # 학생의 순위를 알 수 있는 지 여부
    identified = True
    for j in range(1, n + 1):
        if not graph[i][j] and not graph[j][i]:
            identified = False
            break
    # 해당 학생의 순위를 알 수 없다면 count -= 1
    if not identified:
        count -= 1

print(count)