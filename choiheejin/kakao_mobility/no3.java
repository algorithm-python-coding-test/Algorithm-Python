// 짝수 값이 모두 같고 홀수값이 모두 같은 배열의 길이의 최댓값능구하라
// [0, 1, 2, 3, 4, 5, 6] 2, 3, 4, 5 가 같다면?
// [0, 2, 4, 6] 여기서 2와 4가 같은 것
// [1, 3, 5] 여기서는 하나밖에 안섞여있음

// 문제는 효율성인데, 100,000이라는 것
// 그래도 완전 탐색 정도는 가능해보임
package choiheejin.kakao_mobility;

import java.util.ArrayList;
import java.util.List;

public class no3 {
    public int solution(int[] A) {
        if (A.length < 2) {
            return A.length;
        }
        int sameEven = 0;
        int sameOdd = 0;
        int count = 2;
        List<Integer> counts = new ArrayList<>();

        for (int i = 0; i < A.length; i++) {
            if (i == 0) {
                sameEven = A[i];
            } else if (i == 1) {
                sameOdd = A[i];
            } else if (i % 2 == 0) {
                if (A[i] == sameEven) {
                    count++;
                } else {
                    if (count > 2) {
                        counts.add(count);
                    }
                    sameEven = A[i];
                    count = 2;
                }
            } else {
                if (A[i] == sameOdd) {
                    count++;
                } else {
                    if (count > 2) {
                        counts.add(count);
                    }
                    sameOdd = A[i];
                    count = 2;
                }
            }
        }
        if (count > 2) {
            counts.add(count);
        }

        if (counts.size() == 0) {
            return 2;
        }

        int max = 0;
        for (int i = 0; i < counts.size(); i++) {
            if (counts.get(i) >= max) {
                max = counts.get(i);
            }
        }
        return max;

    }

    public static void main(String[] args) {
        int[] A = { 3, 2, 3, 2, 5, 2, 4, 2, 4, 2, 4, 2, 1 };
        System.out.println(new no3().solution(A));
    }
}
