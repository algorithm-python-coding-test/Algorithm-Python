/*
* problem : �̷� Ż�� (https://programmers.co.kr/learn/courses/30/lessons/81304)
*/

//��� ������ ��ã�� �ϴ°� ���� dijkstra���� �ǽ�... floyd������ �ʿ� ������
//�Ϲ����� dijkstra�� �˰��� ������ O(N^2)�� �䱸. trap�� ���� ó������ �Ѵٸ� �ð��ʰ��� ���ɼ��� ����
//pq�� Ȱ���� ������ dijkstra�� ������� => O(NlogN)
//dijkstra�� ����Ϸ��� graph�� �ϼ��Ǿ�� ���ٵ� trap-node, trap-trap�� ���� ��� ������ ����ȭ �� �� ������?
//=>trap-node�� ���������� trap-trap�� ��쿡 ������ �߻�...
//dijkstra ���� �� graph�� ������Ʈ �Ͽ� �ִܰŸ��� ã�� �� �ִ°�???
//=>�������ϴ�. �׷��� trap���� ����Ǵ� ��츦 ������ ó�����־�� �Ѵ�. => ó������ �ʴ°�� ��ã�� ���� or ���ѷ���
//�ð��� ������ ������ �� ���� ����...

//Solving Time : 1hour 40min + @...

#include <string>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 1e9

using namespace std;

vector<int> trap_info;
int d[1001];
int _size;
int graph[1001][1001];
//trap�ߵ� �Լ�
void activate_trap(int num) {
    for (int i = 1; i <= _size; i++) {
        swap(graph[num][i], graph[i][num]);
    }
}
//priority_queue�� Ȱ���� dijkstra
void dijkstra(int start) {
    priority_queue<pair<int, int>> pq;
    pq.push({ 0, start });
    d[start] = 0;
    while (!pq.empty()) {
        int dist = -pq.top().first;
        int now = pq.top().second;
        bool isTrap = find(trap_info.begin(), trap_info.end(), now) != trap_info.end();
        pq.pop();
        if (d[now] < dist && !isTrap) continue;

        if (isTrap) {
            activate_trap(now);
        }

        for (int i = 1; i <= _size; i++) {
            if (graph[now][i] == INF) continue;
            int cost = dist + graph[now][i];
            if (cost < d[i]) {
                d[i] = cost;
                pq.push({ -cost, i });
            }
        }
    }
}

int solution(int n, int start, int end, vector<vector<int>> roads, vector<int> traps) {
    _size = n;
    //roads�Է��� �ޱ� �� graph �ʱ�ȭ
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            graph[i][j] = INF;
    }
    //dijkstra�� ����ϱ� ���� distance�迭 �ʱ�ȭ
    for (int i = 1; i <= n; i++) d[i] = INF;
    //roads �Է¿� ���� graph�ʱ�ȭ
    for (int i = 0; i < roads.size(); i++) {
        int from, to, cost;
        from = roads[i][0]; to = roads[i][1]; cost = roads[i][2];
        if (graph[from][to] > cost) {
            graph[from][to] = cost;
        }
    }

    trap_info = traps;

    dijkstra(start);

    int answer = d[end];
    return answer;
}