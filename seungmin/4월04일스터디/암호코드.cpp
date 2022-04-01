#include <string>
#include <iostream>
using namespace std;

int dp[5005];

int main() {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    string str;
    cin >> str;

    dp[0] = 1;
    int n1 = str[0] - '0';
    if (n1 == 0) {
        cout << 0 << '\n';
        return 0;
    }

    int n2 = str[1] - '0';
    int num = 10 * n1 + n2;
    if (num == 0 || (num > 26 && n2 == 0)) {
        cout << 0 << '\n';
        return 0;
    } 
    else if (num > 10 && num <= 26 && num != 20) {
        dp[1] = 2;
    }
    else if (num == 10 || num == 20) {
        dp[1] = 1;
    }
    else if (num > 26) {
        dp[1] = dp[0];
    }

    for (int i = 2; i < str.size(); i++) {
        n1 = str[i - 1] - '0';
        n2 = str[i] - '0';
        num = 10 * n1 + n2;
        // 00,30,40,50,60,70,80,90�� ���⼭ �ɷ���
        if (num == 0 || (num > 26 && n2 == 0)) {
            cout << 0 << '\n';
            return 0;
        }
        // 11~19, 21~26 �̶�� �� ���ĺ�(A~J)�� �̾���� ��� + �ϳ��� ���ĺ�(K~Z)�� ���� ���
        else if (num > 10 && num <= 26 && num != 20) {
            dp[i] = (dp[i - 2] + dp[i - 1]) % 1000000;
        }
        // 10�̳� 20�̸� �ϳ��� ���ĺ�(J�� T)�� ���� ���
        else if (num == 20 || num == 10) {
            dp[i] = dp[i - 2];
        }
        // 01,02,,...09 �� 1~9�� ���ĺ� �ϳ��� ���� ���
        else if (num < 10) {
            dp[i] = dp[i - 1];
        }
        // 26���� Ŀ�� �� ���ڿ� �ش��ϴ� ���ĺ� �ΰ��� �̾���� ���
        else if (num > 26) {
            dp[i] = dp[i - 1];
        }
    }
    cout << dp[str.size() - 1] << '\n';

    return 0;
}
