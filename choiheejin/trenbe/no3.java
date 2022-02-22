// 완전 탐색 or 그리디
// 선을 설치하는 것보다 일단 점을 묶어보기?
// 1개만 사용한다면 제일 하나의 그룹에서 제일 오른쪽 - 제일 왼쪽 < 선분 이면 가능
// 2개만 사용한다면 두개의 그룹으로 나누고 각 그룹에서 제일 오른쪽 - 제일 왼쪽 < 선분 이면 가능
package choiheejin.trenbe;

import java.util.Collections;
import java.util.Iterator;
import java.util.PriorityQueue;

public class no3 {
    public int solution(int[] dots, int[] lines) {
        PriorityQueue<Integer> linesq = new PriorityQueue<>(Collections.reverseOrder());
        for (int line : lines) {
            linesq.add(line);
        }

        int answer = 1;
        while (answer < lines.length) {
            Iterator<Integer> iterator = linesq.iterator();
            int sum = 0;
            for (int i = 0; i < answer; i++) {
                sum += iterator.next();
            }
            if (dots[dots.length - 1] - dots[0] < sum) {
                return answer;
            }
            answer++;
        }
        return -1;

    }

    public static void main(String[] args) {
        int[] dots = { 1, 5, 8 };
        int[] lines = { 1, 3, 4, 6 };
        System.out.println(new no3().solution(dots, lines));
    }
}
