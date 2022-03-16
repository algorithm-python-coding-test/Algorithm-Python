// dfs가 아니라 브루트포스임
// 왜? 방문한 노드도 경우의수를 처리하고 나면 방문했던 것을 취소해줘야하기때문
// 모든 브루트포스는 경우를 처리해주면 원래로 바꿔줘야한다.
package choiheejin.codeplus.브루트포스.재귀;

import java.util.*;

public class 테트로미노 {
    static int[][] a;
    static boolean[][] c;
    static int n, m;
    static int[] dx = { 0, 0, 1, -1 };
    static int[] dy = { 1, -1, 0, 0 };
    static int ans = 0;

    static void go(int x, int y, int sum, int cnt) {
        if (cnt == 4) {
            if (ans < sum)
                ans = sum;
            return;
        }
        if (x < 0 || x >= n || y < 0 || y >= m)
            return;
        if (c[x][y])
            return;
        c[x][y] = true;
        for (int k = 0; k < 4; k++) {
            go(x + dx[k], y + dy[k], sum + a[x][y], cnt + 1);
        }
        c[x][y] = false;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        a = new int[n][m];
        c = new boolean[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[i][j] = sc.nextInt();
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                go(i, j, 0, 0);
                if (j + 2 < m) {
                    int temp = a[i][j] + a[i][j + 1] + a[i][j + 2];
                    if (i - 1 >= 0) {
                        int temp2 = temp + a[i - 1][j + 1];
                        if (ans < temp2)
                            ans = temp2;
                    }
                    if (i + 1 < n) {
                        int temp2 = temp + a[i + 1][j + 1];
                        if (ans < temp2)
                            ans = temp2;
                    }
                }
                if (i + 2 < n) {
                    int temp = a[i][j] + a[i + 1][j] + a[i + 2][j];
                    if (j + 1 < m) {
                        int temp2 = temp + a[i + 1][j + 1];
                        if (ans < temp2)
                            ans = temp2;
                    }
                    if (j - 1 >= 0) {
                        int temp2 = temp + a[i + 1][j - 1];
                        if (ans < temp2)
                            ans = temp2;
                    }
                }
            }
        }
        System.out.println(ans);
    }
}
