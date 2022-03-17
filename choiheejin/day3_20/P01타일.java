// 보텀업
// dp[1] 1
// dp[2] = 00 11 = 2
// dp[3] = 1__ + 00_ = dp[2] + dp[1] = 3
// dp[4] = 1___ + 00__ = dp[3] + dp[2] = 3 + 2 = 5
// dp[5] = 1____ + 00___ = dp[4] + dp[3] = 5 + 3 = 8
// 소요시간: 232ms
package choiheejin.day3_20;

import java.util.*;

public class P01타일 {

    public static void main(String[] args) {

        long[] dp = new long[1000001];

        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();
        dp[1] = 1;
        dp[2] = 2;

        for (int i = 3; i <= n; i++) {
            dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
        }

        System.out.println(dp[n]);
    }

}
