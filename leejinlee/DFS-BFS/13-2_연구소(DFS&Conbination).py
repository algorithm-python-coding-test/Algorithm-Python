from itertools import combinations
from copy import deepcopy

N, M = map(int, input().split())

mat = [[0] * M for _ in range(N)]

zeroPos = []
twoPos = []
maxSafeZone = 0

for i in range(N):
    row = list(map(int, input().split()))

    for j in range(M):
        mat[i][j] = row[j]

        if row[j] == 0:
            maxSafeZone += 1
            zeroPos.append((i, j))
        elif row[j] == 2:
            twoPos.append((i, j))

maxSafeZone -= 3
answer = 0

dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

for positions in combinations(zeroPos, 3):  # combination으로 벽이 세워질 장소 정하기
    cnt_trans = 0
    temp_mat = deepcopy(mat)

    for pos in positions:
        row, col = pos
        temp_mat[row][col] = 1

    stack = deepcopy(twoPos)

    while stack:
        # 바이러스 확산 시키기
        curR, curC = stack.pop()

        for i in range(4):
            if 0 <= curR + dy[i] < N and 0 <= curC + dx[i] < M and temp_mat[curR + dy[i]][curC + dx[i]] == 0:
                temp_mat[curR + dy[i]][curC + dx[i]] = 2
                cnt_trans += 1
                stack.append((curR + dy[i], curC + dx[i]))

    # 남아 있는 안전 영역의 최대 값 구하기
    if answer < maxSafeZone - cnt_trans:
        answer = maxSafeZone - cnt_trans

print(answer)