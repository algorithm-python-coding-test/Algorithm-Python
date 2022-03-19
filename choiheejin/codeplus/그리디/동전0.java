// https://www.acmicpc.net/problem/11047
// 다음의 수가 전의 수의 배수 -> 무조건 큰것부터 
// 4200
// 4200 / 1000 = 4
// 4200 % 1000 = 200
// 200 / 100 = 2
// 소요시간: 216ms
package choiheejin.codeplus.그리디;

import java.util.*;

public class 동전0 {

    static int[] coins = new int[10];

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), k = sc.nextInt();
        sc.nextLine();
        for (int i = 0; i < n; i++) {
            coins[i] = sc.nextInt();
        }

        int count = 0;
        for (int i = n - 1; i >= 0; i--) {
            count += k / coins[i];
            k = k % coins[i];
            if (k == 0) {
                System.out.println(count);
                return;
            }
        }
        System.out.println(-1);

    }

}
