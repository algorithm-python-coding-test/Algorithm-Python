#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9

using namespace std;

int T, N;
int graph[125][125], d[125][125];

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

int main()
{
	cin >> T;
	vector<int> ret;
	//�׽�Ʈ ���̽� Ƚ����ŭ �ݺ�
	for (int cnt = 0; cnt < T; cnt++)
	{
		cin >> N;
		//�� ���� �Է�
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> graph[i][j];
		//�ִ� �Ÿ��� ��� �������� �ʱ�ȭ
		for (int i = 0; i < N; i++)
			fill(d[i], d[i] + 125, INF);
		//���� ��ġ ����
		int x = 0, y = 0;
		//���ͽ�Ʈ�� �˰����� ����ϱ� ���� �켱���� ť ���
		//(-�Ÿ�, {��ġ�� x, y})
		priority_queue < pair<int, pair<int, int>>> pq;
		pq.push({ -graph[x][y], {0, 0} });
		d[x][y] = graph[x][y];

		while (!pq.empty())
		{
			int dist = -pq.top().first;
			int x = pq.top().second.first;
			int y = pq.top().second.second;
			pq.pop();
			//ó���� ���� �ִ� �����̶�� ����
			if (d[x][y] < dist) continue;
			//������ ������ Ȯ��
			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				//���� ������ ����� ��� ����
				if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
				int cost = dist + graph[nx][ny];
				if (cost < d[nx][ny])
				{
					d[nx][ny] = cost;
					pq.push({ -cost, {nx, ny} });
				}
			}
		}

		ret.push_back(d[N - 1][N - 1]);
	}

	//��� ���
	for (int i = 0; i < T; i++)
	{
		cout << ret[i] << '\n';
	}
}