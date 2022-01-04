# - input
#   - A: 편집할 문자열
#   - B: 편집하여 만들 문자열
# - output
#   - 
# - constraint
#   - 1 <= len(A, B) <= 5000
# - edge case
#   - 
# - solution (어떻게 해서 문제를 풀 것인지)
#   - data structure
#     - dp : hashmap
#   - algorithm
#     - 재귀를 이용한 문자열 분리
#         - 왼쪽에서부터 겹치는 문자열을 분리하고
#         - B 문자열에서 겹치는 문자열 기준으로 안겹치는 문자열 위치(왼쪽 오른쪽)로 나누어
#         - 재귀 함수 호출
#         - 더이상 겹치는 문자열이 없을 시, 안겹치는 문자열을 교체(문자열 길이가 같다면), 삭제 혹은 추가(문자열 길이 다를 경우)
#     - s + unday, s + aturday
#     - unday, aturday
#     - u + nday, at + u + rday
#     - n + day, r + day    //  (빈문자열), at (추가 + 2)
#     - n, r (교체 + 1)

#     - dp 사용 : 두 문자열 튜플에 대한 정수 값 저장하기 위한 딕셔너리

#   - time complexity
#   - space complexity

A = input()
B = input()

# dp 사용
dp = {}

# 왼쪽에서부터 최초로 겹치는 문자열 찾아 리턴
# 이진검색
def find(A, B):
    ans = ""
    return ans

# 겹치는 문자열을 끝까지 분리하고
# 하나도 겹치지 않을 때 교체 번수 구하는 재귀 함수
def func(A, B):
    str = find(A, B)

    # 하나도 겹치지 않을 경우
    if str == "":
        if (len(A) == len(B)):
            dp[(A, B)] = len(A)
        else:
            dp[(A, B)] = len(B)
    
    # 겹치는 문자가 있을 경우
    splitA = A.split(str)
    splitB = B.split(str)
    
    for i in range(len(splitA)):
        for j in range(len(splitB)):
            if splitA[i] == str and splitB[j] == str:
                if i == 0:
                    leftA = ""
                    rightA = splitA[i+1]
                elif i == 1:
                    leftA = splitA[i-1]
                    rightA = splitA[i+1]
                else:
                    leftA = splitA[i-1]
                    rightA = ""
                
                if j == 0:
                    leftB = ""
                    rightB = splitB[j+1]
                elif j == 1:
                    leftB = splitB[j-1]
                    rightB = splitB[j+1]
                else:
                    leftB = splitB[j-1]
                    rightB = ""
                break

    dp[A, B] = func(leftA, leftB) + func(rightA, rightB)

print(dp[A, B])
    