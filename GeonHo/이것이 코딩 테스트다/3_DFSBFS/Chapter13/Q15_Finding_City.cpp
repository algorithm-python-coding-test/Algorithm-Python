#include <iostream>
#include <queue>

using namespace std;
//����� ���� �ʱ�ȭ
int N = 0, M = 0, K = 0, X = 0;
//�Ÿ� ������ ���� �迭
vector<int> graph[300001];
//�ִ� �Ÿ� ������ ���� �迭
//�湮���� ���� ������ �Ÿ��� -1�� ����
vector<int> d(300001, -1);

int main()
{
	//N, M, K, X �Է�
	cin >> N >> M >> K >> X;
	//��� ���� ���� �Է�
	for (int i = 0; i < M; i++)
	{
		int from, to;
		cin >> from >> to;
		graph[from].push_back(to);
	}
	//��� ������ �Ÿ��� 0
	d[X] = 0;
	//��� �������� �� ���ñ����� �Ÿ��� �����ϴ� �����̹Ƿ� BFS�� ���
	queue<int> q;
	q.push(X);
	while (!q.empty())
	{
		//python�� popleft�� ����� c++���� �����ϴ� ��
		int now = q.front();
		q.pop();
		for (int i = 0; i < graph[now].size(); i++)
		{
			int next = graph[now][i];
			//d[] == -1�̸� �ѹ��� �湮���� ���� ���� �̹Ƿ� �Ÿ� ����
			if (d[next] == -1)
			{
				d[next] = d[now] + 1;
				q.push(next);
			}
		}
	}
	//�ִ� �Ÿ��� K�� ���� ��ȣ�� ������������ ���
	bool isPossible = false;
	for (int i = 1; i <= N; i++)
	{
		if (d[i] == K)
		{
			cout << i << '/n';
			isPossible = true;
		}
	}
	//�ִ� �Ÿ��� K�� ���ð� ������� -1 ���
	if (!isPossible) cout << -1;
}