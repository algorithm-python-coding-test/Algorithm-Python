# #이해부족 + 결과 x
# N = int(input())
# data = list(map(int, input().split()))
# i = 1
#
# for i in range(len(data)):
#     data[i]+data[i+1]
#
#
#
# while(True):
#     if i in data: #리스트에 i가 있으면
#         print("")
#         i += 1   # 다음 숫자 찾기
#     else:
#         #if
#         print(i)


n = int(input())
data = list(map(int, input().split()))
data.sort()

target = 1
for x in data:
    # 만들 수 없는 금액을 찾았을 때 반복 종료
    if target < x:
        break
    target += x

# 만들 수 없는 금액 출력
print(target)


