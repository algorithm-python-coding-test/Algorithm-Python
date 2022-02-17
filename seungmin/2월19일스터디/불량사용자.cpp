/*
어려웠던 점
- possible case가 처음 나오면 가능한 모든 경우를 next_permutation으로 구하여 배열에 저장후,
다음 possible case가 나올 때마다 배열을 순회하여 중복되는게 있는지 확인 -> 성공은 했으나 최대 7823ms 소요

*/

/*
다른 사람의 풀이 : 

-  dfs로 해당 아이디를 탐색했는지 체크하는 true/false 배열을 선언하고
possible case가 나오면 배열 앞에서부터 true/false확인하여 index문자열을 만들어줌

(ex) 5->3->7->2 로 제재아이디를 확인했다면 "2357" 문자열
     2->3->5->7 로 제재아이디를 확인해도 "2357" 문자열
     ---> 중복case에 대해 처리 가능

- 위 문자열은 Set 자료구조에 저장 ( 중복 허용 X )

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
