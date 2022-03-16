// https://www.acmicpc.net/problem/9019
// BFS인 이유: 전의 선택이 후의 선택에 영향을 주기 떄문에 노드와 간선으로 표현
//           + 선택 한번에 대한 가중치가 동일 + 최소 비용 구하기
// 경로까지 구해야함
// 도착지점에서 시작지점까지 경로를 역순으로 찾아갈 수 있도록 from[] 관리
// 소요 시간 : 
package choiheejin.codeplus.BFS;

import java.util.*;

public class DSLR {
    static List<String> answer = new ArrayList<>();

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        sc.nextLine();

        for (int i = 0; i < t; i++) {
            int a = sc.nextInt(), b = sc.nextInt();
            sc.nextLine();
            check(a, b);
        }

        for (int i = 0; i < answer.size(); i++) {
            System.out.println(answer.get(i));
        }
    }

    private static void check(int a, int b) {
        int[][] from = new int[10000][2];
        boolean[] checked = new boolean[10000];
        Deque<Integer> q = new ArrayDeque<>();
        q.add(a);
        checked[a] = true;
        while (!q.isEmpty()) {
            int curr = q.removeFirst();
            if (curr == b) {
                Stack<Character> stack = new Stack<>();
                int toNode = curr;
                while (from[toNode][0] != a) {
                    if (from[toNode][1] == 0)
                        stack.push('D');
                    else if (from[toNode][1] == 1)
                        stack.push('S');
                    else if (from[toNode][1] == 2)
                        stack.push('L');
                    else
                        stack.push('R');
                    toNode = from[toNode][0];
                }
                if (from[toNode][1] == 0)
                    stack.push('D');
                else if (from[toNode][1] == 1)
                    stack.push('S');
                else if (from[toNode][1] == 2)
                    stack.push('L');
                else
                    stack.push('R');
                StringBuilder sb = new StringBuilder();
                while (!stack.isEmpty()) {
                    sb.append(stack.pop());
                }
                answer.add(sb.toString());
            } else {
                // D
                int next = curr * 2 % 10000;
                if (!checked[next]) {
                    q.add(next);
                    checked[next] = true;
                    from[next][0] = curr;
                    from[next][1] = 0;
                }
                // S
                next = curr == 0 ? 9999 : curr - 1;
                if (!checked[next]) {
                    q.add(next);
                    checked[next] = true;
                    from[next][0] = curr;
                    from[next][1] = 1;
                }
                // L
                int d1 = curr / 1000;
                int d234 = curr % 1000;
                next = d234 * 10 + d1;
                if (!checked[next]) {
                    q.add(next);
                    checked[next] = true;
                    from[next][0] = curr;
                    from[next][1] = 2;
                }
                // R
                int d4 = curr % 10;
                int d123 = (curr - d4) / 10;
                next = d4 * 1000 + d123;
                if (!checked[next]) {
                    q.add(next);
                    checked[next] = true;
                    from[next][0] = curr;
                    from[next][1] = 3;
                }
            }
        }
    }

}
