/*
* Problem : �Ÿ��α� Ȯ���ϱ�
* �� ���� ���� ��� �����ڰ� ����ư �Ÿ� 2 �ʰ��� ��ġ�ϴ��� �˻�
* 5���� 5x5���� ����
* vector<vector<string>> -> vector<string> : �� ���� ���� (P : ������, O : �� ���̺�, X : ��Ƽ��)
*
* �ϳ��� ���ǿ� ���� �˰����� ¥��, ������ ������ �׽�Ʈ���̽��� ������
* 
* >>�ּ� 0.02ms, 3.66MB�� ����
* >>�ִ� 0.02ms, 4.34MB�� ����
*/

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<string> room;
int graph[5][5];	//�� ���̺� = 0, ������ : 1, ��Ƽ�� = 2
queue<pair<int, int>> pos;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

int main()
{
	//�ϳ��� ���ǿ� ���� ���� �Է�
	for (int i = 0; i < 5; i++)
	{
		string temp;
		cin >> temp;
		room.push_back(temp);
	}
	//���ڿ��� �־��� ������ �ٷ�� ������ �������·� ��ȯ
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
		{
			if (room[i][j] == 'O')
				graph[i][j] = 0;
			//�ش� ĭ�� ����� �ִٸ�
			else if (room[i][j] == 'P')
			{
				graph[i][j] = 1;
				pos.push({ i, j });		//����� ��ġ ����
			}
			else
				graph[i][j] = 2;
		}
	//BFS �˰��� ����
	while (!pos.empty())
	{
		pair<int, int> person = pos.front();
		pos.pop();
		//������� ����ư �Ÿ��� 2 �ʰ��̾�� �ϹǷ�
		//�� ������� �� ĭ���� ����� �־�� �Ѵ�.
		for (int i = 0; i < 4; i++)
		{
			int nx = person.first + dx[i];
			int ny = person.second + dy[i];
			//���� ����� �ʴ� ��쿡��
			if (0 <= nx && 0 <= ny && nx < 5 && ny < 5)
			{
				//��ĭ�� ����� �ִ°��
				if (graph[nx][ny] == 1)
				{
					//0�� ��ȯ�ϰ� ����
					cout << 0;
					return 0;
				}
				//��ĭ�� ��Ƽ���̶�� Ž���� ����
				else if (graph[nx][ny] == 2) continue;
				else
					//��ĭ�� ��ĭ�̶�� ������� ���縦 ���� 1 ����
					graph[nx][ny] = 1;
			}
		}
	}
	//�˻��� ��� ��ģ�ٸ� 1�� ��ȯ
	cout << 1;
	return 0;
}

//���α׷��ӽ� ����� �ڵ�
//#include <string>
//#include <vector>
//#include <queue>
//
//using namespace std;
//
//void Initialize(vector<string> part);
//
//int graph[5][5];
//queue<pair<int, int>> pos;
//
//int dx[] = { -1, 0, 1, 0 };
//int dy[] = { 0, 1, 0, -1 };
//
//vector<int> solution(vector<vector<string>> places) {
//	vector<int> answer;
//
//	for (int i = 0; i < 5; i++)
//	{
//		Initialize(places[i]);
//		bool isPossible = true;
//		while (!pos.empty() && isPossible)
//		{
//			pair<int, int> person = pos.front();
//			pos.pop();
//
//			for (int i = 0; i < 4; i++)
//			{
//				int nx = person.first + dx[i];
//				int ny = person.second + dy[i];
//
//				if (0 <= nx && 0 <= ny && nx < 5 && ny < 5)
//				{
//					if (graph[nx][ny] == 1)
//					{
//						isPossible = false;
//						break;
//					}
//					else if (graph[nx][ny] == 2) continue;
//					else
//						graph[nx][ny] = 1;
//				}
//			}
//		}
//		if (isPossible) answer.push_back(1);
//		else
//			answer.push_back(0);
//	}
//	return answer;
//}
//
////�� �׽�Ʈ���̽��� ����� ������ �ʱ�ȭ�ϴ� �Լ�
//void Initialize(vector<string> part)
//{
//	pos = queue<pair<int, int>>();
//	for (int i = 0; i < 5; i++)
//		for (int j = 0; j < 5; j++)
//		{
//			if (part[i][j] == 'O')
//				graph[i][j] = 0;
//			else if (part[i][j] == 'P')
//			{
//				graph[i][j] = 1;
//				pos.push({ i, j });
//			}
//			else
//				graph[i][j] = 2;
//		}
//}