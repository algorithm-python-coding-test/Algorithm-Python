# 3, 1, 3, 1, 5, 6, 3, 4
# dp[0] = 3
# dp[1] = max([3], [] + [1]) => 3
# dp[2] = [3, 1, 3] => max([3, 1], [3] + [3]) = 3 + 3
# dp[3] = [3, 1, 3, 1] => max([3, 1, 3], [3, 1] + [1]) = 3 + 3
# dp[7] = [1, 2, 3, 1, 5, 6, 3, 4] => max([1, 2, 3,.., 3], [2, 3, 1, 5, 6] + [4]) 
# 결국 다시 돌아오면 제일 끝 인덱스를 넣을 경우와 넣지 않을 경우 두가지가 있다.
# 따라서 두가지 경우에 대한 Dp 테이블을 관리한다.
class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        elif len(nums) == 2:
            return max(nums[0], nums[1])
        # 0~len-2 최댓값을 저장하는 dp
        dpFrom0To_2 = [0] * (len(nums))
        dpFrom0To_2[0] = nums[0]
        dpFrom0To_2[1] = max(nums[0], nums[1])
        # 1~len-3 최댓값을 저장하는 dp
        dpFrom1To_3 = [0] * (len(nums))
        dpFrom1To_3[1] = nums[1]
        dpFrom1To_3[2] = max(nums[1], nums[2])
        # dpFrom0To_2 채우기
        for i in range(2, len(nums)-1):
            dpFrom0To_2[i] = max(dpFrom0To_2[i-1], dpFrom0To_2[i-2] + nums[i])
        # dpFrom1To_1 채우기
        for i in range(3, len(nums)-2):
            dpFrom1To_3[i] = max(dpFrom1To_3[i-1], dpFrom1To_3[i-2] + nums[i])
        
        return max(dpFrom0To_2[-2], dpFrom1To_3[-3] + nums[-1])