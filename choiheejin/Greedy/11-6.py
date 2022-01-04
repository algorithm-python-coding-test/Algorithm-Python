# constraint
#  - 1 <= len(food_times) <= 200,000
#  - 1 <= food_times[i] <= 100,000,000
#  - 1 <= k <= 2 * 10^13

# data structure
# remain: 남은 음식의 시간을 정렬한 배열
# lastMin: 전 음식이 끝난 시점
# time: k 시간동안 가장 마지막으로 어떤 음식이 끝난 시점을 계산한 값

# algorithm
#  - 음식이 하나씩 끝나는 시간을 단위로 잘라 계산
#  - 0. remain 복사 & 오름차순 정렬, time = 0, lastMin = 0
#  - 1. time += len(remain) * (remain[0] - lastMin) (len(remain) == 0일때에는 return -1)
#  - 2. time < k인지 확인
#    - 2.a. time < k이면
#       - 2.a.1. lastMin = remain[0]
#       - 2.a.2. remain에서 lastMin과 값이 같은 것들 삭제
#       - 1번으로 돌아가 수행
#    - 2.b time > k이면
#       - 2.b.1. time <= k일 때까지 time -= len(remain) 수행
#       - 2.b.2. time < k이면 food_times에서 remain[0]보다 작은 애들을 제외하고 k - time + 1번째에 있는 음식 인덱스 리턴
#       -        time == k이면 food_times에서 remain[0]보다 작거나 같은 애들을 제외하고 첫번째에 있는 음식 인덱스 리턴
#.   - 2.c time == k이면
#       - 2.c.1 food_times에서 remain[0]보다 작거나 같은 애들을 제외하고 첫번째에 있는 음식 인덱스 리턴
import copy

def fun(remain, food_times, lastMin, time, k):
    # len(remain) == 0일때에는 return -1
    if len(remain) == 0:
        return -1
    
    time += len(remain) * (remain[0] - lastMin)
    
    if time < k:
        # lastMin = remain[0]
        lastMin = remain[0]
        # remain에서 lastMin과 값이 같은 것들 삭제
        while lastMin in remain:
            del remain[0]
        # 1번으로 돌아가 수행
        return fun(remain, food_times, lastMin, time, k)
    elif time > k:
        while time > k:
            time -= len(remain)
        if time < k:
            count = 0
            for i in range(len(food_times)):
                if food_times[i] >= remain[0]:
                    count += 1
                    if count == k - time + 1:
                        return i + 1
        elif time == k:
            for i in range(len(food_times)):
                if food_times[i] > remain[0]:
                    return i + 1
    else:
        for i in range(len(food_times)):
            if food_times[i] > remain[0]:
                return i + 1
        
    

def solution(food_times, k):
    # remain 복사 & 정렬
    remain = copy.deepcopy(food_times)
    remain.sort()
    
    time = 0
    lastMin = 0
    
    return fun(remain, food_times, lastMin, time, k)