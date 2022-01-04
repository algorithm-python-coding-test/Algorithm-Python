#△
def solution(s):
    count = 1
    result = ''
    n = []
    re = []
    for i in range(1, len(s) // 2 + 1):
        split = list(map(''.join, zip(*[iter(s)] * i)))
        for j in range(len(split) - 1):
            if split[j] == split[j + 1]:
                count += 1
            else:
                result += str(count) + split[j]
                count = 1
        re.append(result)
        n.append(len(result))

        print(re)
        print(split)
    print(n)
    answer = min(n)
    return answer