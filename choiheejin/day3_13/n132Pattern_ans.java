package choiheejin.day3_13;

import java.util.*;

public class n132Pattern_ans {
    public boolean find132pattern(int[] nums) {
        if (nums == null || nums.length < 3) {
            return false;
        }
        int[] min = new int[nums.length];
        min[0] = nums[0];
        for (int i = 1; i < min.length; i++) {
            min[i] = Math.min(nums[i], min[i - 1]);
        }
        Stack<Integer> stack = new Stack<>();
        for (int i = nums.length - 1; i >= 0; i--) {
            if (nums[i] > min[i]) {
                while (!stack.empty() && stack.peek() <= min[i]) {
                    stack.pop();
                }
                if (!stack.empty() && stack.peek() < nums[i]) {
                    return true;
                }
                stack.push(nums[i]);
            }
        }
        return false;
    }
}
