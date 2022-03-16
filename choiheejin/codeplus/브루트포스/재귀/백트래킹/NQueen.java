// 브루트 포스로 풀면 : 2**(N*N)
// 다른 방법으로 생각해보면 각각의 행에 퀸이 있을 수 있는 곳의 위치 : N => 모든 행에 퀸이 있을 수 있는 경우의수 : N**N
// 둘다 너무 연산 수가 큼
// 한 열에 퀸이 놓여져있으면 그 열에도 놓을 수가 없는 것을 이용해서
// 각각의 열에도 퀸이 하나, 각각의 행에도 퀸이 하나만 놓아진다면 N!
// 함수를 어떻게 만들 것인가?
// calc(row) : row 행에 퀸을 어디에 놓을지 결정
package choiheejin.codeplus.브루트포스.재귀.백트래킹;

import java.util.*;

public class NQueen {
    static boolean[][] a = new boolean[15][15];
    static int n;
    static int ans = 0;

    static boolean check(int row, int col) {
        // |
        for (int i = 0; i < n; i++) {
            if (i == row)
                continue;
            if (a[i][col]) {
                return false;
            }
        }
        // 왼쪽 위 대각선
        int x = row - 1;
        int y = col - 1;
        while (x >= 0 && y >= 0) {
            if (a[x][y] == true) {
                return false;
            }
            x -= 1;
            y -= 1;
        }
        // /
        x = row - 1;
        y = col + 1;
        while (x >= 0 && y < n) {
            if (a[x][y] == true) {
                return false;
            }
            x -= 1;
            y += 1;
        }
        return true;
    }

    static void calc(int row) {
        if (row == n) {
            ans += 1;
        }
        for (int col = 0; col < n; col++) {
            a[row][col] = true;
            if (check(row, col)) {
                calc(row + 1);
            }
            a[row][col] = false;
        }
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        calc(0);
        System.out.println(ans);
    }
}
