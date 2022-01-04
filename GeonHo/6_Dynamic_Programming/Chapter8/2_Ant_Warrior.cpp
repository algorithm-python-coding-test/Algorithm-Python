#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Initialize();

int N;
vector<int> storage;
vector<int> dp;

int main()
{
	Initialize();

	for (int i = 2; i < N; i++)
	{
		dp[i] = max(dp[i - 1], dp[i - 2] + storage[i]);
	}

	cout << dp[N - 1];
}

void Initialize()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		storage.push_back(x);
		dp.push_back(0);
	}

	dp[0] = storage[0];
	dp[1] = max(storage[0], storage[1]);
}

/*
* i��° â����� �ִ�ġ = max(i-1��° â����� �ִ�ġ, i-2��° â����� �ִ�ġ + i��° â���� �ķ�)
* i-1��° â����� �ִ�ġ : i��° â��� ��Ż���� ����.
* i-2��° â����� �ִ�ġ : i-1��° â��� ��Ż���� �ʰ�, i��° â��� ��Ż��.
* 
* i-1��° â����� �ִ�ġ����, ���� i-1��° â�� ���� �ʾҴٸ� i���� â�� �о ���� �ʳ�?
* >> �׷��� ���� i-2��° â������� �ִ�ġ ��쿡 ���Եȴ�.
*/