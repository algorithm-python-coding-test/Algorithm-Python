// 50이면
// 1+1+1+1....+11 연산자는 24개가 최대, 피연산자는 25개가 최대
// 연산자의 순서 케이스를 모두 구한다면 24! 너무 큼
// 어떻게 푸는지 해결방법 대충 확인함....
// 소요 시간: 224ms
package choiheejin.day4_3;

import java.util.*;

public class 잃어버린_괄호 {

    static List<Integer> tokens = new ArrayList<>();

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        StringBuilder sb = new StringBuilder(str);
        int lastMinusIndex = 0;
        // 식을 순회하면서 -를 기준으로 문자열 분리
        for (int i = 0; i < sb.length(); i++) {
            // -를 만나면 이 앞과 뒤를 자름
            if (sb.charAt(i) == '-') {
                // 앞부분을 잘라서 숫자만 찾아 더하기
                StringBuilder front = new StringBuilder(sb.substring(lastMinusIndex, i));
                // -으로 식이 시작할 때에 대한 예외 처리
                if (front.length() == 0) {
                    continue;
                }
                int token = 0;
                int last = 0;
                for (int j = 0; j < front.length(); j++) {
                    if (front.charAt(j) == '+') {
                        // +으로 식이 시작할 때에 대한 예외 처리
                        if (front.substring(last, j).length() == 0) {
                            continue;
                        }
                        token += Integer.parseInt(front.substring(last, j));
                        last = j + 1;
                    }
                }
                token += Integer.parseInt(front.substring(last, front.length()));
                tokens.add(token);
                lastMinusIndex = i + 1;
            }
        }
        // 마지막으로 남은 문자열도 토큰에 집어넣기
        int token = 0;
        int last = lastMinusIndex;
        for (int j = lastMinusIndex; j < sb.length(); j++) {
            if (sb.charAt(j) == '+') {
                // +으로 식이 시작할 때에 대한 예외 처리
                if (sb.substring(last, j).length() == 0) {
                    continue;
                }
                token += Integer.parseInt(sb.substring(last, j));
                last = j + 1;
            }
        }
        token += Integer.parseInt(sb.substring(last, sb.length()));
        tokens.add(token);

        int answer = tokens.get(0);
        for (int i = 1; i < tokens.size(); i++) {
            answer -= tokens.get(i);
        }

        System.out.println(answer);

    }
}
