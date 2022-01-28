# info 1이상 50,000이하 # query 1이상 100,000이하
# 쿼리 하나에 대하여 가장 빠른 방법으로 체크해야한다.
# info 하나에는 5가지 조건이 있음 쿼리 하나당 50,000 * 5 = 250,000
# 완전탐색에 걸리는 것은 250,000 * 100,000
# 탈락자 찾아 걸러내기
# 통과한 친구들 리스트에서 나머지 조건만 필요한 것!만 체크
import heapq

def solution(info, query):
    # 모든 지원자 정보를 담을 리스트
    infoList = []

    # 모든 지원자 정보 담기 
    for i in range(len(info)):
        infoList.append(list(info[i].split()))
    
    # 답을 저장할 리스트
    result = []
    
    # 모든 쿼리에 대하여 
    for i in range(len(query)):
        # 이번 조건에 맞는 후보들 저장할 리스트
        passList = [i for i in range(len(info))]
        
        # 해당 쿼리들의 조건
        queryList = list(query[i].split(' and '))
        soul, score = queryList[3].split()
        queryList[3] = soul
        queryList.append(int(score))
        
        # 조건 0~3
        for j in range(4):
            # 해당 조건이 '-'가 아니면
            if queryList[j] != '-':
                # 통과자들을 후보자들로 옮기고
                applicants = passList[:]
                # 통과자 리스트 초기화
                passList = []
                # 후보자들에 대하여 조건 확인 
                for index in applicants:
                    if queryList[j] == infoList[index][j]:
                        passList.append(index)
                
        # 모든 조건을 통과한 passList에 대하여 코딩테스트를 통과한 후보자들의 수 더하기
        count = 0
        for index in passList:
            if int(infoList[index][4]) >= queryList[4]:
                count += 1
        result.append(count)
    return result

# 정확도 100 & 효율성 0