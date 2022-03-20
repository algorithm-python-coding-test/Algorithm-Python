package choiheejin.socar2;

import java.util.*;

public class no1 {
    static List<List<int[]>> graph = new ArrayList<>();
    static Set<Integer> ans = new HashSet<>();

    public int[] solution(int n, int k, int[][] roads) {
        for (int i = 0; i < n; i++) {
            graph.add(new ArrayList<>());
        }

        for (int[] road : roads) {
            graph.get(road[0]).add(new int[] { road[1], road[2] });
            graph.get(road[1]).add(new int[] { road[0], road[2] });
        }

        PriorityQueue<int[]> q = new PriorityQueue<>((o1, o2) -> o1[1] - o2[1]);
        find(k, q);
        if (ans.size() == 0) {
            return new int[] { -1 };
        }
        int[] answer = new int[ans.size()];
        int i = 0;
        for (int a : ans) {
            answer[i] = a;
            i++;
        }
        Arrays.sort(answer);
        return answer;
    }

    private void find(int k, PriorityQueue<int[]> q) {
        q.offer(new int[] { 0, 0 });
        while (!q.isEmpty()) {
            int[] curr = q.poll();
            System.out.println(curr[0] + " " + curr[1]);
            if (curr[1] != 0 && curr[0] == 0) {
                find(k - curr[1], new PriorityQueue<>((o1, o2) -> o1[1] - o2[1]));
            } else {
                if (curr[1] == k) {
                    ans.add(curr[0]);
                }
                for (int i = 0; i < graph.get(curr[0]).size(); i++) {
                    int[] next = graph.get(curr[0]).get(i);
                    if (curr[1] + next[1] <= k) {
                        q.offer(new int[] { next[0], curr[1] + next[1] });
                    }
                }
            }
        }
    }

    public static void main(String[] args) {
        int n = 6;
        int k = 50;
        int[][] roads = { { 5, 4, 6 }, { 5, 2, 5 }, { 0, 4, 2 }, { 2, 3, 3 }, { 1, 2, 7 }, { 0, 1, 3 } };
        int[] answer = new no1().solution(n, k, roads);
        for (int i = 0; i < answer.length; i++) {
            System.out.print(answer[i] + " ");
        }
        System.out.println();
    }
}
