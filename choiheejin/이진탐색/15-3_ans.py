n, c = list(map(int, input().split(" ")))

array = []
for _ in range(n):
    array.append(int(input()))
array.sort()

start = 1
end = array[-1] - array[0]
result = 0

while start <= end:
    # 첫번째 집에 공유기 한개 설치
    mid = (start + end) // 2
    value = array[0]
    count = 1

    # 다음 공유기들을 앞에서부터 차례로 설치(mid 이상 띄워진 다음 집에 설치)
    for i in range(1, n):
        if array[i] >= value + mid:
            value = array[i]
            count += 1
    # c개 이상 공유기를 설치할 수 있다면 더큰 값이 있을지 확인
    if count >= c:
        start = mid + 1
        result = mid
    # 설치할 수 없다면 거리를 감소
    else:
        end = mid - 1

print(result)
