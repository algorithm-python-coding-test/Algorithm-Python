/*
* problem : �޾ƾ��� (https://www.acmicpc.net/problem/20542)
* i�� i, j, l�� ��� ��Ī�Ǹ� v�� v, w�� ��Ī�� ��, �޾ƾ��� ������ ���ϱ�
*
* 168ms / 90MB �� ����
*/

//�����Ÿ� �˰��� (Levensthein Algorithm)�� ����
//�����Ÿ� �˰���� ���� ������ ������ + ���� ���̽��� ó��
//�� ���ڿ��� ���̰� �ִ� 1,000,000�̹Ƿ� �����Ҵ� dp���̺�� ó�� �Ұ���
//vector�� ����Ͽ� �����Ҵ� �ϴ� ������� ����
//-> n * m�� dp���̺��� ����ϹǷ� �ð����⵵�� O(N*M) ~= O(N^2)

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> dp;

int solution(string str1, string str2) {
    //�˰����� ���ϰ� �����ϱ� ���� ��������
    string ans = "0" + str1;
    string sol = "0" + str2;
    //dp���̺� �ʱ�ȭ
    for (int r = 1; r <= n; r++) {
        dp[r][0] = dp[r - 1][0] + 1;
    }
    for (int c = 1; c <= m; c++) {
        dp[0][c] = dp[0][c - 1] + 1;
    }
    //Levensthein Algorithm ����
    for (int r = 1; r <= n; r++) {
        for (int c = 1; c <= m; c++) {
            if (ans[r] == sol[c] || (ans[r] == 'i' && (sol[c] == 'j' || sol[c] == 'l')) || (ans[r] == 'v' && sol[c] == 'w'))
                dp[r][c] = dp[r - 1][c - 1];
            else {
                dp[r][c] = min(min(dp[r - 1][c], dp[r][c - 1]), dp[r - 1][c - 1]) + 1;
            }
        }
    }

    return dp[n][m];
}

void main() {
    cin >> n >> m;
    dp.resize(n + 1);
    for (int i = 0; i < n + 1; i++)
        dp[i].resize(m + 1);
    string str_ans, str_sol;
    cin >> str_ans; cin >> str_sol;
    int ret = solution(str_ans, str_sol);
    cout << ret;
}