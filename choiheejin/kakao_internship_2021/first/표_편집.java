// // 1차 : LinkedList와 Stringbuilder를 사용했으나 
// 정확도와 효율성 모두 부족했음 
// -> 이후 정확도를 채우고 
// Stringbuilder를 처음부터 사용하여 효율성을 높였으나
// 여전히 효율성 테스트를 넘지 못함
// -> LinkedList의 추가/삭제 속도는 O(1)이지만 
// 추가/삭제 대상이 되는 노드를 탐색하는데 O(n)이 걸리기 때문 
// -> 직접 구현해야 하며 DoubleLinked여야 함
// 최소시간 : 1.95ms
// 최대시간 : 5.16ms
package choiheejin.kakao_internship_2021.first;

import java.util.LinkedList;
import java.util.List;
import java.util.Stack;

class Entry {
    int firstIndex;
    int removedIndex;

    public Entry(int firstIndex) {
        this.firstIndex = firstIndex;
    }
}

public class 표_편집 {
    public String solution(int n, int k, String[] cmd) {
        String answer = "";
        List<Entry> list = new LinkedList<>();
        int cursor = k;
        Stack<Entry> removed = new Stack<>();

        for (int i = 0; i < n; i++) {
            answer += "O";
            list.add(new Entry(i));
        }

        StringBuilder sb = new StringBuilder(answer);

        for (String line : cmd) {
            // 커서 이동
            if (line.startsWith("U")) {
                cursor -= Integer.parseInt(line.substring(2));
                if (cursor < 0) {
                    cursor = 0;
                }
            } else if (line.startsWith("D")) {
                cursor += Integer.parseInt(line.substring(2));
                if (cursor >= n) {
                    cursor = list.size() - 1;
                }
                // 삭제
            } else if (line.equals("C")) {
                Entry removedEntry = list.remove(cursor);
                sb.setCharAt(removedEntry.firstIndex, 'X');
                removedEntry.removedIndex = cursor;
                removed.push(removedEntry);
                if (cursor == list.size()) {
                    cursor--;
                }
                // 복구
            } else if (line.equals("Z")) {
                Entry removedEntry = removed.pop();
                list.add(removedEntry.removedIndex, removedEntry);
                sb.setCharAt(removedEntry.firstIndex, 'O');
                if (removedEntry.removedIndex <= cursor) {
                    cursor++;
                }
            }
        }
        return sb.toString();
    }

    public static void main(String[] args) {
        int n = 8;
        int k = 2;
        String[] cmd = { "D 2", "C", "U 3", "C", "D 4", "C", "U 2", "Z", "Z", "U 1", "C" };
        System.out.println(new 표_편집().solution(n, k, cmd));

    }
}
