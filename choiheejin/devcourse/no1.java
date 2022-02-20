// arr 길이는 1000개
// 정렬 후 제일 중간 값...?
// 임계값이 여러개라면 그 중 가장 작은 값이 되어야함
// [중간 값 미만] -  중간값 - [중간 값 이상]
// 따라서 중간값은 왼쪽 값들 중 제일 큰 값 +1 이 되면 된다.
// 중간 인덱스를 뚝 자르는데 그 떄 왼쪽 값과 오른쪽 값이 같을 경우
// 그것보다 작은 값을 가진 인덱스를 찾아 +1 한 것과 지금 값 + 1한 것 중 비교
package choiheejin.devcourse;

import java.util.Arrays;

public class no1 {
    public int solution(int[] arr) {
        // 일단 정렬
        Arrays.sort(arr);

        // 제일 중간 값 찾기
        int mid = (int) arr.length / 2;

        if (mid == 0) {
            return 0;
        }

        if (arr[mid - 1] != arr[mid]) {
            return arr[mid - 1] + 1;
        }

        // 왼쪽 최댓값과 오른쪽 최솟값이 값다면?
        int little_cursor = mid - 1;
        int big_cursor = mid;
        while (little_cursor >= 0) {
            if (arr[mid - 1] > arr[little_cursor]) {
                break;
            }
            --little_cursor;
        }
        while (big_cursor < arr.length) {
            if (arr[mid - 1] < arr[big_cursor]) {
                break;
            }
            ++big_cursor;
        }
        if (little_cursor < 0 && big_cursor == arr.length) {
            return 0;
        }
        if (little_cursor < 0) {
            return arr[big_cursor - 1] + 1;
        }
        if (big_cursor == arr.length) {
            return arr[little_cursor] + 1;
        }
        big_cursor--;

        int little_gap = arr.length - (little_cursor + 1) - (little_cursor + 1);
        int big_gap = big_cursor + 1 - (arr.length - big_cursor - 1);

        if (little_gap <= big_gap) {
            return arr[little_cursor] + 1;
        }
        return arr[big_cursor] + 1;
    }

    public static void main(String[] args) {
        int[] arr = {
                0, 0, 0, 0, 3
        };
        System.out.println(new no1().solution(arr));
    }
}
