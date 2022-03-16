// https://www.acmicpc.net/problem/6087
// BFS인 이유: 특정 노드로 이동 하는 데 필요한 가중치는 거울을 설치하는 것 설치하지 않는 것 1 0 뿐
// 설치해야하는 거울 개수의 최솟값
// 노드 : 그래프에서 r, c값 + 빛이 현재 향하는 방향
// 소요시간 : 
package choiheejin.codeplus.BFS;

import java.util.*;

public class 레이저_통신 {

    static byte[][] graph = new byte[100][100];
    static boolean[][][] checked = new boolean[100][100][4];
    static int[] startC = { -1, -1 };
    static int[] endC = { -1, -1 };
    // 상우하좌
    static int[] dr = { -1, 0, +1, 0 };
    static int[] dc = { 0, +1, 0, -1 };

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int w = sc.nextInt(), h = sc.nextInt();

        sc.nextLine();

        for (int i = 0; i < h; i++) {
            byte[] bytes = sc.nextLine().getBytes();
            for (int j = 0; j < w; j++) {
                graph[i][j] = bytes[j];
                if (bytes[j] == 'C') {
                    if (startC[0] == -1) {
                        startC[0] = i;
                        startC[1] = j;
                    } else {
                        endC[0] = i;
                        endC[1] = j;
                    }
                }
            }
        }

        Deque<int[]> q = new ArrayDeque<>();
        // x, y, 방향, 가중치
        for (int i = 0; i < 4; i++) {
            q.add(new int[] { startC[0], startC[1], i, 0 });
            checked[startC[0]][startC[1]][i] = true;
        }

        int min = Integer.MAX_VALUE;
        while (!q.isEmpty()) {
            int[] curr = q.removeFirst();
            if (curr[0] == endC[0] && curr[1] == endC[1]) {
                min = Math.min(min, curr[3]);
            } else {
                for (int i = 0; i < 4; i++) {
                    int nextR = curr[0] + dr[i];
                    int nextC = curr[1] + dc[i];
                    if (0 > nextR || nextR >= h || 0 > nextC || nextC >= w || graph[nextR][nextC] == '*') {
                        continue;
                    }
                    // 거울을 설치 안해도 되는 경우 - 가중치 0
                    if (i == curr[2]) {
                        if (!checked[nextR][nextC][i]) {
                            checked[nextR][nextC][i] = true;
                            q.addFirst(new int[] { nextR, nextC, i, curr[3] });
                        }

                    }
                    // 180도 방향 제외하고 나머지는 거울 설치 - 가중치 1
                    if (!(curr[0] == startC[0] && curr[1] == startC[1])) {
                        if (i == (curr[2] == 0 ? 3 : curr[2] - 1) || i == (curr[2] == 3 ? 0 : curr[2] + 1)) {
                            if (!checked[nextR][nextC][i]) {
                                checked[nextR][nextC][i] = true;
                                q.add(new int[] { nextR, nextC, i, curr[3] + 1 });
                            }
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
