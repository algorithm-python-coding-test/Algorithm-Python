n, m = map(int, input().split())

d = [[0] * 2 for _ in range(n)] 
# 즉, 0이 1개 들어있는 리스트 [0]에 2를 곱하면 [0, 0]이 되는데, 
# 이걸 for i in range(n)으로 n번 반복해주면 [[0, 0], [0, 0], [0, 0]... n번 반복]이 됩니다.
x, y, direction = map(int, input().split())

array = []
for i in range(n):
    array.append(list(map(int, input().split())))

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

def turn_left():
    global direction 
    # global 선언하면 함수 바깥에 있는 전역 변수 수정 가능
    direction -= 1
    if direction == -1:
        direction = 3

count = 1
turn_time = 0
while True:
    turn_left()
    nx = x + dx[direction]
    ny = y + dy[direction]

    if d[nx][ny] == 0 and array[nx][ny] == 0:
        d[nx][ny] = 1
        x = nx
        y = ny
        count += 1
        turn_time = 0
        continue

    else:
        turn_time += 1
        if (turn_time == 4):
            nx = x - dx[direction]
            ny = y - dy[direction]

            if array[nx][ny] == 0:
                x = nx
                y = ny
            else:
                break
            turn_time = 0

print(count)