// 효율성테스트 소요 시간 : 39.00ms ~ 58.78ms
// 트리 DP
// 정확도 테스트의 제한은 k <= 20, num <= 20 모든 조합으로 통과할 수 있음
// 효율성 테스트의 제한은 k <= 10,000, num <= 10,000 경우의 수가 너무 많음
// => 파라메트릭 서치가 필요

// 파라메트릭 : 최적화 문제 -> 결정 문제
// 주어진 범위 내에서 원하는 조건에 일치하는 값을 찾아내기
// 트리를 k개 이하의 그룹으로 나눠서 얻을 수 있는 최소한의 최대 그룹 크기
// 트리를 k개 이하의 그룹으로 나누어서 얻을 수 있는 최대 그룹의 크기가 L이하가 될 수 있도록 할 수 있는가???
// 공유기 설치 문제와 비슷
// 최대 그룹의 크기는 전체/k보다는 작을 수 없음
// L의 범위 -> 전체/k <= L <= 전체

// L이 조건에 맞는지 확인하려면, 
// 트리 DP는 트리를 후위 순회하여 Buttom-up 방식으로 리프노드부터 dp 배열을 채워나갔다.
// 트리 DP dp[현재 노드][L이하가 되도록하기 위한 최소 section 크기, L이하가 되었을 때 현재 노드를 포함한 서브 트리의 최솟값]
// 1) 현재노드 + dp[l][1] + dp[r][1] <= L -> [dp[l][0] + dp[r][0] - 1, 현재노드 + dp[l][1] + dp[r][1]]
// 2) 현재노드 + min(dp[l][1], dp[r][1]) <= L -> [dp[l][0] + dp[r][0], max(현재노드 + dp[l/r][1], dp[l/r][1])]
// 3) 현재노드 <= L -> [dp[l][0] + dp[r][0] + 1, max(현재노드, dp[l][1], dp[r][1])]
// 4) 현재노드 > L -> dp  -> [MAX_SECTION,INF]
// https://loosie.tistory.com/342

// 서브트리 구조에 대한 경우의수
// 1. 리프노드인 경우
// 2. 풀 노드인 경우
// 3. 왼쪽 자식 노드 혹은 오른쪽 자식 노드만 있는 경우

// 서브트리 구조에 대한 경우의 수를 나눠준 다음
// DP 배열에 각 조건에 맞게 값을 할당
// 마지막으로 탐색하는 노드의 [1] 값이 최대그룹의 크기 L이 된다.
package choiheejin.kakao_internship_2021.answer;

import java.util.ArrayList;
import java.util.List;

public class 시험장_나누기 {

    class Node {
        int data;
        int left, right;

        public Node(int data, int left, int right) {
            this.data = data;
            this.left = left;
            this.right = right;
        }
    }

    private static final int INF = Integer.MAX_VALUE, MAX_SECTION = 10001;
    // 각 노드 정보를 관리하는 리스트 배열
    List<Node>[] list;
    int[][] cost;

    // 파라메트릭 서치
    public int solution(int k, int[] num, int[][] links) {

        int size = num.length;
        // 노드 개수만큼 길이의 배열 만들어주기
        list = new ArrayList[size];
        for (int i = 0; i < size; i++) {
            // 배열마다 리스트 객체 채우기
            list[i] = new ArrayList<>();
        }

        // 전체 노드 데이터 합
        int sum = 0;
        // 모든 노드의 정보를 넣었는지에 대한 체크 정보 저장
        boolean[] check = new boolean[size];
        // 각 노드에 대하여 자식 노드 정보 조회하여 리스트에 넣기
        for (int i = 0; i < size; i++) {
            int left = links[i][0];
            int right = links[i][1];
            if (left != -1)
                check[left] = true;
            if (right != -1)
                check[right] = true;
            // 해당 노드 인덱스 리스트에 대하여 노드 객체 생성하여 집어넣기
            list[i].add(new Node(num[i], left, right));
            // 노드 데이터 더하기
            sum += num[i];
        }

        // 체크안된 노드는 루트 노드
        int root = -1;
        for (int i = 0; i < size; i++) {
            if (!check[i])
                root = i;
        }

        // 파라메트릭
        int left = sum / k;
        int right = sum;
        // 왼쪽과 오른쪽이 같으면 그 값 리턴
        if (left == right)
            return right;
        // 아니면 조건에 부합하는 L 값 구하기
        else {
            while (left + 1 < right) {
                // L값 지정
                int mid = (left + right) / 2;

                // 각 L값에 대하여
                // 각 노드에 대한 dp 테이블 초기화
                cost = new int[size][2];
                // dp 테이블 채워나가기
                traversal(root, mid);
                // 루트 노드의 section 크기 <= k이면 조건에 부합하는 것
                // 조건에 부합하면 아래로 줄여서 다시 확인
                if (cost[root][0] <= k) {
                    right = mid;
                    // 부합하지 않으면 위로 줄여서 다시 확인
                } else {
                    left = mid;
                }
            }
            return right;
        }
    }

    private void traversal(int pos, int w) {
        // 현재 노드 객체 정보를 가져옴
        Node curNode = list[pos].get(0);
        int data = curNode.data, l = curNode.left, r = curNode.right;

        // 자식 노드가 있다면 먼저 자식 노드 정보 업데이트
        if (l != -1)
            traversal(l, w);
        if (r != -1)
            traversal(r, w);

        // leaf 노드라면
        if (l == -1 && r == -1) {
            // 데이터가 L이하면 dp 정보는 [1, data]
            if (data <= w) {
                cost[pos][0] = 1;
                cost[pos][1] = data;
                // 데이터가 L보다 크면 dp 정보는 [MAX_SECTION, INF];
            } else {
                cost[pos][0] = MAX_SECTION;
                cost[pos][1] = INF;
            }
        }

        // full 노드라면
        else if (l != -1 && r != -1) {
            // 1) data + cost[l][1] + cost[r][1] <= w
            if (data + cost[l][1] + cost[r][1] <= w) {
                cost[pos][0] = cost[l][0] + cost[r][0] - 1;
                cost[pos][1] = data + cost[l][1] + cost[r][1];
                // 2) data + Math.min(cost[l][1], cost[r][1]) <= w
            } else if (data + Math.min(cost[l][1], cost[r][1]) <= w) {
                cost[pos][0] = cost[l][0] + cost[r][0];
                // ?????
                cost[pos][1] = data + Math.min(cost[l][1], cost[r][1]);
                // 3) data <= w
            } else if (data <= w) {
                cost[pos][0] = cost[l][0] + cost[r][0] + 1;
                cost[pos][1] = data;
                // 4) data > w
            } else {
                cost[pos][0] = MAX_SECTION;
                cost[pos][1] = INF;
            }
        } else {
            // 왼쪽 자식만 있는 경우
            if (r == -1) {
                // 1) data + cost[l][1] <=w
                if (data + cost[l][1] <= w) {
                    cost[pos][0] = cost[l][0];
                    cost[pos][1] = data + cost[l][1];
                    // 2) data <= w
                } else if (data <= w) {
                    cost[pos][0] = cost[l][0] + 1;
                    cost[pos][1] = data;
                } else {
                    cost[pos][0] = MAX_SECTION;
                    cost[pos][1] = INF;
                }
            }
            // 오른쪽 자식만 있는 경우
            if (l == -1) {
                // 1) data + cost[r][1] <=w
                if (data + cost[r][1] <= w) {
                    cost[pos][0] = cost[r][0];
                    cost[pos][1] = data + cost[r][1];
                    // 2) data <= w
                } else if (data <= w) {
                    cost[pos][0] = cost[r][0] + 1;
                    cost[pos][1] = data;
                } else {
                    cost[pos][0] = MAX_SECTION;
                    cost[pos][1] = INF;
                }
            }
        }
    }
}
