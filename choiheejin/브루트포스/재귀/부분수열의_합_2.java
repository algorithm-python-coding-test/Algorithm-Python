// 모든 합을 어딘가에 저장해두고 가장 작은 자연수부터 만들수 없는 자연수를 찾아주면 됨
package choiheejin.브루트포스.재귀;

import java.util.*;

public class 부분수열의_합_2 {
    static boolean[] c = new boolean[20 * 100000 + 10];
    static int[] a = new int[20];
    static int n;

    static void go(int i, int sum) {
        if (i == n) {
            c[sum] = true;
            return;
        }
        go(i + 1, sum + a[i]);
        go(i + 1, sum);
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        go(0, 0);
        for (int i = 1;; i++) {
            if (c[i] == false) {
                System.out.println(i);
                break;
            }
        }
    }
}
