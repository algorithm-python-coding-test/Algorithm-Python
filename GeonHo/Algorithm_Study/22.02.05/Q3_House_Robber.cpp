/*
* problem : House Robber
* �������� ��ġ�� ������ �湮�� ��, ���� ���� ���� ȹ���� �� �ִ� ���
* �� �� ������ �� ���� ���ÿ� �湮�� ���� ����.
*
* ȿ�����׽�Ʈ
* Runtime: 0 ms, faster than 100.00% of C++ online submissions for House Robber II.
* Memory Usage: 7.8 MB, less than 57.45% of C++ online submissions for House Robber II.
* 
* memset�� ����Ͽ� �迭 �ʱ�ȭ �ϴ°��� for���� ������ �� ���� ȿ����
*/
#include <iostream>
#include <vector>

using namespace std;

int dp[100];

int solution(vector<int> nums) {
    if (nums.size() <= 3) {
        if (nums.size() == 1) return nums[0];
        else if (nums.size() == 2) return max(nums[0], nums[1]);
        else {
            return max(max(nums[0], nums[1]), nums[2]);
        }
    }

    //1)ù��° ���� �����ؼ� �湮�ϴ� ��� -> ���������� �湮�� �� ����
    memset(dp, -1, sizeof(dp));
    dp[0] = nums[0];
    dp[1] = nums[1];
    dp[2] = max(nums[0] + nums[2], nums[1]);
    for (int i = 3; i < nums.size() - 1; i++) {
        dp[i] = max(max(dp[i - 1], dp[i - 2] + nums[i]), dp[i - 3] + nums[i]);
    }
    int ret1 = dp[nums.size() - 2];
    //2)ù��° ���� �������Ͽ� �湮�ϴ� ��� -> ���������� �湮�� �� ����
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    dp[1] = nums[1];
    dp[2] = nums[2];
    for (int i = 3; i < nums.size(); i++) {
        dp[i] = max(max(dp[i - 1], dp[i - 2] + nums[i]), dp[i - 3] + nums[i]);
    }
    int ret2 = dp[nums.size() - 1];

    return max(ret1, ret2);
}


int main() {
    int ret = solution({ 1, 3, 1 });
    cout << ret;
    return 0;
}