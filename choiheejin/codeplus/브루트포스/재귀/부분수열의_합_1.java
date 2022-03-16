// 크기가 양수인 부분 수열 중이라고 했으니 아무것도 고르지 않은 경우는 빼줘야함
// 시간 복잡도 : 2**n
package choiheejin.codeplus.브루트포스.재귀;

import java.util.*;

public class 부분수열의_합_1 {
    public static int go(int[] a, int m, int i, int sum) {
        if (i == a.length) {
            if (sum == m) {
                return 1;
            } else {
                return 0;
            }
        }
        return go(a, m, i + 1, sum + a[i]) + go(a, m, i + 1, sum);
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        int ans = go(a, m, 0, 0);
        if (m == 0) {
            ans -= 1;
        }
        System.out.println(ans);
    }
}
