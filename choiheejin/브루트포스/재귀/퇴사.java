// 모든 브루트포스를 다이내믹으로 풀수 있는 것은 아니지만
// 퇴사 문제는 브루트포스와 다이내믹으로 둘다 풀 수 있는데
// 그 이유는 어떤 성질이 있기 때문
package choiheejin.브루트포스.재귀;

import java.util.*;

public class 퇴사 {
    static final int inf = -100000000;
    static int[] t;
    static int[] p;
    static int n;
    static int ans = 0;

    static void go(int day, int sum) {
        if (day == n + 1) {
            if (ans < sum)
                ans = sum;
            return;
        }
        if (day > n + 1) {
            return;
        }
        go(day + 1, sum);
        go(day + t[day], sum + p[day]);
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        t = new int[n + 1];
        p = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            t[i] = sc.nextInt();
            p[i] = sc.nextInt();
        }
        go(1, 0);
        System.out.println(ans);
    }
}
