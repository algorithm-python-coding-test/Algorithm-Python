// 선행으로 배워야할 스킬이 있음
// 가장 쉬운 스킬은 트리의 루트노드임
// 이 트리의 특이한 점 : 직접 선행되어야하는 스킬은 무조건 하나임
//  -> 따라서 모든 노드의 진입차수는 루트 노드를 제외하고는 모두 1임 
// 스킬 트리를 array 형태로 줌
// A로 주어진 노드들의 모든 부모 노드를 탐색해라 
package choiheejin.kakao_mobility;

import java.util.HashSet;
import java.util.Set;

public class no2 {
    public int solution(int[] T, int[] A) {
        // tree 그리기
        int[][] tree = new int[T.length][T.length];
        for (int i = 0; i < T.length; i++) {
            tree[T[i]][i] = 1;
        }

        // 각 부모 노드를 저장하는 List
        Set<Integer> parents = new HashSet<>();
        for (int j : A) { // 4, 2, 6, 1,0
            parents.add(j);
            for (int i = 0; i < tree.length; i++) {
                if (tree[i][j] == 1) {
                    int next = i;
                    parents.add(next);
                    while (tree[next][next] != 1) {
                        for (int k = 0; k < tree.length; k++) {
                            if (tree[k][next] == 1) {
                                next = k;
                                parents.add(next);
                            }
                        }
                    }
                }
            }
        }
        return parents.size();

    }

    public static void main(String[] args) {
        int[] T = { 0, 3, 0, 0, 5, 0, 5 };
        int[] A = { 4, 2, 6, 1, 0 };
        System.out.println(new no2().solution(T, A));
    }

}
