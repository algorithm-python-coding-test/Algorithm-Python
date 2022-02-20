package choiheejin.kakao_winter_2019.answer;

import java.util.*;

public class 튜플 {
    public int[] solution(String s) {
        int[] answer = {};
        String[] strs = s.replaceAll("[{}]", " ").trim().split(" ,");
        answer = new int[strs.length];
        HashSet<Integer> hs = new HashSet<Integer>();
        Arrays.sort(strs, (a, b) -> (a.length() - b.length()));
        int i = 0;
        for (String str : strs) {
            for (String st : str.split(",")) {
                int a = Integer.parseInt(st.trim());
                if (hs.contains(a))
                    continue;
                hs.add(a);
                answer[i++] = a;
            }
        }
        return answer;
    }
}