// https://www.acmicpc.net/problem/16928
// 거리를 의미하는 배열 dist
// 사다리, 뱀 관계를 표현하는 배열 next
// BFS인 이유: 다음칸으로 가는데는 '주사위를 한번 돌리는' 가중치가 동일하기 때문
// i -> i+1, i+2, i+3, i+4, i+5, i+6
// next[] => 뱀과 사다리로 인해 가게 되는 다음 칸
// 소요시간 : 232ms
package choiheejin.codeplus.BFS;

import java.util.*;

public class 뱀과_사다리_게임 {

    static int[] next = new int[101];
    static boolean[] checked = new boolean[101];

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), m = sc.nextInt();
        sc.nextLine();
        // 일반 노드 초기화
        for (int i = 1; i <= 100; i++) {
            next[i] = i;
        }
        // 사다리 정보 초기화
        for (int i = 0; i < n; i++) {
            next[sc.nextInt()] = sc.nextInt();
            sc.nextLine();
        }
        // 뱀 정보 초기화
        for (int i = 0; i < m; i++) {
            next[sc.nextInt()] = sc.nextInt();
            sc.nextLine();
        }

        Deque<int[]> q = new ArrayDeque<>();
        q.add(new int[] { 1, 0 });
        checked[1] = true;
        while (!q.isEmpty()) {
            int[] curr = q.removeFirst();
            if (curr[0] == 100) {
                System.out.println(curr[1]);
            }
            for (int i = 1; i <= 6; i++) {
                if (curr[0] + i > 100) {
                    continue;
                }
                int nextNode = next[curr[0] + i];
                if (!checked[nextNode]) {
                    checked[nextNode] = true;
                    q.add(new int[] { nextNode, curr[1] + 1 });
                }
            }
        }
    }
}
