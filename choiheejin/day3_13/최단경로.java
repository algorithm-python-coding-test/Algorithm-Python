// 인접 리스트로 그래프 그린 후
// 다익스트라 수행 
package choiheejin.day3_13;

import java.util.*;

public class 최단경로 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int v = sc.nextInt();
        int e = sc.nextInt();
        sc.nextLine();
        int start = sc.nextInt();
        sc.nextLine();

        // 인접리스트
        List<List<int[]>> graph = new ArrayList<>();
        for (int i = 0; i < v + 1; i++) {
            graph.add(new ArrayList<>());
        }
        for (int i = 1; i <= e; i++) {
            int s = sc.nextInt();
            int d = sc.nextInt();
            int c = sc.nextInt();
            sc.nextLine();
            graph.get(s).add(new int[] { d, c });
        }

        // 다익스트라
        int[] costs = new int[v + 1];
        for (int i = 1; i <= v; i++) {
            costs[i] = Integer.MAX_VALUE;
        }
        PriorityQueue<int[]> pq = new PriorityQueue<>((o1, o2) -> o1[1] - o2[1]);
        pq.offer(new int[] { start, 0 });
        costs[start] = 0;
        while (!pq.isEmpty()) {
            int[] curr = pq.poll();
            if (curr[1] > costs[curr[0]]) {
                continue;
            }
            for (int i = 0; i < graph.get(curr[0]).size(); i++) {
                int[] next = graph.get(curr[0]).get(i);
                if (curr[1] + next[1] < costs[next[0]]) {
                    costs[next[0]] = curr[1] + next[1];
                    pq.offer(new int[] { next[0], curr[1] + next[1] });
                }
            }
        }

        for (int i = 1; i <= v; i++) {
            if (costs[i] == Integer.MAX_VALUE) {
                System.out.println("INF");
            } else {
                System.out.println(costs[i]);
            }
        }
    }
}
