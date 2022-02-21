// 1. FirstMiddleLast@Company.com
// 2. FirstName 이니셜, MiddleName이 있다면 이니셜, Lastname은 8글자 이하로 잘라야함
// 3. 같은 이메일이 만들어진다면 -> 두 번째부터는 @ 앞에 숫자가 들어가야함
package choiheejin.kakao_mobility;

import java.util.HashMap;

public class no1 {
    public String solution(String S, String C) {
        String[] sa = S.split(", ");
        String[] emails = new String[sa.length];
        HashMap<String, Integer> emailsMap = new HashMap<>();
        for (int i = 0; i < sa.length; i++) {
            String[] names = sa[i].split(" ");
            String email = "" + names[0].toLowerCase().charAt(0);
            if (names.length == 3) {
                email += names[1].toLowerCase().charAt(0);
            }
            names[names.length - 1] = names[names.length - 1].replace("-", "");
            try {
                email += names[names.length - 1].toLowerCase().substring(0, 8) + "@" + C.toLowerCase()
                        + ".com";
            } catch (Exception e) {
                email += names[names.length - 1].toLowerCase() + "@" + C.toLowerCase()
                        + ".com";
            }
            if (emailsMap.containsKey(email)) {
                int index = emailsMap.get(email) + 1;
                emailsMap.put(email, index);
                email = email.replace("@", index + "@");
            } else {
                emailsMap.put(email, 1);
            }
            emails[i] = email;
        }
        String answer = "";
        for (int i = 0; i < emails.length; i++) {
            answer += sa[i] + " <" + emails[i] + ">, ";
        }
        answer = answer.substring(0, answer.length() - 2);
        return answer;
    }

    public static void main(String[] args) {
        String S = "John Doe, Peter Parker, Mary Jane Watson-Parker, James Doe, John Elvis Doe, Jane Doe, Penny Parker";
        String C = "Example";
        System.out.println(new no1().solution(S, C));

    }
}
