// 처음에는 다익스트라라고 판단했고, 
// 두번 이상 함정을 방문하는 경우는 같은 노드에서만 발생한다고 판단해서 
// 함정을 두번 이상 방문 했을 경우의 함정을 대표하는 가상의 노드를 추가함
// 그러나 예제 2 케이스부터 반례였음 (1 -> 2 -> 3 -> 2)
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
