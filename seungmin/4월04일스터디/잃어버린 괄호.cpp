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
    // ���ڿ��� ��� ���������� ��ȯ -> (���� : ����), (+ : -1), (- : -2)
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
    // ���� ���� ��� ó��
    // - �� ������ ������ ��� ���ڸ� ���ϰ�, - �� ������ ����
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
    // ������ ���� ����
    r.push_back(tem);

    // ���� ó��
    int answer = r[0];
    for (int i = 1; i < r.size(); i++) {
        answer -= r[i];
    }

    cout << answer << '\n';

    return 0;
}