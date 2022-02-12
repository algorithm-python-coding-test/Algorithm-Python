####개인 풀이

# 효율성  테스트
# 테스트 1 〉통과 (3.93ms, 10.5MB)
# 테스트 2 〉통과 (5.95ms, 10.5MB)
# 테스트 3 〉통과 (13.07ms, 11.1MB)
# 테스트 4 〉통과 (9.26ms, 12.2MB)
# 테스트 5 〉통과 (21.68ms, 11.8MB)
# 테스트 6 〉통과 (27.04ms, 12.2MB)
# 테스트 7 〉통과 (31.00ms, 12.6MB)
# 테스트 8 〉통과 (35.18ms, 13MB)
# 테스트 9 〉통과 (37.57ms, 13.4MB)
# 테스트 10 〉통과 (41.87ms, 14MB)
# 테스트 11 〉통과 (53.60ms, 14.7MB)
# 테스트 12 〉통과 (38.17ms, 16.1MB)
# 테스트 13 〉통과 (48.41ms, 16.9MB)
# 테스트 14 〉통과 (82.71ms, 16.9MB)
# 테스트 15 〉통과 (84.11ms, 17.8MB)
# 최소 3.93 최대 84.11

import collections

def solution(gems):
    
    #need는 보석 종류별로 1개씩 담은 딕셔너리
    #ex) need={"RUBY":1,"DIA":1,"EMERALD":1, "SAPPHIRE":1}
    #missing은 추가적으로 담아야 하는 보석종류의 수
    #ex) 위의 예에서는 4가지 보석이 있어야하기 떄문에 missing 값은 4에서 시작
    #left, right는 각각 이동하는 포인터를 의미하며 start,end는 최소길이일 때 갱신하기 위한 변수
    
    need = collections.Counter(list(set(gems)))
    missing=len(list(set(gems)))
    left=start=0
    end=len(gems)
    
    #need 딕셔너리는 모든 종류의 보석이 1의 값을 가진 상태에서 시작
    #right 포인터를 gems의 0에서부터 한칸씩 오른쪽으로 이동하면서 새로운 종류의 보석이 추가되면 missing을 1씩 빼줌
    #이 때 need 딕셔너리에서 해당 보석의 값을 1씩 빼주면 한개 이상 중복된 보석은 음수의 값을 가지게 됨
    #필요한 보석의 모든 종류가 포함될 때까지(missing이 0이 될 때까지) 이동
    #missing이 0이 되면 left 포인터를 0에서부터 오른쪽으로 이동하면서 need 딕셔너리의 해당 보석의 값을 1씩 더해줌
    #딕셔너리 값이 0보다 커지면 안되므로 그때 left와 right의 길이가 이전꺼보다 작으면 갱신

    for right, gem in enumerate(gems):

        missing -=need[gem] >0
        need[gem] -=1

        if missing ==0:

            while left <right and need[gems[left]]<0:

                need[gems[left]] +=1
                left +=1

                
            if right-left<end-start:
                end, start = right,left
            
            continue

    return [start+1,end+1]



####다른 사람 풀이

# 효율성  테스트
# 테스트 1 〉통과 (2.64ms, 10.5MB)
# 테스트 2 〉통과 (3.97ms, 10.6MB)
# 테스트 3 〉통과 (8.00ms, 11MB)
# 테스트 4 〉통과 (7.62ms, 11.6MB)
# 테스트 5 〉통과 (13.12ms, 11.7MB)
# 테스트 6 〉통과 (14.17ms, 12.2MB)
# 테스트 7 〉통과 (16.57ms, 12.5MB)
# 테스트 8 〉통과 (21.03ms, 12.9MB)
# 테스트 9 〉통과 (23.76ms, 13.4MB)
# 테스트 10 〉통과 (28.27ms, 13.7MB)
# 테스트 11 〉통과 (31.17ms, 14.6MB)
# 테스트 12 〉통과 (24.98ms, 15.4MB)
# 테스트 13 〉통과 (33.20ms, 16.1MB)
# 테스트 14 〉통과 (46.47ms, 16.9MB)
# 테스트 15 〉통과 (51.36ms, 17.7MB)
# 최소 2.64 최대 51.36

from collections import defaultdict

def solution(gems):
    
    start,end=0,len(gems)-1
    left,right=0,0
    dic = defaultdict(int)
    kind = len(set(gems))
 
    while right<len(gems):
        
        while len(dic) < kind and right<len(gems):
            dic[gems[right]]+=1
            right+=1
        while len(dic)==kind and left<=right:
            dic[gems[left]]-=1
            if (dic[gems[left]])==0:
                del(dic[gems[left]])
            left+=1
 
        if end-start> right - left:
            start=left-1
            end=right-1
            
    return[start+1,end+1]

