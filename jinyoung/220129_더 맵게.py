#!/usr/bin/env python
# coding: utf-8

# ### 개인풀이

# In[1]:


import heapq
def solution(scoville, K):
    answer = 0
    heapq.heapify(scoville)
    for _ in range(len(scoville)):
        i = heapq.heappop(scoville)
        if i >K:
            return answer
        else:
            if len(scoville)==0:
                return -1
            else:
                j = heapq.heappop(scoville)
                n = i+2*j
                heapq.heappush(scoville, n)
                answer+=1
            
    return answer


# In[6]:


#sort 이용한 풀이
def solution(scoville, K):
    answer = 0
    
    for _ in range(len(scoville)):
        scoville.sort()
        i = scoville.pop(0)
        if i >K:
            return answer
        else:
            if len(scoville)==0:
                return -1
            else:
                j = scoville.pop(0)
                n = i+2*j
                scoville.append(n)
                answer+=1
            
    return answer

# 효율성  테스트
# 테스트 1 〉	실패 (시간 초과)
# 테스트 2 〉	실패 (시간 초과)
# 테스트 3 〉	실패 (시간 초과)
# 테스트 4 〉	실패 (시간 초과)
# 테스트 5 〉	실패 (시간 초과)
# 채점 결과
# 정확성: 76.2
# 효율성: 0.0
# 합계: 76.2 / 100.0

##정렬하는데 시간이 늘어남


# ### 다른풀이

# In[ ]:


#다른풀이
from heapq import heapify, heappush, heappop
def solution(scoville, K):
    heapify(scoville)
    for i in range(1000000):
        try:
            heappush(scoville, heappop(scoville)+(heappop(scoville)*2))
            if scoville[0] >= K: return i+1
        except:
            return -1

