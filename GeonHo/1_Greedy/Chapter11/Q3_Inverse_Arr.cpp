#include <iostream>

using namespace std;

string str;

int main()
{
	cin >> str;

	float cnt_change = 0;
	char lastLetter = str[0];

	for (int i = 1; i < str.length(); i++)
	{
		if (str[i] == '0' && lastLetter == '1')
		{
			lastLetter = '0';
			cnt_change++;
		}
		else if (str[i] == '1' && lastLetter == '0')
		{
			lastLetter = '1';
			cnt_change++;
		}
	}

	cout << ceil(cnt_change / 2) << endl;
}

/*
* ���ӵ� ���ڸ� ��� �ѹ��� �����°��� �ּ� ������ �������� �׸��� �˰��� ���
* 0�� 1�� ����� ���� ��, ���� �ϸ� �ᱹ �迭�� ���´� ��������������...
* �� -> �� && �� -> ���� �����Ǵ� ������ count
* �����Ǵ� ��� ������ ���� �� count /2 �Ͽ� �ּ� ���� Ƚ�� ���
*/