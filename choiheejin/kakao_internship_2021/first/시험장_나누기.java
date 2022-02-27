// 가장 큰 그룹의 인원을 최소화하기
// 각 노드에 대하여 그 자손 노드들의 합을 DP로 구함
// DP를 탐색해서 그룹의 합이 가장 큰 것부터 자르면서 업데이트
package choiheejin.kakao_internship_2021.first;

import java.util.Comparator;
import java.util.PriorityQueue;

public class 시험장_나누기 {
    
    static int[][] sum = new int[10000][2];

    public int solution(int k, int[] num, int[][] links) {

        PriorityQueue<Integer> q = new PriorityQueue<>(new Comparator<>() {

            @Override
            public int compare(Integer o1, Integer o2) {

                return 0;
            }

        });

        for (int i = 0; i < sum.length; i++) {
            sum[i][0] = -1;
            sum[i][1] = -1;
        }
        boolean[] checked = new boolean[num.length];

        for (int i = 0; i < checked.length; i++) {
            if (!checked[i]) {
                dfs(sum, links, num, checked, i);
            }
        }

        int answer = 0;
        return answer;
    }

    public static void dfs(int[][] sum, int[][] links, int[] num, boolean[] checked, int i) {
        // 왼쪽이 리프노드가 아니라면
        if (links[i][0] != -1) {
            // 자식노드가 모두 확인이 완료되지 않았다면 체크해주고
            if (!checked[links[i][0]]) {
                dfs(sum, links, num, checked, links[i][0]);
            }
            // 자식 노드 + 자식 노드의 왼쪽 자식노드 + 자식노드의 오른쪽 자식 노드
            sum[i][0] = sum[links[i][0]][0] + sum[links[i][0]][1] + num[links[i][0]];
        } else {
            sum[i][0] = 0;
        }
        // 오른쪽이 리프노드가 아니라면
        if (links[i][1] != -1) {
            // 자식노드가 모두 확인이 완료되지 않았다면 체크해주고
            if (!checked[links[i][1]]) {
                dfs(sum, links, num, checked, links[i][1]);
            }
            // 자식 노드 + 자식 노드의 왼쪽 자식노드 + 자식노드의 오른쪽 자식 노드
            sum[i][1] = sum[links[i][1]][0] + sum[links[i][1]][1] + num[links[i][1]];
            // 왼쪽이 리프노드라면
        } else {
            sum[i][1] = 0;
        }

        if (sum[i][0] != -1 && sum[i][1] != -1) {
            checked[i] = true;
        }
    }

    public static void main(String[] args) {
        int k = 3;
        int[] num = { 12, 30, 1, 8, 8, 6, 20, 7, 5, 10, 4, 1 };
        int[][] links = { { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { 8, 5 }, { 2, 10 }, { 3, 0 }, { 6, 1 },
                { 11, -1 }, { 7, 4 }, { -1, -1 }, { -1, -1 } };
        new 시험장_나누기().solution(k, num, links);
    }
}
