#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> mass;

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		mass.push_back(x);
	}

	int cnt = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (mass[i] != mass[j])
				cnt++;
		}
	}

	cout << cnt;
}

/*
int n, m;
// 1���� 10������ ���Ը� ���� �� �ִ� �迭
int arr[11];

int main(void) {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		arr[x] += 1;
	}

	int result = 0;

	// 1���� m������ �� ���Կ� ���Ͽ� ó��
	for (int i = 1; i <= m; i++) {
		n -= arr[i]; // ���԰� i�� �������� ����(A�� ������ �� �ִ� ����) ����
		result += arr[i] * n; // B�� �����ϴ� ����� ���� �����ֱ�
	}

	cout << result << '\n';
}
*/