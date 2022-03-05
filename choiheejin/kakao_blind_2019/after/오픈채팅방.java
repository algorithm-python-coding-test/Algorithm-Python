// 아이디와 가장 최근 닉네임을 관리하는 Map
// record를 차례대로 보고 하나씩 최근 닉네임을 안뒤
// 다시 record를 처음부터 읽어서 문자열 생성
package choiheejin.kakao_blind_2019.after;

import java.util.*;

class 오픈채팅방 {
    public String[] solution(String[] record) {
        Map<String, String> map = new HashMap<>();
        for (String line : record) {
            String[] info = line.split(" ");
            if (info[0].equals("Enter") || info[0].equals("Change")) {
                map.put(info[1], info[2]);
            }
        }
        List<String> answer = new ArrayList<>();
        for (String line : record) {
            String[] info = line.split(" ");
            String nickname = map.get(info[1]);
            if (info[0].equals("Enter")) {
                answer.add(nickname + "님이 들어왔습니다.");
            } else if (info[0].equals("Leave")) {
                answer.add(nickname + "님이 나갔습니다.");
            }
        }
        return answer.toArray(String[]::new);
    }
}