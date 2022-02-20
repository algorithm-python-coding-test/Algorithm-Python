// 튜플 알아보는 법
// 1개 있는 것은 [0]임
// 2개 있는 것은 1개 있는 것에서 없는 것
// 3개 있는 것은 2개있는 것에서 없는 것
// ...

// 차례대로 알아보는 법 (답을 저장하는 배열 필요, 답을 오름차순으로 정렬한 우선순위큐도 필요)
// 1. 우선순위 큐 사용 -> 요소 수가 작은 것부터 차례대로 정렬
// 2. 우선순위 큐 사용 -> 집합안의 요소를 정렬하고 요소의 개수를 비교하고 하나가 부족한 것을 찾아 답 배열에 append & 우선순위 큐에도 push
package choiheejin.kakao_winter_2019.first_try;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;

class 튜플 {
    public ArrayList<Integer> solution(String s) {

        // 문자열 처리
        ArrayList<Integer> list = new ArrayList<>();
        s = s.replace("{", "");
        s = s.replace("},", "-");
        s = s.replace("}}", "");

        String[] array = s.split("-");

        // 정렬
        Arrays.sort(array, new Comparator<String>() {
            public int compare(String o1, String o2) {
                return Integer.compare(o1.length(), o2.length());
            }
        });

        // 각 배열을 차례대로 조회하여 없는 것을 찾아 add
        for (int i = 0; i < array.length; i++) {
            String[] chars = array[i].split(",");
            for (int j = 0; j < chars.length; j++) {
                int num = Integer.parseInt(chars[j]);
                if (!list.contains(num)) {
                    list.add(num);
                }
            }
        }
        return list;
    }

    public static void main(String[] args) {
        for (int i : new 튜플().solution("{{2},{3,2},{3,2,1},{1,2,3,4}}")) {
            System.out.print(i + ", ");
        }

    }
}
