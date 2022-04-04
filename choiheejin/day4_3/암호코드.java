// 문자열 길이 5000
// 해석의 가짓수 구하기
// 완전 탐색은 절대 아님
// 25114
// 2, 25로 해석
// 모든 숫자를 하나 또는 2개로 해석할 수 있다면 한개 두개로 묶는 경우의 수만 구하면 됨
// dp[0] = if n[0] == 0 -> 0 // else 1
// dp[1] = 
//  if n[i] == 0 && n[i-1] == 1 || 2 -> dp[i-1]
//  else if n[i] == 0 && n[i-1] != 1 && 2 -> XXXX
//  else if n[i] != 0 && 10 <= n[i-1]~n[i] <= 26 -> dp[i-1] + 1
//  else if n[i] != 0 && n[i-1]~n[i] < 10 && n[i-1]~n[i] > 26 -> dp[i-1]
// dp[i] = 
//  if n[i] == 0 && n[i-1] == 1 || 2 -> dp[i-1]
//  else if n[i] == 0 && n[i-1] != 1 && 2 -> XXXX
//  else if n[i] != 0 && 10 <= n[i-1]~n[i] <= 26 -> dp[i-1] + dp[i-2]
//  else if n[i] != 0 && n[i-1]~n[i] < 10 && n[i-1]~n[i] > 26 -> dp[i-1]

// => 260ms
package choiheejin.day4_3;

import java.util.*;

public class 암호코드 {

    public static void main(String[] args) {
        int[] dp = new int[5000];
        Scanner sc = new Scanner(System.in);
        String n = sc.nextLine();
        // 길이가 없으면 0리턴
        if (n.length() == 0) {
            System.out.println(0);
            return;
        }

        // dp[0] 초기화
        dp[0] = (n.charAt(0) == '0') ? 0 : 1;
        // dp[1] ~ dp[n-1] 값 갱신
        for (int i = 1; i < n.length(); i++) {
            if (n.charAt(i) == '0') {
                if (n.charAt(i - 1) == '1' || n.charAt(i - 1) == '2') {
                    if (i == 1) {
                        dp[i] = 1;
                    } else {
                        dp[i] = dp[i - 2];
                    }
                } else {
                    System.out.println(0);
                    return;
                }
            } else {
                int twoChar = Integer.parseInt(n.substring(i - 1, i + 1));
                if (twoChar >= 10 && twoChar <= 26) {
                    if (i == 1) {
                        dp[i] = (dp[i - 1] + 1) % 1000000;
                    } else {
                        dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000;
                    }
                } else {
                    dp[i] = dp[i - 1];
                }
            }
        }
        System.out.println(dp[n.length() - 1]);
    }

}