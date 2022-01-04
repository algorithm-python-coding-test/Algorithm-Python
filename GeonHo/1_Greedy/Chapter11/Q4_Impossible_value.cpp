#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> coin;

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		coin.push_back(x);
	}

	sort(coin.begin(), coin.end());

	int min_value = 1;

	for (int i = 0; i < N; i++)
	{
		if (min_value < coin[i]) break;
		min_value += coin[i];
	}

	cout << min_value;
}

/*
*	//���� �� ���� �ݾ�//
* �׼��� ���� ���� �������� �����س����� �׸��� �˰���
*/
