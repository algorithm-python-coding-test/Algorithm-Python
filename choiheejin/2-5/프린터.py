# 우선순위:[인덱스배열], 우선순위[인덱스배열], ... => 최대 큐 저장
# answer = 0 초기화
# 우선순위가 제일 높은 것을 꺼내서 
# location 우선순위보다 큰 우선순위면
# answer += 배열 크기
# 커서 갱신 (이진탐색) => 정렬은 이미 되어있음
# 해당 커서보다 작은 인덱스가 존재한다면 그 인덱스 바로 밑 친구를 커서로
# 해당 커서보다 작은 인덱스가 존재하지 않는다면 최댓값을 커서로
# location 우선순위랑 같은 우선순위가 나왔다면
# 현재 커서보다 큰 인덱스부터 시작하여 차례대로 순서를 정함
# location우선순위 == 우선순위이면
# 해당 커서보다 큰 것들 중 가장 작은 것부터 꺼내어 location이 나올때까지 
# answer += 1
from bisect import bisect_left, bisect_right
# 우선순위 인덱스 배열
def solution(priorities, location):
    # {3: [2], 2:[0,3], 1:[1]}
    dictionary = {}
    for i in range(len(priorities)):
        # location의 Priority 저장
        if location == i:
            locationPriority = priorities[i]
        if priorities[i] not in dictionary:
            dictionary[priorities[i]] = [i]
        else:
            dictionary[priorities[i]].append(i)
    
    # 우선순위 내림차순 정렬
    dictKeys = list(dictionary.keys())
    dictKeys.sort(reverse=True)
    
    # 커서와 순서 갱신
    answer = 0
    cursor = 0
    # 각 우선순위에 대하여 
    for dictKey in dictKeys:
        indexes = dictionary[dictKey]
        # locationPriority 보다 해당 우선순위가 클 경우에는
        if dictKey > locationPriority:
            # 해당 배열 길이만큼 answer를 더함
            answer += len(indexes)
            # 인덱스의 최솟값이 커서보다 작을 경우(커서보다 작은 값이 존재할 경우)
            if indexes[0] < cursor:
                # 커서는 bisect_left보다 작은 값들중 가장 큰 것
                cursor = indexes[bisect_left(indexes, cursor) - 1]
            # 커서보다 작은 값이 없을 경우
            else:
                # 커서는 가장 큰 인덱스로 갱신
                cursor = indexes[-1]
        # 우선순위가 locationPriority와 같을 때
        elif dictKey == locationPriority:
            if cursor in indexes:
                i = indexes.index(cursor)
            # 커서보다 큰 값들 중 가장 작은 값부터 시작해야한다.
            # 만약 커서보다 큰 값이 존재한다면
            elif cursor < indexes[-1]:
                # i를 커서보다 큰 값들 중 가장 작은 값으로 초기화
                i = bisect_right(indexes, cursor)
            # 만약 커서보다 큰 값이 존재하지 않는다면
            else:
                # i를 가장 작은 값으로 초기화
                i = indexes[0]
            # indexes[i]를 꺼내보았다고 가정하고 answer +1
            answer += 1
            # indexes[i]가 location이면 answer 리턴하고
            # 아니면 i +1, answer +1 하고 다시 location과 비교
            while indexes[i % len(indexes)] != location:
                i += 1
                answer += 1
            break
        
    return answer

print(solution([1, 1, 1, 1], 0))