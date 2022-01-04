n = int(input())
people = list(map(int, input().split()))
people.sort(reverse=True)

count = 1
while True:

    # 제일 큰 값 만큼 배열 자르기
    people = people[people[0]: len(people)]
    print(people)

    # 나눠떨어지면 끝
    if (len(people) == 0):
        break

    # 남은 배열 중 제일 큰 값 이상의 길이인지 검사
    if (people[0] > len(people)):
        break
    count += 1

print(count)

    
    