// https://www.acmicpc.net/problem/16948
// BFS인 이유: 노드 이동 가중치가 1번으로 동일
// 소요 시간 : 224ms
package choiheejin.codeplus.BFS;

import java.util.*;

public class 데스_나이트 {

    static boolean[][] checked = new boolean[200][200];
    static int[] dr = { -2, -2, 0, 0, +2, +2 };
    static int[] dc = { -1, +1, -2, +2, -1, +1 };

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();
        int r1 = sc.nextInt(), c1 = sc.nextInt(), r2 = sc.nextInt(), c2 = sc.nextInt();

        Deque<int[]> q = new ArrayDeque<>();
        q.add(new int[] { r1, c1, 0 });
        checked[r1][c1] = true;

        while (!q.isEmpty()) {
            int[] curr = q.removeFirst();
            if (curr[0] == r2 && curr[1] == c2) {
                System.out.println(curr[2]);
                return;
            }
            for (int i = 0; i < 6; i++) {
                int nextR = curr[0] + dr[i];
                int nextC = curr[1] + dc[i];
                if (0 <= nextR && nextR < n && 0 <= nextC && nextC < n) {
                    if (!checked[nextR][nextC]) {
                        checked[nextR][nextC] = true;
                        q.add(new int[] { nextR, nextC, curr[2] + 1 });
                    }
                }
            }
        }

        System.out.println(-1);

    }
}
