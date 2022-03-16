// https://www.acmicpc.net/problem/2206
// 벽을 한번만 부술 수 있음 
// 소요 시간: 1028ms
package choiheejin.day3_20;

import java.util.*;

public class 벽_부수고_이동하기 {

    static byte[][] graph = new byte[1000][1000];
    static boolean[][][] checked = new boolean[1000][1000][2];
    static int[] dr = { -1, +1, 0, 0 };
    static int[] dc = { 0, 0, +1, -1 };

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), m = sc.nextInt();
        sc.nextLine();

        // 그래프 채우기
        for (int i = 0; i < n; i++) {
            byte[] bytes = sc.nextLine().getBytes();
            for (int j = 0; j < m; j++) {
                graph[i][j] = bytes[j];
            }
        }

        Deque<int[]> q = new ArrayDeque<>();
        // 로우, 컬럼, 벽을 부쉈는지 안부쉈는지 여부, 거리
        q.add(new int[] { 0, 0, 0, 1 });
        checked[0][0][0] = true;

        int min = Integer.MAX_VALUE;
        while (!q.isEmpty()) {
            int[] curr = q.pop();
            if (curr[0] == n - 1 && curr[1] == m - 1) {
                min = Math.min(min, curr[3]);
            }
            // 벽을 부순 경우
            if (curr[2] == 1) {
                for (int i = 0; i < 4; i++) {
                    int nextR = curr[0] + dr[i];
                    int nextC = curr[1] + dc[i];
                    if (0 <= nextR && nextR < n && 0 <= nextC && nextC < m && 0 <= nextR
                            && graph[nextR][nextC] == '0') {
                        if (!checked[nextR][nextC][1]) {
                            checked[nextR][nextC][1] = true;
                            q.add(new int[] { nextR, nextC, 1, curr[3] + 1 });
                        }
                    }
                }
                // 벽을 아직 부수지 않은 경우
            } else {
                for (int i = 0; i < 4; i++) {
                    int nextR = curr[0] + dr[i];
                    int nextC = curr[1] + dc[i];
                    if (0 <= nextR && nextR < n && 0 <= nextC && nextC < m) {
                        if (graph[nextR][nextC] == '1' && !checked[nextR][nextC][1]) {
                            checked[nextR][nextC][1] = true;
                            q.add(new int[] { nextR, nextC, 1, curr[3] + 1 });
                        } else if (graph[nextR][nextC] == '0' && !checked[nextR][nextC][0]) {
                            checked[nextR][nextC][0] = true;
                            q.add(new int[] { nextR, nextC, 0, curr[3] + 1 });
                        }
                    }
                }
            }
        }
        if (min == Integer.MAX_VALUE) {
            System.out.println(-1);
        } else {
            System.out.println(min);
        }
    }
}