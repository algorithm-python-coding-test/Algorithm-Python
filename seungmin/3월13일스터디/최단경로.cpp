// ���ͽ�Ʈ�� �˰���
// �ʱ⿡ '������ ~ ����'������ �ִܰ�ΰ��� �ſ� ū ������ �����Ѵ�
// { �ִܰ�ΰ�, ���� } �� ����� ������ min_heap�� ����Ͽ� �ִ� ��ΰ��� �������� �������� �����Ѵ�
// �ʱ⿡ min_heap�� { 0 , ������ } �ϳ��� ������ �ִ� ( ������~������ ��ΰ��� 0 )
// min_heap�� top����� �������� �̾����ִ� {����,����}���� ��� Ȯ���Ͽ�
// top�� ���� ~ ������ ���ļ� ���°� ������ ���� ��κ��� ª�ٸ�, ���� �����ϰ�
// min_heap�� �ֽ�ȭ�� {�ִܰ�ΰ�, ����} ���� �־��ش� (�׸��� �˰��� ��Ұ� �ִ�.)
// min_heap�� ������� ������ �� ��ƾ�� �ݺ��ϸ� �� ������ �ִܰ�ΰ��� ���� �� �ִ�.

// min_heap�� �̿��� ���ͽ�Ʈ�� �˰����� O(E*logE + V) �ð����⵵�� ������
// V�� ��� ������ �ʱ�ȭ�ϴµ� �ɸ��� �ð��̴�
// ��� ������ �����ϱ� ������ E�̰�, �� E�� �ѹ� �����ɶ����� min_heap�� �߰��ȴٸ�
// min_heap�� ���Ľð����� �ִ� logE�� �ҿ�� �� �ִ�.


#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

// �� ������ ����� ���� ���� : { ����� ��, ������ ����ġ }
vector<pair<int, int>> adj[20001];
// ���������� �� ���������� �ִ� ��ΰ�
int d[20001];
// const : INF�� ���� ������ �� ���� ����� �����Ѵ�
// ������ �ִ� 300,000���̰� �� ������ ����ġ�� 10 �����̹Ƿ� ��ΰ��� �ִ� 3e6�� ���� �ʴ´�.
const int INF = 1e9;

int main() {
    
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int v, e;
    cin >> v >> e;
    int st;
    cin >> st;

    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        // ���� u�� v�� �մ� ����, �� ����ġ�� w 
        adj[u].push_back({ v,w });
    }
    // ��� �ִ� ��ΰ��� INF�� �ʱ�ȭ
    fill(d, d + v + 1, INF);
    // { �ִܰŸ� ��, ���� } �� ������ min_heap : �ִܰŸ����� �������� �������� ����
    priority_queue<pair<int, int>> pq;
    // ������ st�� �ִ� �Ÿ����� 0
    d[st] = 0;
    // { st�� �ִܰŸ���, st } �� pq�� ����
    pq.push({ 0,st });

    // pq�� ������� ���� ���� ��� ����
    while (!pq.empty()) {
        // pq�� �ִ� �� �� ���� ���� �ִܰ�ΰ��� ������
        int dist = -pq.top().first;
        int node = pq.top().second;
        pq.pop();

        // dist���� d[node]���� �ٸ��ٸ�, dist�� node������ �ִܰ�ΰ��� �ƴ�
        if (dist != d[node]) continue;

        // node�� ����� ��� �������� ����
        for (int i = 0; i < adj[node].size(); i++) {
            // { node�� ����� ����, ������ ����ġ } �� �޾ƿ�
            pair<int, int> adjacent = adj[node][i];
            // ������ ~ node ~ �� ���Ͽ� ���� ��ΰ�
            // ������ ���� �ִ� ��κ��� ª���� Ȯ���Ѵ�
            if (d[adjacent.first] > adjacent.second + dist) {
                d[adjacent.first] = adjacent.second + dist;
                // �ִ� ��ΰ� ���ŵ� ������ ���� ������ pq�� �ִ´�.
                pq.push({ -d[adjacent.first], adjacent.first });
            }
        }
    }

    for (int i = 1; i <= v; i++) {
        if (d[i] != INF) cout << d[i] << '\n';
        else cout << "INF" << '\n';
    }

    return 0;
}