// 인접 행렬이 아니라 인접 리스트로 구현
// dfs로 부모 리스트를 관리하며 원하는 노드가 나왔을떄 그 부모 리스트를 답안 set에 넣어줌
package choiheejin.kakao_mobility;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
import java.util.stream.IntStream;

public class no2_after {
    public int solution(int[] T, int[] A) {
        int root = 0;
        // tree 그리기
        List<List<Integer>> tree = new ArrayList<>();
        for (int i = 0; i < T.length; i++) {
            tree.add(new ArrayList<>());
        }

        for (int i = 0; i < T.length; i++) {
            tree.get(T[i]).add(i);
        }

        // dfs로 모든 부모를 따라가며 탐색 후 그 노드 중에 A에 속한 것이 있다면 Set에 부모들을 set에 집어넣기
        Set<Integer> parents = new HashSet<>();
        List<Integer> currentParents = new ArrayList<>();

        dfs(tree, A, root, parents, currentParents);
        return parents.size();
    }

    private void dfs(List<List<Integer>> tree, int[] A, int i, Set<Integer> parents, List<Integer> currentParents) {
        // 현재 부모 노드 리스트에 자기 자신 집어넣기
        currentParents.add(i);
        // 현재 노드가 A에 속한다면, 현재 부모 노드 리스트를 답 set에 집어넣고 초기화
        if (IntStream.of(A).anyMatch(x -> x == i)) {
            parents.addAll(currentParents);
        }

        for (int j : tree.get(i)) {
            if (i != j) {
                dfs(tree, A, j, parents, currentParents);
            }
        }

        currentParents.remove(Integer.valueOf(i));

    }

    public static void main(String[] args) {
        int[] T = { 0, 3, 0, 0, 5, 0, 5 };
        int[] A = { 2, 4, 6, 1, 0 };
        System.out.println(new no2_after().solution(T, A));
    }

}