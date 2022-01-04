# https://programmers.co.kr/learn/courses/30/lessons/60057


# 1 ~ 길이의 반 까지 자르고 가장 짧은 것.

# aaaabbabbabb

s=input()

length = len(s)
len_res=[]

for l in range(1, length // 2 + 1):  # 자르는 단위 l

    lst = []

    for i in range(0, length, l):  # 인덱스 i
        lst.append(s[i:i + l])

    # print(lst)

    # 리스트 순회
    res = []
    j=0
    cnt=1

    while True:
        if lst[j] == lst[j + 1]:

            cnt += 1
            j += 1
            # 같았는데, 마지막 인덱스 전이면 끝내
            if j == len(lst)-1:
                if cnt!=1:
                    res.append(str(cnt))
                res.append(lst[j])
                break

        else:
            if cnt != 1:
                res.append(str(cnt))
            res.append(lst[j])
            cnt=1
            j+=1

            # 다른데, 마지막 인덱스 전이면 마지막꺼 추가해
            if j == len(lst)-1:
                res.append(lst[j])
                break

    # print(res)
    # print('---------------------------')

    join_res = "".join(res)
    # print(join_res)
    # print(len(join_res))
    len_res.append(len(join_res))
print(min(len_res))








