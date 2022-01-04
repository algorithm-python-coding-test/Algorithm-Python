# 결과 못냄
lst = input()

S=list(lst)
suc = False
flip = 0
num = 0
print(S)
while(S.count(0) != len(S) and S.count(1) != len(S)):
    for i in range(0, len(S)):
        if(S.count(0) > S.count(1)):
            if S[i] == 1 and suc == False:
                S[i] = 0
                flip += 1
                suc == True
                print(S)
            if S[i] == 0 and suc == True:
                suc = False
            if S[i] == 1 and suc == True:
                S[i] = 0
                flip += 1
                print(S)
        else:
            if S[i] == 0 and suc == False:
                S[i] = 1
                flip += 1
                suc == True
                print(S)
            if S[i] == 1 and suc == True:
                suc = False
            if S[i] == 0 and suc == True:
                S[i] = 1
                flip += 1
                print(S)

print(flip)


# data = input()
# count0 = 0 # 전부 0으로 바꾸는 경우
# count1 = 0 # 전부 1로 바꾸는 경우
#
# # 첫 번째 원소에 대해서 처리
# if data[0] == '1':
#     count0 += 1
# else:
#     count1 += 1
#
# # 두 번째 원소부터 모든 원소를 확인하며
# for i in range(len(data) - 1):
#     if data[i] != data[i + 1]:
#         # 다음 수에서 1로 바뀌는 경우
#         if data[i + 1] == '1':
#             count0 += 1
#         # 다음 수에서 0으로 바뀌는 경우
#         else:
#             count1 += 1
#
# print(min(count0, count1))

