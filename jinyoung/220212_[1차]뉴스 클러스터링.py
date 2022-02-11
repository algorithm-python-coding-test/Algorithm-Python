#!/usr/bin/env python
# coding: utf-8

# In[1]:


####개인풀이

# 정확성  테스트
# 테스트 1 〉통과 (0.14ms, 10.4MB)
# 테스트 2 〉통과 (0.24ms, 10.3MB)
# 테스트 3 〉통과 (0.18ms, 10.5MB)
# 테스트 4 〉통과 (3.38ms, 10.7MB)
# 테스트 5 〉통과 (0.18ms, 10.3MB)
# 테스트 6 〉통과 (0.14ms, 10.4MB)
# 테스트 7 〉통과 (0.30ms, 10.4MB)
# 테스트 8 〉통과 (0.14ms, 10.4MB)
# 테스트 9 〉통과 (0.29ms, 10.3MB)
# 테스트 10 〉통과 (0.46ms, 10.5MB)
# 테스트 11 〉통과 (0.76ms, 10.3MB)
# 테스트 12 〉통과 (0.12ms, 10.3MB)
# 테스트 13 〉통과 (0.21ms, 10.4MB)
#최소 0.12 최대 3.38

#re함수를 사용해서 시간이 오래 걸림

import re
from collections import Counter

def solution(str1, str2):
    #2개 단위로 끊어서 영문자로 이루어진 것만 남기기
    str1_list = [re.findall('[a-zA-Z]{2}',str1.lower()[i:i+2]) for i in range(len(str1)-1)]
    str2_list = [re.findall('[a-zA-Z]{2}',str2.lower()[i:i+2]) for i in range(len(str2)-1)]
    
    #위의 re.findall 함수 때문에 리스트에 한 번 더 들어가 있어서 꺼내주기
    str1_list = [i[0] for i in str1_list if len(i)>=1]
    str2_list = [i[0] for i in str2_list if len(i)>=1]
    
    #Counter 함수 사용하여 글자 수 카운팅
    #Counter 함수는 O(n)의 시간복잡도
    str1_cnt = Counter(str1_list)
    str2_cnt = Counter(str2_list)
    
    #리스트를 집합으로 만들어주고 교집합과 합집합 원소의 수 담은 변수 만들기 
    str1_set,str2_set = set(str1_list),set(str2_list)
    cnt_inter = len(str1_set.intersection(str2_set))
    cnt_union = len(str1_set.union(str2_set))
    
    #교집합 원소 중 작게 카운팅 된 수를 더해주기
    for w in list(str1_set.intersection(str2_set)):
        cnt_inter+=min(str1_cnt[w],str2_cnt[w])-1
    #합집합 원소 중 크게 카운킹 된 수를 더해주기        
    for w in list(str1_set.union(str2_set)):
        cnt_union+=max(str1_cnt[w],str2_cnt[w])-1
    
    answer = int(cnt_inter/cnt_union*65536) if cnt_union!=0 else 65536
    return answer



####다른 사람 풀이

from collections import Counter

def solution(str1, str2):
    str1_low = str1.lower()
    str2_low = str2.lower()
    
    str1_lst = []
    str2_lst = []
    
    for i in range(len(str1_low)-1):
        if str1_low[i].isalpha() and str1_low[i+1].isalpha():
            str1_lst.append(str1_low[i] + str1_low[i+1])
    for j in range(len(str2_low)-1):
        if str2_low[j].isalpha() and str2_low[j+1].isalpha():
            str2_lst.append(str2_low[j] + str2_low[j+1])
            
    Counter1 = Counter(str1_lst)
    Counter2 = Counter(str2_lst)
    
    inter = list((Counter1 & Counter2).elements())
    union = list((Counter1 | Counter2).elements())
    
    if len(union) == 0 and len(inter) == 0:
        return 65536
    else:
        return int(len(inter) / len(union) * 65536)

# 정확성 테스트
# 테스트 1 〉통과 (0.05ms, 10.2MB)
# 테스트 2 〉통과 (0.05ms, 10.2MB)
# 테스트 3 〉통과 (0.04ms, 10.2MB)
# 테스트 4 〉통과 (0.74ms, 10.2MB)
# 테스트 5 〉통과 (0.04ms, 10.2MB)
# 테스트 6 〉통과 (0.04ms, 10.2MB)
# 테스트 7 〉통과 (0.12ms, 10.4MB)
# 테스트 8 〉통과 (0.05ms, 10.2MB)
# 테스트 9 〉통과 (0.10ms, 10.4MB)
# 테스트 10 〉통과 (0.20ms, 10.2MB)
# 테스트 11 〉통과 (0.35ms, 10.1MB)
# 테스트 12 〉통과 (0.04ms, 10.3MB)
# 테스트 13 〉통과 (0.08ms, 10.3MB)
# 최소 0.03 최대 0.74

