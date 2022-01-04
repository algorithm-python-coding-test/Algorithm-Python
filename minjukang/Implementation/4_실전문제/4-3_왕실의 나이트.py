location = str(input())

data = [1,1,1,1,1,1,1,1]  #rru, rrd, llu, lld, uur, uul, ddr, ddl 경우의 수 가능여부

if 'a' in location:
    data[1] = 0
    data[2] = 0
    data[4] = 0
    data[6] = 0
elif 'b' in location:
    data[2] = 0
    data[3] = 0
elif 'g' in location:
    data[0] = 0
    data[1] = 0
if 'h' in location:
    data[0] = 0
    data[1] = 0
    data[4] = 0
    data[6] = 0
if '1' in location:
    data[0] = 0
    data[2] = 0
    data[4] = 0
    data[5] = 0
if '2' in location:
    data[4] = 0
    data[5] = 0
if '7' in location:
    data[6] = 0
    data[7] = 0
if '8' in location:
    data[1] = 0
    data[3] = 0
    data[6] = 0
    data[7] = 0

print(data.count(1))


# # 현재 나이트의 위치 입력받기
# input_data = input()
# row = int(input_data[1])
# column = int(ord(input_data[0])) - int(ord('a')) + 1
#
# # 나이트가 이동할 수 있는 8가지 방향 정의
# steps = [(-2, -1), (-1, -2), (1, -2), (2, -1), (2, 1), (1, 2), (-1, 2), (-2, 1)]
#
# # 8가지 방향에 대하여 각 위치로 이동이 가능한지 확인
# result = 0
# for step in steps:
#     # 이동하고자 하는 위치 확인
#     next_row = row + step[0]
#     next_column = column + step[1]
#     # 해당 위치로 이동이 가능하다면 카운트 증가
#     if next_row >= 1 and next_row <= 8 and next_column >= 1 and next_column <= 8:
#         result += 1
#
# print(result)