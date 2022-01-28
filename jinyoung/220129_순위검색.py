#!/usr/bin/env python
# coding: utf-8

# ## 개인풀이

# In[31]:


def solution(info, query):
    
    info_list = [sent.split()[:-1]+[int(sent.split()[-1])] for sent in info]
    query_list = [sent1.split(' and ')[:-1]+[sent1.split()[-2],int(sent1.split()[-1])] for sent1 in query]

    answer = []
    for q in query_list:
        cnt = 0
        for i in info_list:
            cnt+=check(i,q)
        answer.append(cnt)
    
    return answer

def check(p,q):
    for i,j in zip(p,q):
        if i==j or j=='-':
            continue
        elif type(i)==int and int(i)>=int(j):
            continue
        else:
            return 0
    return 1

#효율성 테스트 통과X


# 
# ##### 카카오 해설: https://tech.kakao.com/2021/01/25/2021-kakao-recruitment-round-1/
# ##### ->이진탐색 권장

# ## 다른사람 풀이

# #### 1) 이진탐색 사용

# In[37]:


from itertools import combinations
from bisect import bisect_left

def solution(info, query):
    
    answer = []
    info_dict = {}

    for i in range(len(info)):
        infol = info[i].split()  # info안의 문자열을 공백을 기준으로 분리
        mykey = infol[:-1]  # info의 점수제외부분을 key로 분류
        myval = infol[-1]  # info의 점수부분을 value로 분류

        for j in range(5):  # key들로 만들 수 있는 모든 조합 생성
            for c in combinations(mykey, j):
                tmp = ''.join(c)
                if tmp in info_dict:
                    info_dict[tmp].append(int(myval))  # 그 조합의 key값에 점수 추가
                else:
                    info_dict[tmp] = [int(myval)]

    for k in info_dict:
        info_dict[k].sort()  # dict안의 조합들을 점수순으로 정렬
    

    for qu in query:  # query도 마찬가지로 key와 value로 분리
        myqu = qu.split(' ')
        qu_key = myqu[:-1]
        qu_val = myqu[-1]

        while 'and' in qu_key:  # and 제거
            qu_key.remove('and')
        while '-' in qu_key:  # - 제거
            qu_key.remove('-')
        qu_key = ''.join(qu_key)  # dict의 key처럼 문자열로 변경

        if qu_key in info_dict:  # query의 key가 info_dict의 key로 존재하면
            scores = info_dict[qu_key]

            if scores:  # score리스트에 값이 존재하면
                enter = bisect_left(scores, int(qu_val))

                answer.append(len(scores) - enter)
        else:
            answer.append(0)

    return answer


# #### 2)이진탐색 미사용

# In[ ]:


def solution(info, query):
    data = dict()
    for a in ['cpp', 'java', 'python', '-']:
        for b in ['backend', 'frontend', '-']:
            for c in ['junior', 'senior', '-']:
                for d in ['chicken', 'pizza', '-']:
                    data.setdefault((a, b, c, d), list())
    for i in info:
        i = i.split()
        for a in [i[0], '-']:
            for b in [i[1], '-']:
                for c in [i[2], '-']:
                    for d in [i[3], '-']:
                        data[(a, b, c, d)].append(int(i[4]))

    for k in data:
        data[k].sort()

        # print(k, data[k])

    answer = list()
    for q in query:
        q = q.split()

        pool = data[(q[0], q[2], q[4], q[6])]
        find = int(q[7])
        l = 0
        r = len(pool)
        mid = 0
        while l < r:
            mid = (r+l)//2
            if pool[mid] >= find:
                r = mid
            else:
                l = mid+1
            # print(l, r, mid, answer)
        # answer.append((pool, find, mid))
        answer.append(len(pool)-l)

    return answer

