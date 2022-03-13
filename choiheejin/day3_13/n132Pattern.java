// 132 패턴의 조건 : 세가지 중 가운데가 제일 크고 그다음에 오른쪽 그다음에 왼쪽 순으로 커야함
// 모든 요소에 대해
// i먼저 정하고
// i보다 큰 애들 중 nums[i]보다 값이 큰 애들을 골라 j로 지정
// j보다 큰 애들 중 nums[i] < nums[k] < nums[j]를 만족하는 k를 찾으면 리턴 true
// 아이디어 차용(?) : 
// 브루트포스 : 현재 내 위치에서 왼쪽에 있는 것들 중 최솟값이 오른쪽에 있는 것들 중 나보다 작은 애들 중에 최댓값보다 작으면 된다.=> O(n**3)
// 효율성을 높이기 위해
// 왼쪽부터 누적 최솟값 찾아나가기
// 미리 현재까지의 최소값을 구해놓고 O(n)
// 동일하게 왼쪽부터 오른쪽 값을 비교해나가면 O(n**2)
// O(n**2)도 여전히 40,000,000,000 너무 오래걸림
// 오른쪽 값을 빨리 구하는 법
// 오른쪽도 마찬가지로 누적 최솟값 구하기 O(n)
// 오른쪽부터 차례로 살펴보면
// 현재 min보다 작다면 
package choiheejin.day3_13;

import java.util.*;

public class n132Pattern {

    int[][] sortedNums;

    public boolean find132pattern(int[] nums) {
        return true;
    }

    public static void main(String[] args) {
        int[] nums = { -1, 3, 2, 0 };
        System.out.println(new n132Pattern().find132pattern(nums));
    }

}
