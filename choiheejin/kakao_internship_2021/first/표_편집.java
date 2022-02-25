// 구현 : 삭제된 행을 복구해야함 -> 하나의 변수에 {위치, 정보} 저장
// 선택된 행은 하나의 변수로 구현
// 마지막 행을 삭제하면 다음으로 마지막 행이 되는 것을 선택
// 현재 선택된 것보다 위에서 복구가 이뤄지면 여전히 그것을 선택하고 있어야함!!
// 효율성이므로 삭제가 편한 Linked List로 관리
// 케이스
// 선택된 것이 마지막 것인데 마지막 것을 삭제하는 경우: 선택된 행 -1
// 테스트 케이스 2가 반례임.... 굳이 같은 노드를 두번 가지 않고 같은 함정을 두번 갈 수 있음...
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
        // 최대 1,000,000 번
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
                    cursor = n - 1;
                }
                // 삭제
            } else if (line.equals("C")) {
                System.out.println(cursor);
                Entry removedEntry = list.remove(cursor);
                sb.setCharAt(removedEntry.firstIndex, 'X');
                removedEntry.removedIndex = cursor;
                removed.push(removedEntry);
                if (cursor == n - 1) {
                    cursor--;
                }
                // 복구
            } else if (line.equals("Z")) {
                Entry removedEntry = removed.pop();
                list.add(removedEntry.removedIndex, removedEntry);
                sb.setCharAt(removedEntry.firstIndex, 'O');
            }
        }
        return sb.toString();
    }

    public static void main(String[] args) {
        int n = 30;
        int k = 2;
        String[] cmd = { "D 23", "C", "U 20", "C", "Z" };
        System.out.println(new 표_편집().solution(n, k, cmd));

    }
}
