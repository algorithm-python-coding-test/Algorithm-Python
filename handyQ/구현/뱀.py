
def change(dir, direction):
    if (direction == "L"):
        dir = (dir - 1) % 4
    else:
        dir = (dir + 1) % 4
    return dir


def start():
    cnt = 0   # 시간 경과

    # 뱀 위치 표시
    i = 0
    j = 0

    lst[i][j] = 2
    dir = 0
    idx = 0

    # 뱀의 꼬리 ~ 머리까지의 정보를 Q에 담기
    Q = []
    Q.append((i, j))

    while True:
        # 몇초에 방향 전환 하는지
        if (turn[idx][0] == cnt):
            dir = change(dir, turn[idx][1])
            idx += 1
        ni = i + di[dir]
        nj = j + dj[dir]

        # 범위안에 있고, 자기자신이 아니라면
        if (0 <= ni < N and 0 <= nj < N and lst[ni][nj] != 2):

            # 사과를 먹으면 꼬리는 그대로
            if (lst[ni][nj] == 1):
                lst[ni][nj] = 2
                Q.append((ni, nj))
            # 사과를 못먹으면 꼬리 하나 떼기
            elif (lst[ni][nj] == 0):
                lst[ni][nj] = 2
                Q.append((ni, nj))
                pi, pj = Q.pop(0)
                lst[pi][pj] = 0
            i = ni
            j = nj
            cnt += 1
        else:
            cnt += 1
            break
    return cnt


N = int(input())
K = int(input())
lst = [[0]*N for _ in range(N)]

# 사과 표시
for _ in range(K):
    x,y = list(map(int, input().split()))
    lst[x-1][y-1] = 1


# 방향 전환

#횟수
turn_cnt = int(input())

# 방향전환 요소
turn = []
for i in range(turn_cnt):
    time, direction = input().split()
    turn.append([int(time), direction])
turn.append([0,0]) # 인덱스 에러 방지용

# 방향
    # 동 남 서 북
di = [0, 1, 0, -1]
dj = [1, 0, -1, 0]

res = start()
print(res)