// 그래프 합집합 찾기
// 합집합을 찾고 해당 그룹 안에서 만족도 조사를 한 친구들의 평균을 낸뒤
// 만족도 조사를 하지 않은 학생들을 해당 평균으로 채움
// 어떤 그룹안에서 하나도 만족도 조사를 안했다면 예측 방법 사용 불가능
package choiheejin.soma2;

import java.util.*;

public class no2 {

    static int[] studentResults;
    static int[][] parents;

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), m = sc.nextInt(), k = sc.nextInt();
        sc.nextLine();

        studentResults = new int[n + 1];
        for (int i = 0; i < m; i++) {
            studentResults[sc.nextInt()] = sc.nextInt();
            sc.nextLine();
        }

        parents = new int[n + 1][2];
        for (int i = 1; i <= n; i++) {
            parents[i][0] = i;
            parents[i][1] = studentResults[i] == 0 ? Integer.MAX_VALUE : studentResults[i];
        }

        for (int i = 0; i < k; i++) {
            union(sc.nextInt(), sc.nextInt());
            sc.nextLine();
        }

        // 그룹순, 만족도 순으로 정렬
        Arrays.sort(parents, (o1, o2) -> {
            if (o1[0] == o2[0]) {
                return o1[1] - o2[1];
            } else {
                return o1[0] - o2[0];
            }
        });

        int sum = 0, count = 0, group = parents[1][0];
        for (int i = 1; i <= n; i++) {
            if (group != parents[i][0]) {
                sum = 0;
                count = 0;
                group = parents[i][0];
            }
            if (parents[i][1] != Integer.MAX_VALUE) {
                sum += parents[i][1];
                count++;
            } else {
                if (count == 0) {
                    parents[i][1] = 0;
                } else {
                    parents[i][1] = sum / count;
                }
            }
        }

        sum = 0;
        count = 0;
        for (int i = 1; i <= n; i++) {
            if (parents[i][1] != 0) {
                sum += parents[i][1];
                count++;
            }
        }
        Float ans = sum / 1.0f / count;
        String ansStr = ans.toString();
        if (ansStr.length() == 3) {
            ansStr = ansStr.concat("0");
        }
        System.out.println(ansStr.substring(0, 4));
    }

    static void union(int a, int b) {
        if (find(a) < find(b)) {
            parents[b][0] = parents[a][0];
        } else {
            parents[a][0] = parents[b][0];
        }

    }

    static int find(int a) {
        if (parents[a][0] == a) {
            return a;
        } else {
            parents[a][0] = find(parents[a][0]);
            return parents[a][0];
        }
    }
}
