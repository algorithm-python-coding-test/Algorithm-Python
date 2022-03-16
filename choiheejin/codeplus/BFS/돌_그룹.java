// https://www.acmicpc.net/problem/12886
// BFS인 이유: 전의 변경이 다음의 변경에 영향을 주기 떄문
// 최소 비용을 구하지는 않기 때문에 DFS로 풀 수도 있음
// checked를 map 형태로!
// 소요 시간 : 892ms
package choiheejin.codeplus.BFS;

import java.util.*;

public class 돌_그룹 {

    static Set<String> checked = new HashSet<>();;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] start = new int[3];
        start[0] = sc.nextInt();
        start[1] = sc.nextInt();
        start[2] = sc.nextInt();
        Arrays.sort(start);

        if ((start[0] + start[1] + start[2]) % 3 != 0) {
            System.out.println(0);
            return;
        }
        Deque<int[]> q = new ArrayDeque<>();

        q.add(start);
        checked.add(start[0] + " " + start[1] + " " + start[2]);
        while (!q.isEmpty()) {
            int[] curr = q.removeFirst();
            if (curr[0] == curr[1] && curr[1] == curr[2]) {
                System.out.println(1);
                return;
            }

            // A < B < C
            int a = curr[0];
            int b = curr[1];
            int c = curr[2];

            // 2개가 다른 경우 1 2 2 or 1 1 2
            if (a < b) {
                int nextB = b - a;
                int nextA = a * 2;
                int[] next = new int[] { nextA, nextB, c };
                Arrays.sort(next);
                if (!checked.contains(next[0] + " " + next[1] + " " + next[2])) {
                    checked.add(next[0] + " " + next[1] + " " + next[2]);
                    q.add(next);
                }
            }
            if (b < c) {
                int nextC = c - b;
                int nextB = b * 2;
                int[] next = new int[] { a, nextB, nextC };
                Arrays.sort(next);
                if (!checked.contains(next[0] + " " + next[1] + " " + next[2])) {
                    checked.add(next[0] + " " + next[1] + " " + next[2]);
                    q.add(next);
                }
            }
            if (a < c) {
                int nextC = c - a;
                int nextA = a * 2;
                int[] next = new int[] { nextA, b, nextC };
                Arrays.sort(next);
                if (!checked.contains(next[0] + " " + next[1] + " " + next[2])) {
                    checked.add(next[0] + " " + next[1] + " " + next[2]);
                    q.add(next);
                }
            }
        }
        System.out.println(0);
    }
}
