#include <iostream>

using namespace std;

//���� �Լ� ����
void Initialize();
void Turn_Left();

//�Էµ� ���� ����
int size_y, size_x;
int charactor[3];		//0 : y��ǥ, 1 : x��ǥ, 2 : ���� 
int map[50][50];

//���� ���� ����
int visited[50][50];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };	//���ʹ������ ccw

int main()
{
	//���� �ʱ�ȭ
	Initialize();
	//�˰��� ����� ������ ����
	int cnt_ret = 1;
	//�˰��� ���� ����
	int cnt_turn = 0;

	while (1)
	{
		//�������� ȸ��
		Turn_Left();
		cnt_turn++;
		//���� ��ġ �ĺ� ���
		int next_y = charactor[0] + dy[charactor[2]];
		int next_x = charactor[1] + dx[charactor[2]];
		//�� �� �ִ� ���� && �湮���� ���� �����̸�
		if (map[next_y][next_x] != 1 && visited[next_y][next_x] == 0)
		{
			//�湮 ���
			visited[next_y][next_x] = 1;
			//ĳ���� �̵�
			charactor[0] = next_y;
			charactor[1] = next_x;
			//�湮 ī��Ʈ++
			cnt_ret++;
			//ȸ�� Ƚ�� �ʱ�ȭ
			cnt_turn = 0;
			continue;
		}

		//�� ������ ��� ���Ҵٸ�
		if (cnt_turn == 4)
		{
			//�ڷ� ���� ���
			int next_y = charactor[0] - dy[charactor[2]];
			int next_x = charactor[0] - dx[charactor[2]];
			//���� ������ �� �� �ִ� �����̶��
			if (map[next_y][next_x] != 1)
			{
				//ĳ���� �̵�
				charactor[0] = next_y;
				charactor[1] = next_x;
				//ȸ�� Ƚ�� �ʱ�ȭ
				cnt_turn = 0;
			}
			else break;
		}
	}
	cout << cnt_ret;
}

void Initialize()
{
	cin >> size_y >> size_x;

	for (int i = 0; i < 3; i++)
	{
		int char_info;
		cin >> char_info;
		charactor[i] = char_info;
	}

	for (int y = 0; y < size_y; y++)
		for (int x = 0; x < size_x; x++)
		{
			int tile_info;
			cin >> tile_info;
			map[y][x] = tile_info;
		}

	visited[charactor[0]][charactor[1]] = 1;
}

void Turn_Left()
{
	charactor[2] += 1;
	if (charactor[2] == 4) charactor[2] = 0;
}

/*
* ���� ��ġ���� ���� ������ �������� ���� ������� ccw�� �̵����� ����
* �� �̻� ������ �� ���������� �湮�� ĭ�� �� ���
*/