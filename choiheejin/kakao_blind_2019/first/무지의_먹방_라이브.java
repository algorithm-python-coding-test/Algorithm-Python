// k가 일단 한 바퀴를 도는 시간보다 크다면
// k - n 을 하고 남은 것이 앞으로 먹을 것인디
// n이 매 바퀴마다 바뀔 것이다. 어떻게 바뀌느냐
// 가장 적게 걸리는 음식부터 해당 시간에 1개씩 빠져나갈 것이다.
// 일단 Priorityq에 모든 음식들과 걸리는 시간을 집어넣고
// 제일 적게 걸리는 것을 하나 peek()하여 
// 해당 시간 * PriorityQueue.size() >= k이면
// 그 안에서 음식을 구하면 되고
// < k이면
// k도 해당 시간 * PriorityQueue.size() 만큼 빼주고 
// Priorityq를 poll()(같은 시간이 모두 빠질 때까지)한 다음
// 다시 제일 적게 걸린것을 peek()하여 검사한다.
// 정확성: 38.8
// 효율성: 7.1
// 합계: 46.0 / 100.0
package choiheejin.kakao_blind_2019.first;

import java.util.PriorityQueue;

public class 무지의_먹방_라이브 {
    public int solution(int[] food_times, long k) {

        PriorityQueue<int[]> pq = new PriorityQueue<>((o1, o2) -> o1[0] - o2[0]);
        for (int i = 0; i < food_times.length; i++) {
            pq.offer(new int[] { food_times[i], i + 1 });
        }

        while (k > 0 && pq.size() > 0) {
            int[] first = pq.peek();
            if (pq.size() * first[0] >= k) {
                long remain = k % pq.size();
                PriorityQueue<int[]> newPq = new PriorityQueue<>((o1, o2) -> o1[1] - o2[1]);
                newPq.addAll(pq);
                int answer = 0;
                for (int i = 0; i <= remain; i++)
                    answer = newPq.poll()[1];
                return answer;
            } else {
                k -= pq.size() * first[0];
                while (pq.peek()[0] == first[0]) {
                    pq.poll();
                    if (pq.size() == 0)
                        break;
                }
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        int[] food_times = { 1, 1, 2, 1 };
        long k = 6;
        System.out.println(new 무지의_먹방_라이브().solution(food_times, k));
    }
}
