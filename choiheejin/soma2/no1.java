// 모든 조합에 대해서 브루트 포스
// 각 조합에 대해 이탈하는 손님 수를 구하고
// 해당 손님수가 최소일떄의 유지할 수 있는 손님 수 구하기
package choiheejin.soma2;

import java.util.*;

public class no1 {

    static int[][] guest;
    static List<List<Integer>> cases = new ArrayList<>();

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), m = sc.nextInt(), k = sc.nextInt();
        sc.nextLine();
        guest = new int[n][m];
        // curr = new int[k];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                guest[i][j] = sc.nextInt();
            }
            sc.nextLine();
        }
        getCases(m, k, 0, 0, new ArrayList<Integer>());

        int min = Integer.MAX_VALUE;
        // 각 조합에 대해서 이탈 손님 수 구하기
        for (int i = 0; i < cases.size(); i++) {
            boolean[] guestOut = new boolean[n];
            List<Integer> set = cases.get(i);
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (guestOut[j])
                    continue;
                for (int l = 0; l < set.size(); l++) {
                    if (guest[j][set.get(l)] >= 5 && !guestOut[j]) {
                        guestOut[j] = true;
                        count++;
                    }
                }
            }
            min = Math.min(min, count);
        }

        System.out.println(n - min);

    }

    static void getCases(int m, int k, int e, int index, List<Integer> set) {
        if (e == k) {
            List<Integer> newSet = new ArrayList<>();
            for (int i = 0; i < set.size(); i++) {
                newSet.add(set.get(i));
            }
            cases.add(newSet);
        }

        else if (index == m)
            return;
        else {
            set.add(index);
            getCases(m, k, e + 1, index + 1, set);
            set.remove(e);
            getCases(m, k, e, index + 1, set);
        }
    }
}
