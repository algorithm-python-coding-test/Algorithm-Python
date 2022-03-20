package choiheejin.socar2;

import java.util.*;

public class no2 {
    int min = Integer.MAX_VALUE;
    int[] arr;

    public int solution(int[] numbers, int K) {
        arr = new int[numbers.length];
        for (int i = 0; i < numbers.length; i++) {
            arr[i] = numbers[i];
        }
        Arrays.sort(arr);
        boolean next_exists = true;
        while (next_exists) {
            for (int i = 0; i < arr.length; i++) {
                System.out.print(arr[i] + " ");
            }
            System.out.println();
            // k이하인지 체크
            boolean less_than_k = true;
            for (int i = 0; i < arr.length - 1; i++) {
                if (Math.abs(arr[i] - arr[i + 1]) > K) {
                    less_than_k = false;
                    break;
                }
            }
            if (!less_than_k) {
                next_exists = next_permutation(arr);
                continue;
            }

            // k이하라면 이 배열로 swap 최소 횟수구하기
            int count = 0;
            int[] from = new int[numbers.length];
            for (int i = 0; i < arr.length; i++) {
                from[i] = numbers[i];
            }
            for (int i = 0; i < arr.length; i++) {
                int value = arr[i];
                for (int j = 0; j < from.length; j++) {
                    if (i != j && from[j] == value) {
                        swap(from, i, j);
                        count++;
                    }
                }
            }
            min = Math.min(min, count);

            next_exists = next_permutation(arr);

        }
        return min;
    }

    boolean next_permutation(int[] arr) {
        int i = arr.length - 1;
        while (i > 0 && arr[i - 1] >= arr[i])
            i -= 1;
        if (i <= 0)
            return false;
        int j = arr.length - 1;
        while (arr[j] <= arr[i - 1])
            j -= 1;
        swap(arr, i - 1, j);
        j = arr.length - 1;
        while (i < j) {
            swap(arr, i, j);
            i += 1;
            j -= 1;
        }
        return true;
    }

    void swap(int[] arr, int index1, int index2) {
        int temp = arr[index1];
        arr[index1] = arr[index2];
        arr[index2] = temp;
    }

    public static void main(String[] args) {
        int[] numbers = { 10, 40, 30, 20 };
        int k = 20;
        System.out.println(new no2().solution(numbers, 20));
    }
}
