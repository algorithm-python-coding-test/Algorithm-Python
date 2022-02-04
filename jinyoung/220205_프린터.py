#!/usr/bin/env python
# coding: utf-8

# In[ ]:


### 개인풀이

def solution(priorities, location):
    #인텍스 리스트 생성
    idx_list = [i for i in range(len(priorities))]
    
    print_list = []
    idx_print_list = []
    while len(priorities)!=0:

        value = max(priorities)
        pop_pr = priorities.pop(0)
        pop_idx = idx_list.pop(0)
        #우선순위가 낮을 경우 다시 대기목록과 인덱스 리스트에 넣기
        #우선순위가 가장 높은 문서일 경우 프린트 리스트와 프린트 인덱스 리스트에 넣기
        if pop_pr < value:
            priorities.append(pop_pr)
            idx_list.append(pop_idx)
        else:
            print_list.append(pop_pr)
            idx_print_list.append(pop_idx)
            
    answer = idx_print_list.index(location)+1
    return answer

### 다른사람 풀이

def solution(priorities, location):
    queue =  [(i,p) for i,p in enumerate(priorities)]
    answer = 0
    while True:
        cur = queue.pop(0)
        if any(cur[1] < q[1] for q in queue):
            queue.append(cur)
        else:
            answer += 1
            if cur[0] == location:
                return answer

