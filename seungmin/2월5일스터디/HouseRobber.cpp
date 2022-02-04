#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {

        if (nums.size() == 1) return nums[0];

        // ù���� �и� ������ ���а�, 
        // ������ �и� ù���� ���ϴ�

        // ù��~������ �ι�° ���� �ж�
        int money1 = rob1(nums, 0, nums.size() - 2);
        // �ι�°��~������ �ж�
        int money2 = rob1(nums, 1, nums.size() - 1);

        if (money1 > money2) return money1;
        else return money2;
    }

    int rob1(vector<int>& nums, int start_index, int end_index) {

        int money;

        // �� ������
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
        // �� �������� 3���̻� �϶�, s = max( s1, s2 )
        else
        {
            int s1 = nums[start_index];

            int s2;
            if (nums[start_index] > nums[start_index + 1]) s2 = nums[start_index];
            else s2 = nums[start_index + 1];

            int s;

            // �������� ���� �ϳ��� �ö�, ��ĥ �� �ִ� ���� ū ���� s

            for (int i = start_index + 2; i <= end_index; i++)
            {
                // ���ο� ���� ������ �ִ� ��
                int a = nums[i];

                // �̿��� ���� �� �� �����Ƿ� 
                // s1+a�� s2 �� �� ū���� s
                if ((s1 + a) > s2) s = s1 + a;
                else s = s2;

                // s1, s2 �ֽ�ȭ
                s1 = s2;
                s2 = s;
            }
            money = s;
        }
        return money;
    }
};