# Greedy



##### 탐욕 알고리즘 예

- 거스름돈 줄이기 문제

  거스름돈 주는 지폐와 동전 개수 최소로 

  1. 해 선택 : 단위 큰 동전 부터 선택
  2. 실행 가능성 검사 : 액수 초과 검사. 초과하면 다시 1로
  3. 해 검사 : 액수 모자라면 1로 돌아감

 실제로 500 100 50 10 원 일땐 가능. but 400 이 있다면 해결 안됨. 이런 경우는 완전탐색으로 값을 구해야 함.





##### 큰수의 법칙 p 92



- 가장 큰수, 두번 째로 큰 수 파악하기
- 가장 큰수 K 번 더하고, 두번째 큰수 한번 더하기 M 번 반복

```python
N, M, K = list(map(int, input().split()))
#print(N,M,K)
lst = list(map(int,input().split()))

lst.sort()
lst.reverse()
#print(lst)

ans=0

while M>0:
    for _ in range(K):
        ans += lst[0]
        M -= 1
        if M ==0:
            break
    ans += lst[1]
    M -=1

print(ans)
```





##### 숫자 카드 게임 p96



- 행마다 작은수 리스트 만들기
- 그 중 가장 큰수 뽑기

```python
N,M = map(int,input().split())

lst = [list(map(int,input().split())) for _ in range(N)]

min_lst = []
for i in range(N):

    row_min = 987654321
    for j in range(M):
        if lst[i][j] < row_min:
            row_min = lst[i][j]
    min_lst.append(row_min)


max_row = 0
num_row = 0

for n in range(len(min_lst)):
    if min_lst[n] > max_row:
        max_row = min_lst[n]
        num_row = n

print(num_row)
```



##### 1이 될 때 까지 p99



- K 배수가 될 때 까지 1씩 빼기



```python
N,K = map(int,input().split())

t=0
while N != 1:

    if N % K == 0:
        N /= K
        t+=1

    else:
        N -= 1
        t+=1

print(t)
```





