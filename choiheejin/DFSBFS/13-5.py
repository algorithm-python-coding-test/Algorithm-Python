# 재귀, 아마도 DFS
n = int(input())
numbers = list(map(int, input().split()))
operators = list(map(int, input().split()))

fixedOperators = []
resultList = []


def addOperator():
    # 연산자들이 다 정해졌을 경우
    if len(fixedOperators) == len(numbers) - 1:

        # 결과 계산
        result = numbers[0]
        for i in range(len(numbers) - 1):
            fixedOperator = fixedOperators[i]
            if fixedOperator == 0:
                result += numbers[i + 1]
            elif fixedOperator == 1:
                result -= numbers[i + 1]
            elif fixedOperator == 2:
                result *= numbers[i + 1]
            else:
                if result < 0:
                    result *= -1
                    result //= numbers[i + 1]
                    result *= -1
                else:
                    result //= numbers[i + 1]
        resultList.append(result)

    # 연산자 정하기
    for i in range(len(operators)):
        if operators[i] > 0:
            operators[i] -= 1
            fixedOperators.append(i)
            addOperator()
            fixedOperators.pop()
            operators[i] += 1


addOperator()
print(max(resultList))
print(min(resultList))
