// 효율성 테스트 소요 시간 : 91.65ms ~ 350.09ms
package choiheejin.kakao_internship_2021.answer;

import java.util.Stack;

public class 표_편집 {

    // 양방향 LinkedList
    class Node {
        boolean removed;
        Node prev;
        Node next;
    }

    Node[] NodeArr = new Node[1000000];

    public String solution(int n, int k, String[] cmd) {

        // 배열 안에 n개만큼 객체 만들기
        for (int i = 0; i < n; ++i)
            NodeArr[i] = new Node();
        for (int i = 1; i < n; ++i) {
            NodeArr[i - 1].next = NodeArr[i];
            NodeArr[i].prev = NodeArr[i - 1];
        }

        // 현재 노드를 k번으로 초기화
        Node curr = NodeArr[k];
        // 삭제한 것을 Stack에 저장
        Stack<Node> mystack = new Stack<>();

        // 한 줄씩 실행
        for (String str : cmd) {
            // 위로 이동
            if (str.charAt(0) == 'U') {
                int x = Integer.parseInt(str.substring(2));
                for (int i = 0; i < x; i++) {
                    curr = curr.prev;
                }
                // 아래 이동
            } else if (str.charAt(0) == 'D') {
                int x = Integer.parseInt(str.substring(2));
                for (int i = 0; i < x; i++) {
                    curr = curr.next;
                }
                // 삭제
            } else if (str.charAt(0) == 'C') {
                mystack.push(curr);
                curr.removed = true;
                Node up = curr.prev;
                Node down = curr.next;
                // 지금 삭제 되는 행이 첫번째가 아니라면
                if (up != null)
                    up.next = down;
                // 지금 삭제 되는 행이 마지막이 아니라면
                if (down != null) {
                    down.prev = up;
                    curr = down;
                    // 마지막 행이라면
                    // (up과 down이 둘다 null일 경우에는 배열 길이가 1개란 뜻인데
                    // 이 상태에서 삭제되는 입력은 처음부터 주어지지 x)
                } else {
                    curr = up;
                }

                // 복구
            } else {
                Node node = mystack.pop();
                node.removed = false;
                Node up = node.prev;
                Node down = node.next;
                if (up != null)
                    up.next = node;
                if (down != null)
                    down.prev = node;
            }
        }

        // String이 StringBuilder보다 비효율적인 이유 : String은 immutable 클래스이므로 뒤에 붙이면 그것을 붙인 새로운
        // 문자열을 만들기 때문
        StringBuilder answer = new StringBuilder();
        for (int i = 0; i < n; ++i) {
            if (NodeArr[i].removed)
                answer.append('X');
            else
                answer.append('O');
        }
        return answer.toString();
    }

    public static void main(String[] args) {
        int n = 8;
        int k = 2;
        String[] cmd = { "D 2", "C", "U 3", "C", "D 4", "C", "U 2", "Z", "Z", "U 1", "C" };
        System.out.println(new 표_편집().solution(n, k, cmd));

    }
}
