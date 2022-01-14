# 이진 탐색을 이용하여 ? 처음과 끝 찾기
def findWildCard(query):
    start = 0
    end = len(query) - 1
    # ?으로 시작할 경우
    if query.startswith('?'):
        # 처음부터 끝까지 ?일 경우 그냥 처음과 끝 리턴
        if query.endswith('?'):
            return (start, end)

        # 처음은 ?이지만 중간부터는 문자열일 경우 마지막 ? 찾기
        wildCardStart = 0
        while start <= end:
            middle = (start + end) // 2
            if query[middle] == '?':
                if query[middle + 1] != '?':
                    wildCardEnd = middle
                    break
                else:
                    start = middle + 1
            else:
                end = middle - 1
    # 중간부터 ?가 시작될 경우
    # 어디서부터 ?가 시작되는지 시작점을 탐색
    else:
        wildCardEnd = len(query) - 1

        while start <= end:
            middle = (start + end) // 2
            if query[middle] == '?':
                if query[middle - 1] != '?':
                    wildCardStart = middle
                    break
                else:
                    end = middle - 1
            else:
                start = middle + 1
    # ?의 시작점과 끝점 리턴
    return (wildCardStart, wildCardEnd)

# word 별로 매치여부 검사
def findMatch(query, words):
    count = 0
    for word in words:
        # 길이 안맞으면 넘어감
        if len(word) != len(query):
            continue

        # ?가 어디서부터 어디까지인지 파악해야함 
        start, end = findWildCard(query)
        # 모두 ?일 경우 길이 확인했으니 바로 count +1
        if start == 0 and end == len(query) - 1:
            count += 1
        # ?가 처음부터 시작되지만 중간에서 끊기는 경우, 끊기는 부분부터 잘라서 검사 
        elif start == 0:
            if query[end + 1:] == word[end + 1:]:
                count += 1
        # ?가 중간부터 시작되는 경우, 그전까지 잘라서 검사
        else:
            if query[0:start] == word[0:start]:
                count += 1
    return count

def solution(words, queries):
    answer = []
    for query in queries:
        answer.append(findMatch(query, words))

    return answer

print(solution(["frodo", "front", "frost", "frozen", "frame", "kakao"], ["fro??", "????o", "fr???", "fro???", "pro?"]))

# 정확도 100%
# 효율성 테스트 1, 2, 3 시간초과 4, 5 통과