package choiheejin.kakao_internship_2021.answer;

import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;

public class 미로탈출_복습 {

    // 인접행렬
    int[][] graph = new int[1001][1001];

    // [노드 번호][그래프 상태(bit marking)]
    boolean[][] visited = new boolean[1001][1 << 10];

    public int solution(int n, int start, int end, int[][] roads, int[] traps) {

        // 인접행렬 채우기
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < n + 1; j++) {
                if (i == j)
                    graph[i][j] = 0;
                else
                    graph[i][j] = Integer.MAX_VALUE;
            }
        }
        for (int[] road : roads) {
            int P = road[0], Q = road[1], S = road[2];
            if (graph[P][Q] > S)
                graph[P][Q] = S;
        }

        // [노드, 상태, 비용]
        PriorityQueue<int[]> pq = new PriorityQueue<>(((o1, o2) -> o1[2] - o2[2]));
        pq.add(new int[] { start, 0, 0 });

        return dijkstra(pq, traps, end, n);
    }

    private int dijkstra(PriorityQueue<int[]> pq, int[] traps, int end, int n) {
        while (!pq.isEmpty()) {
            int[] curr = pq.poll();
            int node = curr[0], state = curr[1], cost = curr[2];

            // 목적지라면 리턴
            if (node == end)
                return cost;

            // 이미 방문한 노드라면 패스
            if (visited[node][state]) {
                continue;
            }

            // 방문 처리
            visited[node][state] = true;

            // 현재 노드와 켜져있는 함정 관리, state 업데이트
            boolean currTrapped = false;
            List<Integer> trapped = new ArrayList<>();

            for (int i = 0; i < traps.length; i++) {
                // 해당 함정이 켜져있는 상태라면
                if ((state & 1 << i) != 0) {
                    // 현재 노드가 해당 함정이라면
                    if (traps[i] == node) {
                        // 함정 끄기
                        state &= ~(1 << i);
                        // 현재 노드가 해당 함정이 아니라면
                    } else {
                        trapped.add(traps[i]);
                    }
                    // 해당 함정이 꺼져있고 현재 노드가 이 함정이라면
                } else if (traps[i] == node) {
                    // 함정 켜기
                    state |= (1 << i);
                    trapped.add(traps[i]);
                    currTrapped = true;
                }
            }

            // 연결된 노드를 그래프 상태에 따라 최단 거리 저장
            for (int i = 1; i < n + 1; i++) {
                if (i == node)
                    continue;
                // 다음 노드가 함정인지 아닌지 판단
                boolean nextTrapped = trapped.contains(i);

                if (nextTrapped == currTrapped) {
                    if (graph[node][i] != Integer.MAX_VALUE)
                        pq.add(new int[] { i, state, cost + graph[node][i] });
                } else {
                    if (graph[i][node] != Integer.MAX_VALUE)
                        pq.add(new int[] { i, state, cost + graph[i][node] });
                }
            }
        }
        return Integer.MAX_VALUE;
    }

    public static void main(String[] args) {
        int n = 3;
        int start = 1;
        int end = 3;
        int[][] roads = { { 1, 2, 1 }, { 3, 2, 1 }, { 2, 4, 1 } };
        int[] traps = { 2, 3 };
        new 미로탈출_복습().solution(n, start, end, roads, traps);
    }
}
