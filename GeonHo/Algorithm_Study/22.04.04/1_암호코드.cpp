//0ms

#include <iostream>

using namespace std;

int dp[5001];

int main() {
	string pw;
	cin >> pw;

	if (pw[0] == '0') {
		cout << 0;
		return 0;
	}

	dp[0] = 1;

	if (pw.length() >= 2) {
		if (pw[1] != '0') dp[1] = dp[0];
		int asci = (pw[0] - '0') * 10 + (pw[1] - '0');
		if (asci <= 26 && asci >= 10) dp[1]++;
	}

	for (int i = 2; i < pw.length(); i++) {
		if (pw[i] != '0') {
			dp[i] = dp[i - 1];
		}

		int asci = (pw[i - 1] - '0') * 10 + (pw[i] - '0');
		if (asci <= 26 && asci >= 10) {
			dp[i] = (dp[i - 2] + dp[i]) % 1000000;
		}
	}

	cout << dp[pw.length() - 1];
}