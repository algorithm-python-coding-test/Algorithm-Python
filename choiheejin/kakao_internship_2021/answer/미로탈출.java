// 소요 시간 : 1.19ms ~ 113.93ms
// 인접행렬로 표현
// 다익스트라 사용
// Priority Queue 사용
// 방문 여부는 노드, 함정이 발동됐는지 상태 정보를 넣음
// 노드가 같다고 해도 함정이 발동된 상태와 발동되지 않은 상태는 별도의 기록이기 때문
// visited = [노드][함정 발동 상태]
// PriorrityQueue에는 [비용, 노드, 함정 발동 상태] 정보를 넣을 것
package choiheejin.kakao_internship_2021.answer;

import java.util.HashMap;
import java.util.PriorityQueue;

public class 미로탈출 {

    private final static int MAX_N = 1001;
    private final static int INF = Integer.MAX_VALUE;
    int[][] Graph = new int[MAX_N][MAX_N];

    // 다익스트라 함수
    int dijkstra(int n, int src, int dst, int[] traps) {
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        boolean[][] visited = new boolean[MAX_N][1 << 10];
        // [비용, 노드, 함정 상태]
        pq.add(new int[] { 0, src, 0 });

        while (!pq.isEmpty()) {
            int[] curr = pq.poll();
            // [비용, 노드 ,함정 상태]
            int w = curr[0], u = curr[1], state = curr[2];

            // 목적지가 나오면 리턴
            if (u == dst)
                return w;

            // 방문이 된 노드라면 패스
            if (visited[u][state])
                continue;
            // 방문이 안됐다면 방문 처리
            visited[u][state] = true;

            boolean currTrapped = false;
            // 켜져있는 함정들을 저장한 자료구조
            HashMap<Integer, Boolean> trapped = new HashMap<>();
            for (int i = 0; i < traps.length; i++) {
                int bit = 1 << i;
                // 현재 체크하는 함정이 켜져있는 상태라면
                if ((state & bit) != 0) {
                    // 현재 노드가 함정이라면 비트를 꺼줘야함
                    if (traps[i] == u) {
                        state &= ~bit;
                        // 현재 노드가 함정이 아니라면
                    } else {
                        // 현재 함정을 발동된 상태로 trapped에 넣어둠
                        trapped.put(traps[i], true);
                    }
                    // 함정이 꺼져있다면
                } else {
                    // 현재 노드가 함정이라면 비트를 켜줘야함
                    if (traps[i] == u) {
                        state |= bit;
                        trapped.put(traps[i], true);
                        currTrapped = true;
                    }
                }
            }

            // u와 연결된 노드들의 최단 거리 체크
            for (int v = 1; v <= n; ++v) {
                if (v == u)
                    continue;
                // 연결된 노드가 발동된 함정인지 확인
                boolean nextTrapped = trapped.containsKey(v);
                // 만약 현재 노드의 발동 여부와 연결된 노드의 발동 여부가 같다면?
                if (currTrapped == nextTrapped) {
                    // 연결된 노드가 정말 현재 노드 -> 연결된 노드인지 확인하고
                    if (Graph[u][v] != INF)
                        // PriorityQueue에 최단 거리 넣음
                        // 간선 방향은 바뀌지 않음
                        pq.add(new int[] { w + Graph[u][v], v, state });
                } else {
                    // 연결된 노드가 정말 연결된 노드 -> 현재 노드인지 확인하고
                    if (Graph[v][u] != INF)
                        // PriorityQueue에 최단 거리 넣음
                        // 간선 방향은 바뀌지 않음
                        pq.add(new int[] { w + Graph[v][u], v, state });

                }
            }
        }
        return INF;
    }

    public int solution(int n, int start, int end, int[][] roads, int[] traps) {
        // 인접 행렬
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j)
                    Graph[i][j] = 0;
                else
                    Graph[i][j] = INF;
            }
        }

        // 간선 정보 입력
        for (int[] data : roads) {
            int u = data[0], v = data[1], w = data[2];
            // 두 개의 노드를 연결하는 간선이 여러개 있을 수 있다고 함
            // 여러 개의 간선을 모두 기록할 필요 없이 가장 거리가 짧은 것만 계산해주면 됨
            if (w < Graph[u][v])
                Graph[u][v] = w;
        }
        return dijkstra(n, start, end, traps);
    }
}
