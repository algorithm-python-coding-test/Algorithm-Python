// 구현
// 필요한 것은 알림창 : stack, 보관함 : list
// 1. 알림창에 소식 들어올 때마다 : 규칙대로 알림 여러개를 하나로 바꾸는 과정
// 2. check notification마다 : 알림 하나를 꺼내어 보관함에 넣기
package choiheejin.devcourse;

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

public class no2 {

    public String[] solution(String[] records) {
        // 알림창과 보관함 준비
        Stack<String> window = new Stack<>();
        List<String> memory = new ArrayList<>();

        // record 하나씩 받아 처리
        for (String record : records) {
            // check notification이면 window에 있는 것, memory로 옮기기
            if (record.equals("check notification")) {
                sendToMemory(window, memory);
            } else {
                // record 변환
                String[] r = record.split(" ");
                if (window.empty()) {
                    window.push(record);
                } else {
                    unionUser(window, r);
                }
            }
        }

        String[] answer = new String[memory.size()];
        for (int i = 0; i < memory.size(); i++) {
            answer[i] = memory.get(i);
        }
        return answer;
    }

    // 사용자 결합해서 새로운 기록 넣기
    private void unionUser(Stack<String> window, String[] r) {
        String front_record = window.peek();
        String[] fr = front_record.split(" ");
        // 같은 사람이 있으면
        if (fr[fr.length - 1].equals(r[1])) {
            window.pop();
            // 2명이상
            if (fr[1].equals("and")) {
                // 3명이상
                if (fr[3].equals("others")) {
                    window.push(fr[0] + " and " + (Integer.parseInt(fr[2]) + 1) + " others " + r[1]);
                    // 2명
                } else {
                    window.push(fr[0] + " and 2 others " + r[1]);
                }
                // 1명
            } else {
                window.push(fr[0] + " and " + r[0] + " " + r[1]);
            }
            // 없으면 그냥 넣기
        } else {
            window.push(r[0] + " " + r[1]);
        }
    }

    private void sendToMemory(Stack<String> window, List<String> memory) {
        String record = window.pop();
        if (record.contains("share")) {
            record = record.replace("share", "shared your post");
        } else {
            record = record.replace("comment", "commented on your post");
        }
        memory.add(record);
    }

    private String action(String act) {
        if (act.equals("share")) {
            return "shared your post";
        } else {
            return "commented on your post";
        }
    }

    public static void main(String[] args) {
        String[] records = { "john share", "mary share", "jay share", "james comment", "lee share",
                "check notification", "sally comment", "laura comment", "check notification", "will share",
                "ruby share", "check notification" };
        new no2().solution(records);
    }
}
