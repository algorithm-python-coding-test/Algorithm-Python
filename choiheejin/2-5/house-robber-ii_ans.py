class Solution:
    def rob(self, nums: list[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        # if we rub, record it on first column 0
        # first exclude the last house
        dp = [[0] * 2 for _ in range(len(nums) - 1)]
        dp[0][0] = nums[0]
        for i in range(1, len(nums) - 1):
            dp[i][0] = dp[i - 1][1] + nums[i]
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][1])

        temp = max(dp[len(nums) - 2])

        # then exclude the first house
        dp[0][0] = nums[1]
        for i in range(1, len(nums) - 1):
            dp[i][0] = dp[i - 1][1] + nums[i + 1]
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][1])

        return max(temp, max(dp[len(nums) - 2]))