// 비용이 있는 그래프에서의 최단 거리는 다익스트라
// 함정을 거쳐가는 것을 체크할 때에는
// 해당 함정에 대해 양방향 간선이 직접 연결되어있으면
// 두가지 케이스가 있음
// 1. 한번 거쳐서 + 바뀐 그래프로 최단 경로 계산하기
// 2. 두번 거쳐서 + 바뀌지 않은 그래프로 최단 경로 계산하기
// 이외에는 두번 거쳐도 최단 경로가 나올 수 없음
// 양방향 간선이 없으면
// 1. 한번 거쳐서 + 바뀐 그래프로 최단 경로 계산
// 두 노드가 양방향으로 연결되어있는지, 특정 노드로 들어오는 간선들을 특정하려면 인접 리스트보다는 인접행렬이 나음

package choiheejin.kakao_internship_2021.first;

import java.util.Arrays;
import java.util.PriorityQueue;

public class 미로탈출 {
    public int solution(int n, int start, int end, int[][] roads, int[] traps) {
        int[][] graph = new int[1000][1000];
        // 그래프 그리기
        for (int[] road : roads) {
            graph[road[0]][road[1]] = road[2];
        }

        // trap과 양방향으로 연결된 노드가 있다면
        // 해당 노드와 (노드 -> trap) * 2 + (trap -> 노드) 비용이 걸리는 가상의 노드를 하나 더 만들고
        // trap과 똑같이 연결하기 (trap은 아님)
        for (int trap : traps) {
            for (int i = 1; i < n + 1; i++) {
                if (graph[trap][i] > 0 && graph[i][trap] > 0) {
                    graph[i][n + 1] = graph[i][trap] * 2 + graph[trap][i];
                    graph[n + 1] = graph[trap].clone();
                    n++;
                }
            }
        }

        int[] dist = new int[n + 1];
        for (int i = 0; i < n + 1; i++) {
            dist[i] = Integer.MAX_VALUE;
        }

        PriorityQueue<int[]> q = new PriorityQueue<>((o1, o2) -> Integer.compare(o1[1], o2[1]));
        int[] startNode = { start, 0 };
        q.offer(startNode);

        dist[start] = 0;

        while (!q.isEmpty()) {
            int[] curNode = q.poll();

            if (dist[curNode[0]] < curNode[1]) {
                continue;
            }

            // 만약 해당 노드가 함정이라면
            boolean isTrap = Arrays.stream(traps).anyMatch(i -> i == curNode[0]);
            if (isTrap) {
                // 그래프 바꾸기
                for (int i = 0; i < n + 1; i++) {
                    int temp = graph[curNode[0]][i];
                    graph[curNode[0]][i] = graph[i][curNode[0]];
                    graph[i][curNode[0]] = temp;
                }
            }

            for (int i = 0; i < n + 1; i++) {
                if (graph[curNode[0]][i] > 0 && dist[i] > curNode[1] + graph[curNode[0]][i]) {
                    dist[i] = curNode[1] + graph[curNode[0]][i];
                    int[] node = { i, dist[i] };
                    q.offer(node);
                }
            }
        }
        return dist[end];
    }

    public static void main(String[] args) {
        int n = 4;
        int start = 1;
        int end = 4;
        int[][] roads = { { 1, 2, 1 }, { 3, 2, 1 }, { 2, 4, 1 } };
        int[] traps = { 2, 3 };
        System.out.println(new 미로탈출().solution(n, start, end, roads, traps));

    }
}
