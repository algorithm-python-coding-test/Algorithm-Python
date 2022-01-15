#include <iostream>
#define INF 1e9		//���Ѵ��� �Ÿ�

using namespace std;

int N, M;
int graph[501][501];

int main()
{
	cin >> N >> M;

	//�ִ� �Ÿ��� ��� �������� �ʱ�ȭ
	for (int i = 0; i < 501; i++)
	{
		fill(graph[i], graph[i] + 501, INF);
	}
	//�ڱ��ڽ����� ���� ��δ� 0���� �ʱ�ȭ
	for (int i = 1; i <= N; i++)
	{
		graph[i][i] = 0;
	}
	//�Է¿� ���� ��θ� �߰�
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a][b] = 1;
	}
	//�÷��̵� ���� �˰����� �����Ͽ� �ִܰ�� ����
	for (int k = 1; k <= N; k++)
	{
		for (int a = 1; a <= N; a++)
		{
			for (int b = 1; b <= N; b++)
			{
				graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b]);
			}
		}
	}

	int ret = 0;
	//�� �л����� �� �� ���� �������� üũ
	for (int i = 1; i <= N; i++)
	{
		int cnt = 0;
		for (int j = 1; j <= N; j++)
		{
			if (graph[i][j] != INF || graph[j][i] != INF)
			{
				cnt += 1;
			}
		}
		//��� �л����� ���� �����ϸ� ��Ȯ�� ������ ���� ������
		if (cnt == N) ret += 1;
	}

	cout << ret;
}