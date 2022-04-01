#include <string>
#include <iostream>
#include <vector>
using namespace std;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;

    vector<int> t;
    // 문자열을 모두 정수값으로 변환 -> (숫자 : 숫자), (+ : -1), (- : -2)
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '+') t.push_back(-1);
        else if (s[i] == '-') t.push_back(-2);
        else {
            int tem = 0;
            while (s[i] >= '0' && s[i] <= '9') {
                tem = 10 * tem + s[i] - '0'; i++;
            }
            t.push_back(tem);
            i--;
        }
    }
    // 덧셈 먼저 모두 처리
    // - 가 나오기 전까지 모든 숫자를 더하고, - 가 나오면 저장
    vector<int> r;
    int tem = t[0];
    for (int i = 1; i < t.size(); i += 2) {
        if (t[i] == -1) {
            tem += t[i + 1];
        }
        else if (t[i] == -2) {
            r.push_back(tem);
            tem = t[i + 1];
        }
    }
    // 마지막 숫자 저장
    r.push_back(tem);

    // 뺄셈 처리
    int answer = r[0];
    for (int i = 1; i < r.size(); i++) {
        answer -= r[i];
    }

    cout << answer << '\n';

    return 0;
}