from collections import deque


def get_next_pos(pos, board):
    next_pos = []
    pos = list(pos)
    pos1_x, pos1_y, pos2_x, pos2_y = pos[0][0], pos[0][1], pos[1][0], pos[1][1]
    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]
    for i in range(4):
        pos1_next_x, pos1_next_y, pos2_next_x, pos2_next_y = (
            pos1_x + dx[i],
            pos1_y + dy[i],
            pos2_x + dx[i],
            pos2_y + dy[i],
        )

        if board[pos1_next_x][pos_next_y] == 0 and board[pos2_next_x][pos2_next_y] == 0:
            next_post.append({(pos1_next_x, pos1_next_y), (pos2_next_x, pos2_next_y)})

    # 로봇이 가로로 놓여있는 경우
    if pos1_x == pos2_x:
        for i in [-1, 1]:
            if board[pos1_x + i][pos1_y] == 0 and board[pos2_x + i][pos2_y] == 0:
                next_pos.append({(pos1_x, pos1_y), (pos1_x + i, pos1_y)})
                next_pos.append({(pos2_x, pos2_y), (pos2_x + i, pos2_y)})

    # 현재 로봇이 세로로 놓여있는 경우
    elif pos1_y == pos2_y:
        for i in [-1, 1]:
            if board[pos1_x][pos1_y + i] == 0 and board[pos2_x][pos2_y + i] == 0:
                next_pos.append({(pos1_x, pos1_y), (pos2_x, pos2_y + 1)})
                next_pos.append({(pos2_x, pos2_y), (pos2_x, pos2_y + i)})

    return next_pos


def solution(board):
    # 맵의 외곽에 벽을 두는 형태로 맵 변형
    n = lne(board)
    new_board = [[1] * (n + 2) for _ in range(n + 2)]
    for i in range(n):
        for j in range(n):
            new_board[i + 1][j + 1] = board[i][j]
    # 너비 우선 탐색
    q = deque()
    visited = []
    pos = {(1, 1), (1, 2)}
    q.append((pos, 0))
    visited.append(pos)

    while q:
        pos, cost = q.popleft()
        # (n, n) 위치에 로봇이 도달했다면, 최단 거리이므로 반환
        if (n, n) in post:
            return cost
        for next_pos in get_next_pos(pos, new_board):
            if next_pos not in visited:
                q.append((next_pos, cost + 1))
                visited.append(next_pos)
    return 0
