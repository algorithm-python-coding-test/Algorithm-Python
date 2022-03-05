// 후보키를 찾는 방법
// 후보키의 크기는 1-coloumn개수
// 각 경우의 수를 모두 뒤져보면 2**8개 경우의수
// 일단 1부터 세본다.
// 1개 크기의 후보키를 구하고 2개로 넘어갈때에는 1개째에서 나왔던 컬럼은 뺀다.
// 2개 크기의 후보키를 구하고 3개로 넘어갈때에는 해당 2개를 모두 포함하는 조합은 뺸다.
// 필요한 자료구조 : 후보키로 사용이 됐는지 여부 boolean[]
// 후보키를 구할때에는 각 조합에 대해서
// 모든 로우를 돌며 unique한지 확인
package choiheejin.kakao_blind_2019.after;

import java.util.*;

public class 후보키 {
    static int[] now;
    static List<List<Integer>> comb;
    static List<List<Integer>> candidateKeys = new ArrayList<>();

    public int solution(String[][] relation) {
        // 후보키의 크기가 컬럼 개수를 넘어가기 전까지
        int size = 1;
        while (size <= relation[0].length) {
            comb = new ArrayList<>();
            now = new int[size];
            // 후보키 조합 구하기
            combination(relation[0].length, size, 0, 0);
            // 각 조합에 대하여
            Iterator<List<Integer>> iterator = comb.iterator();
            comb: while (iterator.hasNext()) {
                List<Integer> candidate = iterator.next();

                // 전에 구한 것을 포함하면
                for (int i = 0; i < candidateKeys.size(); i++) {
                    if (candidate.containsAll(candidateKeys.get(i)))
                        continue comb;
                }

                // unique하면 candidateKeys에 포함
                for (int i = 0; i < relation.length; i++) {
                    for (int j = 0; j < relation.length; j++) {
                        if (i == j)
                            continue;
                        boolean allColumnEqual = true;
                        for (int column : candidate) {
                            if (!relation[i][column].equals(relation[j][column])) {
                                allColumnEqual = false;
                                break;
                            }
                        }
                        if (allColumnEqual)
                            continue comb;
                    }
                }
                candidateKeys.add(candidate);
            }
            size++;
        }
        for (int i = 0; i < candidateKeys.size(); i++) {
            System.out.println(candidateKeys.get(i));
        }
        return candidateKeys.size();
    }

    static void combination(int n, int r, int index, int target) {
        if (r == 0) {
            List<Integer> temp = new ArrayList<>();
            for (int i = 0; i < now.length; i++) {
                temp.add(now[i]);
            }
            comb.add(temp);
            return;
        } else if (target == n) {
            return;
        } else {
            now[index] = target;
            combination(n, r - 1, index + 1, target + 1);
            combination(n, r, index, target + 1);
        }
    }
}
