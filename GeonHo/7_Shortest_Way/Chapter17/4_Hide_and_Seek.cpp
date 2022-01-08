#include <iostream>
#include <queue>
#define INF 1e9

using namespace std;

int N, M;
int d[20001];
vector<int> graph[20001];

int main()
{
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		//����� �׷��� ����
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	//�ִܰŸ� ���̺� �ʱ�ȭ
	for (int i = 0; i <= N; i++)
		d[i] = INF;
	//���ͽ�Ʈ�� �˰����� ����ϱ� ���� �غ�
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, 1 });		//dist, number
	d[1] = 0;				//���������� �Ÿ��� 0
	//���ͽ�Ʈ�� �˰��� ����
	while (!pq.empty())
	{
		int dist = -pq.top().first;
		int now = pq.top().second;
		pq.pop();
		if (d[now] < dist) continue;
		for (int i = 0; i < graph[now].size(); i++)
		{
			int cost = dist + 1;
			if (cost < d[graph[now][i]])
			{
				d[graph[now][i]] = cost;
				pq.push({ -cost, graph[now][i] });
			}
		}
	}

	//���ͽ�Ʈ�� �˰����� ���� ������ �Ÿ��� �̿��Ͽ�
	//���� �갣 ��ȣ, �ִ� �Ÿ�, ���� �Ÿ��� �갣 ���� ���
	int maxNode = 0;
	int maxDist = 0;
	vector<int> result;

	for (int i = 1; i <= N; i++)
	{
		if (maxDist < d[i])
		{
			maxNode = i;
			maxDist = d[i];
			result.clear();
			result.push_back(maxNode);
		}

		else if (maxDist == d[i])
			result.push_back(i);
	}

	cout << maxNode << ' ' << maxDist << ' ' << result.size();
}