// 물을 옮기는 방법: 같은 양의 물이 들어있는 물병 두개를 골라 하나로 몰아주기
// N <= 10**7 K <= 1000
// 같은 양의 물병만 두개를 골라 옮길 수 있음
// N개에서 만들 수 있는 최소 물병 개수는 N을 이진수로 표현했을 때 1의 개수이다.
// 현재의 물병 개수가 K보다 클 경우 -> 1씩 수를 늘려가면서 최초로 1의 개수가 K가 됐을 때 더한 값이 물병 개수가 될 것
// 소요시간: 600ms
package choiheejin.day4_3;

import java.util.*;

public class 물병 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        sc.nextLine();

        int count = 0;
        while (true) {
            if (bitCount(n + count) <= k) {
                System.out.println(count);
                return;
            }
            count++;
        }
    }

    public static int bitCount(int input) {
        int count = 0;
        int mask = 1 << 31;

        while (true) {
            // 모든 순회 끝남
            if (mask == 0) {
                break;
            }
            if ((mask & input) != 0) {
                count++;
            }
            mask = mask >>> 1;
        }
        return count;
    }

}
