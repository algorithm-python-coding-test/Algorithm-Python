// 각 스테이지의 실패율 구하는 법
// 스테이지와 같은 값 개수 / 스테이지 이상의 값 개수
// 사용자 기록을 한번 돌며 스테이지별로 있는 유저의 명수 저장
// 스테이지 목록을 한번 돌며 실패율 구하고 sort
package choiheejin.kakao_blind_2019.after;

import java.util.*;

public class 실패율 {
    private float[] failure = new float[501];

    public int[] solution(int N, int[] stages) {
        int[] records = new int[N + 2];
        for (int i = 0; i < stages.length; i++) {
            records[stages[i]]++;
        }

        Integer[] stageNum = new Integer[N];
        stageNum[0] = 0;
        for (int i = 1; i <= N; i++) {
            int sum = 0;
            stageNum[i - 1] = i;
            for (int j = i; j <= N + 1; j++) {
                sum += records[j];
            }
            if (sum != 0)
                failure[i] = ((float) records[i] / sum);
        }
        Arrays.sort(stageNum, (o1, o2) -> {
            if (failure[(int) o1] == failure[(int) o2]) {
                return o1 - o2;
            } else {
                if (failure[o1] - failure[o2] > 0)
                    return -1;
                else if (failure[o1] - failure[o2] == 0)
                    return 0;
                else
                    return 1;
            }
        });
        return Arrays.stream(stageNum).mapToInt(Integer::intValue).toArray();
    }
}
