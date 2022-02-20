
###개인 풀이

###통과하지 못함
###가능한 아이디 후보군까지는 만들었지만 이후 가능한 쌍을 조합하는데서 막힘


from collections import Counter

def solution(user_id, banned_id):
    
    #불량사용자 아이디별 가능한 제재 아이디 후보로 딕셔너리 possible 생성
    # ex: {'fr*d*': ['frodo', 'fradi'], '*rodo': ['frodo', 'crodo'], '******': ['abc123', 'abc123', 'frodoc', 'frodoc']}
    #불량사용자 중 중복된 아이디의 수를 저장하기 위한 딕셔너리 duplicates 생성
    # ex {'******': 2, 'fr*d*': 1, '*rodo': 1}
    
    possible = {}
    duplicates = Counter(banned_id)
    
    for user in user_id:
        for banned in banned_id:
            if len(user)!=len(banned):
                continue
            else:
                for i in range(len(user)):
                    if user[i]!='*' and banned[i]!='*' and user[i]!=banned[i]:
                        break

                else:

                    if banned in possible.keys():
                        possible[banned].append(user)
                    else:
                        possible[banned]=[user]
    
    
    return 

###다른사람 풀이

###가능한 모든 조합을 먼저 뽑아낸 후 비교
### 최소 0.02, 최대 282.02ms

from itertools import permutations 

def check(users,banned_id):
    #각 조합과 banned_id 목록 비교
    for i in range(len(banned_id)):
        #글자 길이 비교
        if len(users[i]) != len(banned_id[i]):
            return False
        
        #각 글자 비교
        for j in range(len(users[i])):
            if banned_id[i][j] == "*":
                continue
            if banned_id[i][j] != users[i][j]:
                return False # 현재 튜플 불일치
    
    return True

def solution(user_id, banned_id):
    
    #banned_id 개수만큼 가능한 모든 user_id의 순열(튜플)로 리스트 생성
    #ex) user_id =  ["frodo", "fradi", "crodo", "abc123", "frodoc"], banned_id = ["fr*d*", "*rodo", "******", "******"]
    #    user_permutation = [('frodo', 'fradi', 'crodo', 'abc123'), ('frodo', 'fradi', 'crodo', 'frodoc'), ...]
    user_permutation = list(permutations(user_id,len(banned_id)))
    banned_Set = []

    for users in user_permutation:
        # 하나의 튜플과 비교 시작
        if not check(users, banned_id):
            continue # 다음 튜플 가져오기
        else:
            users = set(users)
            if users not in banned_Set:
                banned_Set.append(users)

    return len(banned_Set)

