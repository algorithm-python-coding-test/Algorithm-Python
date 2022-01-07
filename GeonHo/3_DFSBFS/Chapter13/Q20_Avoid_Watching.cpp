#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
char graph[6][6];
vector<pair<int, int>> teachers;	//�������� ��ġ�� ����
vector<pair<int, int>> spaces;		//������� ��ġ�� ����

bool watch(int x, int y, int direction);	//�����¿�� �����ϴ� �Լ�	true : �л��߰�
bool process();								//���� �� ó���� �ϴ� �Լ�	true : �߰ߵ� ��찡 ����

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			char temp;
			cin >> temp;
			graph[i][j] = temp;

			if (temp == 'T') teachers.push_back({ i, j });	//�������� �ִ� ��� �ش� ��ġ�� ����
			if (temp == 'X') spaces.push_back({ i, j });	//������� �ִ� ��� �ش� ��ġ�� ����
		}
	}

	bool isPossible = false;
	
	//spaces.size()ũ���� �迭���� 3���� ���Ҹ� ���� ����
	//spaces.size()ũ���� bool �迭�� ���� �� 3���� ���Ҹ� true�� �ʱ�ȭ �������� false
	//���Ŀ� next_permutation�� �̿��� ������ �����Ͽ� ������ ����
	vector<bool> binary(spaces.size());		//spaces.size()ũ���� bool�迭 ����
	fill(binary.end() - 3, binary.end(), true);		//bool�迭�� ������ �� ���Ҹ� true�� �ʱ�ȭ
	do
	{
		//��ֹ� ����
		for (int i = 0; i < spaces.size(); i++)
		{
			if (binary[i])
			{
				int x = spaces[i].first;
				int y = spaces[i].second;
				graph[x][y] = 'O';
			}
		}
		//������ ��ֹ��� ��� ������ ���ø� ���� �� �ִ��� �˻�
		if (!process())
		{
			isPossible = true;
			break;
		}
		//������ ��ֹ� ����
		for (int i = 0; i < spaces.size(); i++)
		{
			if (binary[i])
			{
				int x = spaces[i].first;
				int y = spaces[i].second;
				graph[x][y] = 'X';
			}
		}
	} while (next_permutation(binary.begin(), binary.end()));

	if (isPossible) cout << "YES";
	else cout << "NO";
}

bool watch(int x, int y, int direction)
{
	if (direction == 0)
	{
		while (y >= 0)
		{
			if (graph[x][y] == 'S') return true;
			if (graph[x][y] == 'O') return false;
			y -= 1;
		}
	}
	if (direction == 1)
	{
		while (y <= N)
		{
			if (graph[x][y] == 'S') return true;
			if (graph[x][y] == 'O') return false;
			y += 1;
		}
	}
	if (direction == 2)
	{
		while (x >= 0)
		{
			if (graph[x][y] == 'S') return true;
			if (graph[x][y] == 'O') return false;
			x -= 1;
		}
	}
	if (direction == 3)
	{
		while (x <= N)
		{
			if (graph[x][y] == 'S') return true;
			if (graph[x][y] == 'O') return false;
			x += 1;
		}
	}
}
bool process()
{
	for (int i = 0; i < teachers.size(); i++)
	{
		int x = teachers[i].first;
		int y = teachers[i].second;
		for (int i = 0; i < 4; i++)
		{
			if (watch(x, y, i)) return true;
		}
	}

	return false;
}