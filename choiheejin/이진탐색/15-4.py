import re

words = ["frodo", "front", "frost", "frozen", "frame", "kakao"]
queries = ["fro??", "????o", "fr???", "fro???", "pro?"]

# 하나의 쿼리에 대하여 일치 개수 구하기
def search(query, words, start, end):
    if start > end:
        return 0

    mid = (start + end) // 2
    word = words[mid]
    result = check(query, words[mid])
    count = 0

    if result == 0:
        count += search(query, words, start, mid - 1)
        count += search(query, words, mid + 1, end)

        query = query.replace("?", "[a-z]")
        p = re.compile(query)
        target = p.search(word)
        if target and (target.group() == word):
            count += 1
        return count
    # 쿼리가 더 클 경우
    elif result > 0:
        return search(query, words, mid + 1, end)
    # 워드가 더 클 경우
    else:
        return search(query, words, start, mid - 1)


# 하나의 쿼리에 대하여 길이 일치 개수 구하기
def check(query, word):
    if len(word) == len(query):
        return 0
    elif len(word) < len(query):
        return 1
    else:
        return -1


def solution(words, queries):
    answer = []
    words.sort(key=len)

    for query in queries:
        answer.append(search(query, words, 0, len(words) - 1))

    return answer


print(solution(words, queries))
