package choiheejin.kakao_internship_2021.answer;

public class 시험장_나누기_복습 {

    int root;
    int L;
    // dp[index][section, group size]
    int[][] dp;
    final int K_MAX = 10000;

    public int solution(int k, int[] num, int[][] links) {

        // 루트 노드부터 찾아야
        // 리프 노드를 차례로 타고 dp를 채워나갈 수 있다.
        boolean[] checked = new boolean[num.length];
        int sum = 0;
        for (int i = 0; i < num.length; i++) {
            if (links[i][0] != -1)
                checked[links[i][0]] = true;
            if (links[i][1] != -1)
                checked[links[i][1]] = true;
            sum += num[i];
        }
        for (int i = 0; i < checked.length; i++) {
            if (!checked[i])
                root = i;
        }

        // 파라메트릭
        int left = sum / 3;
        int right = sum;
        dp = new int[num.length][2];

        // 이분탐색
        while (left + 1 < right) {
            int mid = (left + right) / 2;
            // dp 채우기
            traverse(root, links, num, mid);

            if (dp[root][0] <= k) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return right;
    }

    private void traverse(int i, int[][] links, int[] num, int L) {

        // 자식 노드가 있지만 dp 테이블이 안채워져있다면 채우기
        if (links[i][0] != -1) {
            traverse(links[i][0], links, num, L);
        }
        if (links[i][1] != -1) {
            traverse(links[i][1], links, num, L);
        }

        // 해당 노드가 리프노드인 경우
        if (links[i][0] == -1 && links[i][1] == -1) {
            if (num[i] <= L) {
                dp[i][0] = 1;
                dp[i][1] = num[i];
            } else {
                dp[i][0] = K_MAX;
                dp[i][1] = Integer.MAX_VALUE;
            }
            // 해당 노드가 풀노드인 경우
        } else if (links[i][0] != -1 && links[i][1] != -1) {
            if (num[i] + dp[links[i][0]][1] + dp[links[i][1]][1] <= L) {
                dp[i][0] = dp[links[i][0]][0] + dp[links[i][1]][0] - 1;
                dp[i][1] = num[i] + dp[links[i][0]][1] + dp[links[i][1]][1];
            } else if (num[i] + Math.min(dp[links[i][0]][1], dp[links[i][1]][1]) <= L) {
                dp[i][0] = dp[links[i][0]][0] + dp[links[i][1]][0];
                dp[i][1] = num[i] + Math.min(dp[links[i][0]][1], dp[links[i][1]][1]);
            } else if (num[i] <= L) {
                dp[i][0] = dp[links[i][0]][0] + dp[links[i][1]][0] + 1;
                dp[i][1] = num[i];
            } else {
                dp[i][0] = K_MAX;
                dp[i][1] = Integer.MAX_VALUE;
            }
            // 한쪽만 있을 경우
        } else {
            int child;
            if (links[i][0] != -1)
                child = links[i][0];
            else
                child = links[i][1];

            if (num[i] + dp[child][1] <= L) {
                dp[i][0] = dp[child][0];
                dp[i][1] = num[i] + dp[child][1];
            } else if (num[i] <= L) {
                dp[i][0] = dp[child][0] + 1;
                dp[i][1] = num[i];
            } else {
                dp[i][0] = K_MAX;
                dp[i][1] = Integer.MAX_VALUE;
            }
        }

    }

}
