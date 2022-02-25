package choiheejin.kakao_internship_2021.first;

import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.Set;

public class 숫자_문자열과_영단어 {
    public int solution(String s) {
        Map<String, String> map = new HashMap<>();
        map.put("zero", "0");
        map.put("one", "1");
        map.put("two", "2");
        map.put("three", "3");
        map.put("four", "4");
        map.put("five", "5");
        map.put("six", "6");
        map.put("seven", "7");
        map.put("eight", "8");
        map.put("nine", "9");

        Set<String> keys = map.keySet();

        Iterator<String> iterator = keys.iterator();

        while (iterator.hasNext()) {
            String key = iterator.next();

            while (s.contains(key)) {
                s = s.replace(key, map.get(key));
            }

        }
        return Integer.parseInt(s);
    }

    public static void main(String[] args) {
        String s = "one4seveneight";
        new 숫자_문자열과_영단어().solution(s);
    }
}
