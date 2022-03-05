// 일단 키워드 모두 저장하고
// 입력중인것도 모두 저장후
// 입력중인 키워드 하나씩 꺼내서 앞부분이 일치하는 것에 대한 개수를 세어 출력
package choiheejin.swma;

import java.util.*;

public class no1 {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        sc.nextLine();
        String[] keywords = new String[N];
        for (int i = 0; i < N; i++) {
            keywords[i] = sc.nextLine();
        }
        int T = sc.nextInt();
        sc.nextLine();
        String[] inputs = new String[T];
        for (int i = 0; i < T; i++) {
            inputs[i] = sc.nextLine();
        }

        int[] answer = new int[T];
        for (int i = 0; i < T; i++) {
            String input = inputs[i];
            for (int j = 0; j < N; j++) {
                String keyword = keywords[j];
                if (keyword.length() >= input.length()
                        && input.equals(keyword.substring(0, input.length()))) {
                    answer[i]++;
                }
            }
            System.out.println(answer[i]);
        }
    }
}
