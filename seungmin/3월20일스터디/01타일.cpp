#include <iostream>
using namespace std;

int d[1000001];
int divide = 15746;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    
    d[1] = 1;
    d[2] = 2;
    // d[i-1]�� 1Ÿ���� ���̴� ���
    // d[i-2]�� 00Ÿ���� ���̴� ��� (11Ÿ���� ���̴� �� d[i-1]�� 1Ÿ�� ���̴� �Ϳ� ���Ե�!!!)
    for (int i = 3; i <= n; i++) {
        d[i] = (d[i - 2] + d[i - 1]) % divide;
    }
    cout << d[n] % divide << '\n';

    return 0;
}