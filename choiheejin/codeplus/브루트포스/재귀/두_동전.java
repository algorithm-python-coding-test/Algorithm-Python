// 4개의 버튼을 최대 10번 누를 수 있으므로 경우의수는 4**10 = 백만가지 정도
// => 연산 가능
// 함수를 만들기 위해 고민해야할 부분은 동전이나 벽
// 동전의 위치만 바뀌므로 한 동전의 위치, 다른 동전의 위치를 사용해서 구현 가능
// 불가능한 경우: step == 1 or 두 동전이 모두 떨어진 경우
// 정답을 찾은 경우: 두 동전 중에서 하나만 떨어진 경우
// 다음 경우: ><^v
// 핵심: 어떤 정보를 재귀함수로 넘길 것인가? 보드에 대한 정보를 다 넘기면 안됨
// 동전의 위치만 변한다는 점을 이용해서 동전의 위치만 함수의 인수로
package choiheejin.codeplus.브루트포스.재귀;

import java.util.*;

public class 두_동전 {
    static int n, m;
    static char[][] a;
    static final int[] dx = { 0, 0, 1, -1 };
    static final int[] dy = { 1, -1, 0, 0 };

    static int go(int step, int x1, int y1, int x2, int y2) {
        if (step == 11)
            return -1;
        boolean fall1 = false;
        boolean fall2 = false;
        if (x1 < 0 || x1 >= n || y1 < 0 || y1 >= m)
            fall1 = true;
        if (x2 < 0 || x2 >= n || y2 < 0 || y2 >= m)
            fall2 = true;
        if (fall1 && fall2)
            return -1;
        if (fall1 || fall2)
            return step;
        int ans = -1;
        for (int k = 0; k < 4; k++) {
            int nx1 = x1 + dx[k];
            int ny1 = y1 + dy[k];
            int nx2 = x2 + dx[k];
            int ny2 = y2 + dy[k];
            if (0 <= nx1 && nx1 < n && 0 <= ny1 && ny1 < m && a[nx1][ny1] == '#') {
                nx1 = x1;
                ny1 = y1;
            }
            if (0 <= nx2 && nx2 < n && 0 <= ny2 && ny2 < m && a[nx2][ny2] == '#') {
                nx2 = x2;
                ny2 = y2;
            }

            int temp = go(step + 1, nx1, ny1, nx2, ny2);
            if (temp == -1)
                continue;
            if (ans == -1 || ans > temp) {
                ans = temp;
            }
        }
        return ans;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        a = new char[n][m];
        int x1, y1, x2, y2;
        x1 = y1 = x2 = y2 = -1;
        for (int i = 0; i < n; i++) {
            a[i] = sc.next().toCharArray();
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 'o') {
                    if (x1 == -1) {
                        x1 = i;
                        y1 = j;
                    } else {
                        x2 = i;
                        y2 = j;
                    }
                    a[i][j] = '.';
                }
            }
        }
        System.out.println(go(0, x1, y1, x2, y2));
    }
}
