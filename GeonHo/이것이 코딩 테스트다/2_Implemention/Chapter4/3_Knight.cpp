#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string position;
//2 1 11 10 8 7 5 4�� ������ �̵����� �˻�
int dx[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int dy[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };

int main()
{
	cin >> position;

	int cnt = 0;

	int x = (int)position[0] - 'a' + 1;
	int y = (int)position[1] - '0';

	for (int i = 0; i < 8; i++)
	{
		//���� ��ǥ ���
		int x_next = x + dx[i];
		int y_next = y + dy[i];

		//���� ��ġ�� ���带 ����� ī���� x
		if (x_next < 1 || x_next > 8 || y_next < 1 || y_next > 8) continue;

		cnt++;
	}

	cout << "Possible case is : " << cnt;
}

/*
* ����Ʈ�� �������� ������ dx, dy���� ����
* ����Ʈ�� �������� 2�ú��� ccw�� �̵�
* ����Ʈ�� ���� ���� ��ġ�� ���� ���ο� ������ cnt++
* ����Ʈ�� ���� ���� ��ġ�� ���带 ����� continue
*/