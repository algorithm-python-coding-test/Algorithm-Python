package choiheejin.trenbe;

import java.util.HashMap;
import java.util.Map;

public class no1 {
    public String solution(String s) {
        s = s.toLowerCase();
        Map<Character, Integer> map = new HashMap<>();
        for (int i = 'a'; i <= 'z'; i++) {
            map.put((char) i, 0);
        }
        for (int i = 0; i < s.length(); i++) {
            map.put(s.charAt(i), map.get(s.charAt(i)) + 1);
        }

        int max = 0;
        String maxChar = "";
        for (int i = 'a'; i <= 'z'; i++) {
            int now = map.get((char) i);
            if (max < now) {
                max = now;
                maxChar = "" + ((char) i);
            } else if (max == now) {
                maxChar += ((char) i);
            }
        }

        return maxChar;
    }

    public static void main(String[] args) {
        String s = "BBAabcbddDd";
        System.out.println(new no1().solution(s));

    }
}
