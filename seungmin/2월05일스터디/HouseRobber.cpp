#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {

        if (nums.size() == 1) return nums[0];

        // 첫집을 털면 끝집을 못털고, 
        // 끝집을 털면 첫집을 못턴다

        // 첫집~끝에서 두번째 집을 털때
        int money1 = rob1(nums, 0, nums.size() - 2);
        // 두번째집~끝집을 털때
        int money2 = rob1(nums, 1, nums.size() - 1);

        if (money1 > money2) return money1;
        else return money2;
    }

    int rob1(vector<int>& nums, int start_index, int end_index) {

        int money;

        // 총 가구수
        int total_count = end_index - start_index + 1;

        if (total_count == 1)
        {
            money = nums[start_index];
        }
        else if (total_count == 2)
        {
            if (nums[start_index] > nums[end_index]) money = nums[start_index];
            else money = nums[end_index];
        }
        // 총 가구수가 3개이상 일때, s = max( s1, s2 )
        else
        {
            int s1 = nums[start_index];

            int s2;
            if (nums[start_index] > nums[start_index + 1]) s2 = nums[start_index];
            else s2 = nums[start_index + 1];

            int s;

            // 도둑질할 집이 하나씩 늘때, 훔칠 수 있는 가장 큰 돈이 s

            for (int i = start_index + 2; i <= end_index; i++)
            {
                // 새로운 집이 가지고 있는 돈
                int a = nums[i];

                // 이웃한 집을 털 수 없으므로 
                // s1+a와 s2 중 더 큰값이 s
                if ((s1 + a) > s2) s = s1 + a;
                else s = s2;

                // s1, s2 최신화
                s1 = s2;
                s2 = s;
            }
            money = s;
        }
        return money;
    }
};