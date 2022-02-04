### 개인풀이

#최댓값을 더해가는 풀이
#통과하지 못함
#이런 방법으로 풀려면 모든 경우의 수를 전부 계산해서 그 중 최댓값을 계산해야 하는데
#그렇게 하면 for문을 너무 많이 돌리게 됨

def rob(nums):
    total_list = []
    for idx_first in range(len(nums)):
        print('idx_first:',idx_first)
        check_list = [0]*len(nums)
        number_list = nums.copy()
        total = 0

        total_num = calculate(check_list,number_list,total,idx_first)
        total_list.append(total_num)
    return max(total_list)

def calculate(check_list,number_list,total,idx_first):
    
    if check_list[idx_first]==1:
        
        idx_max = number_list.index(max(number_list))
    else:
        idx_max=idx_first
    
    if check_list[idx_max]=='X' or check_list[idx_max]==1:
        return False
    
    elif check_list[idx_max]==0:
        total+=number_list[idx_max]
        check_list[idx_max]=1
        number_list[idx_max]=-1

    if idx_max==len(number_list)-1:
        idx_right=0
        idx_left=idx_max-1
    elif idx_max==0:
        idx_right=idx_max+1
        idx_left=len(number_list)-1
    else:
        idx_right=idx_max+1
        idx_left=idx_max-1
    
    
    check_list[idx_left]='X'
    number_list[idx_left]=-1
    check_list[idx_right]='X'
    number_list[idx_right]=-1
    print('after:',check_list,number_list,total,idx_first)
    if 0 in check_list:
        
        return calculate(check_list,number_list,total,idx_max)
        
    else:
        return total
    

### 다른사람 풀이

##다이나믹 프로그래밍
##첫번째 값과 마지막 값은 동시에 포함되면 안되기 때문에
##각각 빼주고 계산하여 최댓값 반환

def rob(nums):
        if not nums:
            return 0
        
        def max_money(nums):
            nums = [0]+nums
            for i in range(3,len(nums)):
                print(nums)
                nums[i]+=max(nums[i-3],nums[i-2])
            return max(nums[-1],nums[-2])
        
        return max(max_money(nums[1:]),max_money(nums[:-1])) if len(nums) > 2 else max(nums)

