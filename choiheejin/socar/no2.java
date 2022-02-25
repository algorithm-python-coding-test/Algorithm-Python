package choiheejin.socar;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class no2 {
    public int solution(int[] numbers, int K) {
        List<Integer> answer = new ArrayList<>();
        dfs(numbers, answer, 0, K);
        if (answer.isEmpty()) {
            return -1;
        }
        int result = Integer.MAX_VALUE;
        for (int i = 0; i < answer.size(); i++) {
            if (result >= answer.get(i)) {
                result = answer.get(i);
            }
        }
        return result;
    }

    private void dfs(int[] numbers, List<Integer> answer, int count, int k) {
        if (count > numbers.length * (numbers.length - 1))
            return;

        boolean problem = false;
        for (int i = 0; i < numbers.length; i++) {
            if ((i < numbers.length - 1 && Math.abs(numbers[i] - numbers[i + 1]) > k)
                    || (i > 0 && Math.abs(numbers[i] - numbers[i - 1]) > k)) {
                int problemIndex = i < numbers.length - 1 && Math.abs(numbers[i] - numbers[i + 1]) > k ? i + 1 : i - 1;
                problem = true;
                for (int j = 0; j < numbers.length; j++) {
                    if (j != i && j != problemIndex
                            && (i == numbers.length - 1 || Math.abs(numbers[j] - numbers[i + 1]) <= k)
                            && (i == 0 || Math.abs(numbers[j] - numbers[i - 1]) <= k)
                            && (j == numbers.length - 1 || Math.abs(numbers[i] - numbers[j + 1]) <= k)
                            && (j == 0 || Math.abs(numbers[i] - numbers[j - 1]) <= k)) {
                        swap(numbers, i, j);
                        System.out.println("swap : " + i + " " + j + " -> " + Arrays.toString(numbers));
                        dfs(numbers, answer, count + 1, k);
                        swap(numbers, i, j);
                    }
                }
            }
        }
        if (!problem) {
            answer.add(count);
            System.out.println("완료 : " + count);
        }
    }

    void swap(int[] numbers, int i1, int i2) {
        int temp = numbers[i1];
        numbers[i1] = numbers[i2];
        numbers[i2] = temp;
    }

    public static void main(String[] args) {
        int[] numbers = { 10, 50, 40, 30, 20 };
        int k = 10;
        System.out.println(new no2().solution(numbers, k));
    }

}