/*
어려웠던 점
- 가능한 모든 경우를 dfs가 아닌 next_permutation으로 구하려다가 실패
- Set 자료구조에 대한 개념이 없어서 중복 처리가 힘들었음 -> 성공은 했으나 최대 7823ms 소요
*/

/*
다른 사람의 풀이 : dfs 사용

- user_id의 모든 경우를 dfs탐색하여 제재 아이디 쌍을 생성하고,
- 제재아이디는 Set에 저장 ( 중복 허용 X )

최대 : 20.79ms, 4.11MB
최소 : 0.01ms, 4.1MB
*/

#include <bits/stdc++.h>
using namespace std;

bool used[10];
set<string> S;

// 불량아이디 인지 확인
bool possi(string a, string b) {
    if (a.length() != b.length())
        return false;
    for (int i = 0; i < a.length(); i++)
        if (a[i] != b[i] && b[i] != '*')
            return false;
    return true;
}

void dfs(int p, vector<string> user_id, vector<string> banned_id) {
    // 불량아이디를 모두 찾았다면
    if (p == banned_id.size()) {
        string tmp;
        // index를 이어 붙여 tmp을 생성
        // user_id = { "abc", "fff", "wer", "def" } 이고
        // < "abc", "def" > , < "def" , "abc" >가 제재 아이디라면
        // user_id 앞에서 부터 탐색하므로 tmp는 둘다 "03"이 됨
        for (int i = 0; i < user_id.size(); i++)
            if (used[i]) tmp += i + '0';
        // 같은 "03"이므로 Set에서 하나로 취급됨
        S.insert(tmp);
        return;
    }
    // dfs 탐색 : 탐색한 아이디는 true 처리
    for (int i = 0; i < user_id.size(); i++)
        if (!used[i] && possi(user_id[i], banned_id[p]))
            used[i] = true, dfs(p + 1, user_id, banned_id), used[i] = false;
}

int solution(vector<string> user_id, vector<string> banned_id) {
    dfs(0, user_id, banned_id);
    return S.size();
}

int main()
{
    
    return 0;
}
