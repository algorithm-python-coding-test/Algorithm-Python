// 사전순으로 출력하라고 했는데 코드상에는 정렬하는 것이 없음
// 문제 조건에 k개의 수는 항상 오름차순으로 주어진다고 했고,
// 코드에서는 index 번째는 선택안하는 것보다 선택하는 경우가 먼저 계산되기 때문
// 작은 수를 선택하는 것을 먼저 처리하기 때문에 정렬과정이 없어도 됨.
// 시간복잡도 : 2**12
package choiheejin.브루트포스.재귀;

import java.util.*;

public class 로또 {
    static ArrayList<Integer> lotto = new ArrayList<>();

    static void solve(int[] a, int index, int cnt) {
        if (cnt == 6) {
            for (int num : lotto) {
                System.out.print(num + " ");
            }
            System.out.println();
            return;
        }
        int n = a.length;
        if (n == index)
            return;
        lotto.add(a[index]);
        solve(a, index + 1, cnt + 1);
        lotto.remove(lotto.size() - 1);
        solve(a, index + 1, cnt);
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        while (true) {
            int n = sc.nextInt();
            if (n == 0)
                break;
            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = sc.nextInt();
            }
            solve(a, 0, 0);
            System.out.println();
        }
    }
}
