FT = list(map(int,input().split()))
k = int(input())
first_k = k      # k 딥카피

time = 1    # 시작시간은 1 부터
while True:

    if FT[time-1] != 0:   # 다 먹지 않았으면 먹는다.
        FT[time-1] -=1

    else:                # 다 먹은 곳이면 다음으로 continue
        time +=1
        continue

    time += 1             # 시간 더해주고

    if time == len(FT)+1:  # 시간이 FT 길이를 넘었으면
        time = 1            # 다시 처음으로.(인덱스)

    k -= 1                 # k 는 -1 씩 카운트
    if k==0:               # k 가 0되면 끝낸다.
        break


print(FT)           # 남은 FT 확인
print(time-2)         # 마지막 먹은 곳의 인덱스

################### 처음에 마지막 time으로 안하고 start = K % len(FT) 로 해서 , 0일때 넘어간 곳까지 세버림.

start = time-1
if time-1 <0:
    start = len(FT) + time-1

while True:
    if FT[start] != 0:
        print(start+1)   # 인덱스에서 하나 더한 값
        break
    else:
        start += 1