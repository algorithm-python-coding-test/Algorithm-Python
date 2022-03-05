package choiheejin.kakao_internship_2021.answer;

import java.util.Stack;

public class 표_편집_복습 {

    class Node {
        Node next;
        Node prev;
        boolean removed;
    }

    Node[] array = new Node[1000000];

    Node cursor;

    Stack<Node> removedNodes = new Stack<>();

    public String solution(int n, int k, String[] cmd) {

        // array 초기화
        for (int i = 0; i < n; i++) {
            array[i] = new Node();
            if (i > 0) {
                array[i - 1].next = array[i];
                array[i].prev = array[i - 1];
            }
        }

        // cursor 초기화
        cursor = array[k];

        // command 한줄씩 실행
        for (String line : cmd) {
            if (line.charAt(0) == 'U') {
                int up = Integer.parseInt(line.substring(2));
                for (int i = 0; i < up; i++)
                    cursor = cursor.prev;
            } else if (line.charAt(0) == 'D') {
                int up = Integer.parseInt(line.substring(2));
                for (int i = 0; i < up; i++)
                    cursor = cursor.next;
            } else if (line.charAt(0) == 'C') {
                Node prev = cursor.prev;
                Node next = cursor.next;
                cursor.removed = true;
                removedNodes.push(cursor);
                // 첫번쨰 행이 아니라면
                if (prev != null)
                    prev.next = next;
                // 마지막 행이 아니라면
                if (next != null) {
                    next.prev = prev;
                    cursor = next;
                    // 마지막 행이라면
                } else {
                    cursor = prev;
                }

            } else {
                Node node = removedNodes.pop();
                Node prev = node.prev;
                Node next = node.next;
                node.removed = false;

                if (next != null)
                    next.prev = node;
                if (prev != null)
                    prev.next = node;
            }
        }

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++) {
            if (array[i].removed)
                sb.append('X');
            else
                sb.append('O');
        }

        return sb.toString();
    }

    public static void main(String[] args) {
        int n = 8;
        int k = 2;
        String[] cmd = { "D 2", "C", "U 3", "C", "D 4", "C", "U 2", "Z", "Z" };
        System.out.println(new 표_편집_복습().solution(n, k, cmd));
    }
}
