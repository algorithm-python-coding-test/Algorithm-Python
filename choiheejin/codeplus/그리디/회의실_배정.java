// https://www.acmicpc.net/problem/1931
// 회의를 최대한 많이 채우려면 일단 제일 회의 길이가 작은 것부터 채워나가야한다.
// 회의의 수가 100,000이므로 PriorityQueue 사용
// 어떻게 채워나갈 것인가?
// 0 ~ 2**31 ==> 최대시간이 2**31이라는거....
// 비트마스크 꼬!!
package choiheejin.codeplus.그리디;

import java.util.*;
import java.io.*;

public class 회의실_배정 {

    static PriorityQueue<int[]> q = new PriorityQueue<>((o1, o2) -> o1[0] - o2[0]);

    static int time = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        for (int i = 0; i < n; i++) {
            String[] s = br.readLine().split(" ");
            int a = Integer.parseInt(s[0]);
            int b = Integer.parseInt(s[1]);
            int currTime = 0;
            for (int j = a; j < b; j++) {
                currTime += 1 << j;
            }
            q.offer(new int[] { b - a, currTime });
        }

        int count = 0;
        while (!q.isEmpty()) {
            int[] curr = q.poll();
            // 겹치는게 없으면
            if ((curr[1] & time) == 0) {
                System.out.println(curr[0] + " " + curr[1]);
                time |= curr[1];
                count++;
            }
        }

        System.out.println(count);
    }
}
