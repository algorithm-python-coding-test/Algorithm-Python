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
    // d[i-1]에 1타일을 붙이는 경우
    // d[i-2]에 00타일을 붙이는 경우 (11타일을 붙이는 건 d[i-1]에 1타일 붙이는 것에 포함됨!!!)
    for (int i = 3; i <= n; i++) {
        d[i] = (d[i - 2] + d[i - 1]) % divide;
    }
    cout << d[n] % divide << '\n';

    return 0;
}