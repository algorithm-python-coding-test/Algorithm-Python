# - input
#   - 집의 개수 (N), 공유기 개수(C)
# - output
#   - 가장 인접한 두 공유기 사이의 거리를 최대로 하는 프로그램
# - constraint
#   - 2 <= N <= 200,000
#   - 2 <= C <= N
# - edge case
#   - 2개일때에는 start, end에만 
# - solution (어떻게 해서 문제를 풀 것인지)
#   - 집 위치 정렬 후 
#   - 이진 탐색과 비슷한 방식으로
#   - 2개까지는 집의 처음과 끝에 달고
#   - 3번째 부터는 middle에서 제일 가까운 집을 찾아 설치한다.
#   - 그 다음에 start와 end를 재정의할 때에는 middle - start, end - middle 중 더 긴쪽을 골라 재정의한다.
#   - 다시 공유기 설치 반복

n, m = map(int, input().split())
homes = []

for i in range(n):
    homes.append(int(input()))

# 집 위치 정렬
homes.sort()

# 집 처음과 끝 위치에 두개 공유기 미리 설치했다고 가정
# first, second는 현재 설치된 공유기들 중 가장 거리가 먼 공유기의 왼쪽 오른쪽을 말함
first = 0
second = n - 1
installed = n
minD = homes[second] - homes[first]

# 3번째 부터는 middle에서 제일 가까운 집 찾아 설치하고 최단 거리 찾기
for i in range(m - 2):
    start = first
    end =  second
    target = (homes[first] + homes[second]) // 2

    # middle과 가장 가까운 집 찾기
    while start <= end:
        middle = (start + end) // 2
        if homes[middle] == target:
            installed = middle
            break
        elif homes[middle] < target:
            if homes[end] < target and end < n - 1:
                if target - homes[end] >=  homes[end + 1] - target:
                    installed = end + 1
                    break
                else:
                    installed = end
                    break
            else:
                start = middle + 1
        else:
            if homes[start] > target and start > 0:
                if homes[start] - target >= target - homes[start - 1]:
                    installed = start - 1
                    break
                else:
                    installed = start
                    break
            else:
                end = middle - 1
    
    if homes[installed] - homes[first] > homes[second] - homes[installed]:
        minD = homes[second] - homes[installed]
        second = installed
    else:
        minD = homes[installed] - homes[first]
        first = installed
        

print(minD)

# 로직에 오류가 있음
# 휴...
# 이거는 코드리뷰 안하셔도 될 것 같아요...