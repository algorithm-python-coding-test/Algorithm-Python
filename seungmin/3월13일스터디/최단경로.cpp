// 다익스트라 알고리즘
// 초기에 '시작점 ~ 정점'까지의 최단경로값을 매우 큰 값으로 저장한다
// { 최단경로값, 정점 } 을 멤버로 가지는 min_heap을 사용하여 최단 경로값을 기준으로 내림차순 정렬한다
// 초기에 min_heap은 { 0 , 시작점 } 하나를 가지고 있다 ( 시작점~시작점 경로값은 0 )
// min_heap의 top요소의 정점에서 이어져있는 {간선,정점}들을 모두 확인하여
// top의 정점 ~ 간선을 거쳐서 가는게 이전에 계산된 경로보다 짧다면, 값을 갱신하고
// min_heap에 최신화된 {최단경로값, 정점} 쌍을 넣어준다 (그리디 알고리즘 요소가 있다.)
// min_heap이 비어있을 때까지 위 루틴을 반복하면 각 정점의 최단경로값을 구할 수 있다.

// min_heap을 이용한 다익스트라 알고리즘은 O(E*logE + V) 시간복잡도를 가진다
// V는 모든 정점을 초기화하는데 걸리는 시간이다
// 모든 간선을 참고하기 때문에 E이고, 각 E가 한번 참조될때마다 min_heap에 추가된다면
// min_heap의 정렬시간으로 최대 logE가 소요될 수 있다.


#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

// 각 정점에 연결된 간선 정보 : { 연결된 점, 간선의 가중치 }
vector<pair<int, int>> adj[20001];
// 시작점에서 각 정점까지의 최단 경로값
int d[20001];
// const : INF는 값을 변경할 수 없는 상수로 지정한다
// 간선이 최대 300,000개이고 각 간선의 가중치는 10 이하이므로 경로값은 최대 3e6을 넘지 않는다.
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
        // 정점 u와 v를 잇는 간선, 그 가중치는 w 
        adj[u].push_back({ v,w });
    }
    // 모든 최단 경로값을 INF로 초기화
    fill(d, d + v + 1, INF);
    // { 최단거리 값, 정점 } 을 저장한 min_heap : 최단거리값을 기준으로 내림차순 정렬
    priority_queue<pair<int, int>> pq;
    // 시작점 st의 최단 거리값은 0
    d[st] = 0;
    // { st의 최단거리값, st } 를 pq에 삽입
    pq.push({ 0,st });

    // pq가 비어있지 않을 동안 계속 실행
    while (!pq.empty()) {
        // pq에 있는 값 중 가장 작은 최단경로값을 가져옴
        int dist = -pq.top().first;
        int node = pq.top().second;
        pq.pop();

        // dist값이 d[node]깂과 다르다면, dist는 node까지의 최단경로값이 아님
        if (dist != d[node]) continue;

        // node에 연결된 모든 간선들을 조사
        for (int i = 0; i < adj[node].size(); i++) {
            // { node와 연결된 정점, 간선의 가중치 } 를 받아옴
            pair<int, int> adjacent = adj[node][i];
            // 시작점 ~ node ~ 를 통하여 가는 경로가
            // 이전에 계산된 최단 경로보다 짧은지 확인한다
            if (d[adjacent.first] > adjacent.second + dist) {
                d[adjacent.first] = adjacent.second + dist;
                // 최단 경로가 갱신된 정점에 대한 정보를 pq에 넣는다.
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