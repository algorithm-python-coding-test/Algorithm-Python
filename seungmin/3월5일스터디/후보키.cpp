// 2시간
// dfs로 시도했지만 실패..
// 모든 후보키 조합을 시도
// 중복을 걸러내기가 힘듦
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

int tuple_cnt, attr_cnt;
vector<string> attrs[8];
int ret = 0;

bool used[8];
char kind[20] = { 0, };

vector<string> keys;

bool cmp(string a, string b) {
    if (a.size() == b.size()) {
        return a < b;
    }
    else {
        return a.size() < b.size();
    }
}

int attr_kind(vector<string> attr, vector<int>& idx, vector<int>& idx2)
{
    int cnt = 0;

    for (int i = 0; i < attr.size() - 1; i++) {
        if (kind[i] == 1 || kind[i] == 2) continue;

        string attr_kind = attr[i];
        int j;
        int flag = 1;
        for (j = i + 1; j < attr.size(); j++) {
            string cur = attr[j];
            if (attr_kind == cur) {
                kind[i] = 2;
                kind[j] = 2;
                idx2.push_back(i);
                idx2.push_back(j);
                flag = 0;
            }
        }
        if (flag == 1) {
            kind[i] = 1;
            cnt++;
            idx.push_back(i);
        }
    }
    if (kind[attr.size() - 1] == 0) {
        kind[attr.size() - 1] = 1;
        cnt++;
        idx.push_back(attr.size() - 1);
    }
    return cnt;
}

//  1 2 3 4
//  1 23  123
void dfs(int s, int cnt)
{
    if (cnt == tuple_cnt) {
        string s;
        for (int i = 0; i < attr_cnt; i++) {
            if (used[i] == true) s += (i + '0');
        }
        keys.push_back(s);

        return;
    }
    vector<int> idx, idx2;

    for (int i = s; i < attr_cnt; i++) {
        if (used[i] == false) {
            used[i] = true;
            idx.clear();
            idx2.clear();
            int tem = attr_kind(attrs[i], idx, idx2);
            for (int j = 0; j < idx2.size(); j++) kind[idx2[j]] = 0;
            dfs(i + 1, cnt + tem);
            for (int j = 0; j < idx.size(); j++) kind[idx[j]] = 0;
            used[i] = false;
        }
    }
    return;
}

int solution(vector<vector<string>> relation) {
    int answer = 0;

    tuple_cnt = relation.size();
    attr_cnt = relation[0].size();

    for (int i = 0; i < tuple_cnt; i++) {
        for (int j = 0; j < attr_cnt; j++) {
            attrs[j].push_back(relation[i][j]);
        }
    }

    dfs(0, 0);

    bool key_used[8] = { 0, };
    sort(keys.begin(), keys.end(), cmp);

    for (int i = 0; i < keys.size(); i++) {
        if (key_used[i] == 0) answer++;
        string s = keys[i];
        for (int j = i + 1; j < keys.size(); j++) {
            if (key_used[j] == 0) {
                bool temp[8] = { 0, };
                for (int k = 0; k < s.size(); k++) temp[s[k] - '0'] = 1;
                string s2 = keys[j];
                int cnt = 0;
                for (int k = 0; k < s2.size(); k++) {
                    if (temp[s2[k] - '0'] == 1) cnt++;
                }
                if (cnt == s.size()) key_used[j] = 1;
            }
        }
    }
    return answer;
}

int main() {

    int sol = solution({ {"1","ryan","music"} ,{"1","apeach","math"},
        {"1","tube","computer"},{"6","tube","computer"},
        {"5","muzi","music"},{"6","apeach","computer"} });


    return 0;
}