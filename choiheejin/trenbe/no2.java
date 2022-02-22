package choiheejin.trenbe;

import java.util.Comparator;
import java.util.PriorityQueue;

public class no2 {
    public int[] solution(int[] grade) {
        // [index, grade]
        PriorityQueue<int[]> students = new PriorityQueue<>(new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                if (o1[1] > o2[1]) {
                    return -1;
                } else if (o1[1] < o2[1]) {
                    return 1;
                } else {
                    return 0;
                }
            }
        });

        for (int i = 0; i < grade.length; i++) {
            int[] student = { i, grade[i] };
            students.add(student);
        }

        int[] answer = new int[grade.length];

        int count = 1;
        int firstIndex = count;
        int value = students.peek()[1];
        while (!students.isEmpty()) {
            int[] now = students.poll();
            if (value == now[1]) {
                answer[now[0]] = firstIndex;
            } else {
                value = now[1];
                firstIndex = count;
                answer[now[0]] = count;
            }
            count++;
        }
        return answer;
    }

    public static void main(String[] args) {
        int[] grade = { 3, 2, 1, 2 };
        new no2().solution(grade);
    }
}
