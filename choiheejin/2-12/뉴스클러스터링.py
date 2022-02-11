# 두 글자씩 끊어서 다중 집합을 만듦 (영어 이외의 문자가 들어있는 쌍은 버림)
# 중복을 허용!
# 두 다중집합 비교, 대문자 소문자 안가림

# 한 문자가 알파벳인지 확인하는 함수
def precheck(e):
    if ord(e) > 64 and ord(e) < 91:
        return True
    return False

def solution(str1, str2):
    
    # 일단 모든 문자열을 대문자로 만듦
    str1 = str1.upper()
    str2 = str2.upper()
    
    str1MultiList = []
    str2MultiList = []

    # 다중 집합 만들기
    for i in range(len(str1) - 1):
        if precheck(str1[i]) and precheck(str1[i+1]):
            str1MultiList.append(str1[i:i+2])
    for i in range(len(str2) - 1):
        if precheck(str2[i]) and precheck(str2[i+1]):
            str2MultiList.append(str2[i:i+2])
    
    # 다중 집합에 대하여 중복이 없는 set 자료구조 만듦
    str1MultiSet = set(str1MultiList)
    str2MultiSet = set(str2MultiList)
    
    # 두 집합이 모두 공집합이라면 1 리턴
    if len(str1MultiSet) == 0 and len(str2MultiSet) == 0:
        return 65536
    
    # 일단 중복없이 교집합/합집합 구하기
    intersect = str1MultiSet & str2MultiSet
    union = str1MultiSet | str2MultiSet
    
    # 교집합 개수 구하기 
    intersectCount = 0
    for e in intersect:
        intersectCount += min(str1MultiList.count(e), str2MultiList.count(e))
        
    # 중복없이 합집합 구하기
    unionCount = 0
    for e in union:
        unionCount += max(str1MultiList.count(e), str2MultiList.count(e))
    
    return int((intersectCount / unionCount) * 65536)