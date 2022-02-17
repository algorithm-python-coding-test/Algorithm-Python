//GG

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> user_divided_len[9];
vector<string> banned_divided_len[9];

bool comp_user(string user, string ban) {
    int len = user.length();
    bool ret = true;
    for (int i = 0; i < len; i++) {
        if (ban[i] == '*' || user[i] == ban[i]) continue;
        else if (user[i] != ban[i]) {
            ret = false;
            break;
        }
    }
    return ret;
}

int factorial(int num) {
    if (num == 0 || num == 1) return 1;
    return num * factorial(num - 1);
}

int solution(vector<string> user_id, vector<string> banned_id) {
    sort(user_id.begin(), user_id.end());
    for (int i = 0; i < user_id.size(); i++) {
        user_divided_len[user_id[i].length()].push_back(user_id[i]);
    }
    for (int i = 0; i < banned_id.size(); i++) {
        banned_divided_len[banned_id[i].length()].push_back(banned_id[i]);
    }
    int answer = 1;
    for (int i = 1; i <= 8; i++) {
        if (banned_divided_len[i].size() == 0) continue;
        int temp = 0;

        do {
            bool pos = true;
            for (int j = 0; j < banned_divided_len[i].size(); j++) {
                if (!comp_user(user_divided_len[i][j], banned_divided_len[i][j])) pos = false;
            }
            if (pos) temp++;
        } while (next_permutation(user_divided_len[i].begin(), user_divided_len[i].end()));
        int fact = user_divided_len[i].size() - banned_divided_len[i].size();
        answer *= temp / factorial(fact);
    }

    return answer;
}

int main() {
    int ret = solution({ "frodo", "fradi", "crodo", "abc123", "frodoc" }, { "*rodo", "*rodo", "******" });
    cout << ret;
}