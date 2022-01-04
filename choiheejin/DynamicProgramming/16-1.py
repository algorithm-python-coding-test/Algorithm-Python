def solution(n, m, mapArray):
    # dp 테이블
    d = [0] * (n * m)

    # 마지막 열 값 채우기
    for i in range(n):
        d[i * m + m - 1] = mapArray[i * m + m - 1]
        
    # 마지막에서 두번쨰 열부터 값 채우기
    for i in range(m-2, -1, -1):
        for j in range(n):
            if j == 0:
                d[j * m + i] = max(d[j * m + i + 1], d[(j + 1) * m + i + 1]) + mapArray[j * m + i]
            elif j == (n - 1):
                d[j * m + i] = max(d[j * m + i + 1], d[(j - 1) * m + i + 1]) + mapArray[j * m + i]
            else:
                d[j * m + i] = max(d[j * m + i + 1], d[(j - 1) * m + i + 1], d[(j + 1) * m + i + 1]) + mapArray[j * m + i]
    
    maxV = d[0]
    # 첫번째 열에서 최솟값 구하기
    for i in range(1, n):
        maxV = max(maxV, d[i * m])
    
    return maxV
    

t = int(input())

for i in range(t):
    n, m = map(int, input().split())
    mapArray = list(map(int, input().split()))
    print(solution(n, m, mapArray))