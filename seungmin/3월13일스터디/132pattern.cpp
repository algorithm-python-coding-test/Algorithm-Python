// nums값을 받아와서 오름차순으로 정렬
// lo < hi 되도록 두가지 값을 lo, hi에 저장, mid = ( lo + hi ) / 2
// mid값을 중심으로, nums를 앞에서부터 순회한다
// (1) mid값이 lo보다 먼저 나온다면 { lo+1, hi } , {lo , hi+1} 두 가지 케이스에 대해 다시 검사
// (2) mid왼쪽에 있는 있는 값 중 하나라도 lo보다 크고 mid보다 크다면 true
// (3) mid오른쪽에 있는 값 중 하나라도 lo보다 크고 mid보다 작다면 true
// (2),(3) 모두 아니라면  { lo, mid } , {mid , hi} 두가지 케이스에 대해 다시 검사
// 
//  { -2,1,2,-2,1,2 } 에서 안됨 중복되는 값이 있으면 앞에서부터 순회하는 방식이 먹히지 않음!

/*  
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

typedef struct node {
    int l, h;
} info;

using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        vector<int> sorted = nums;

        sort(sorted.begin(), sorted.end());

        int lo = 0, hi = sorted.size() - 1;
        int mid;

        queue<info> q;
        info temp;
        temp.l = lo; temp.h = hi;
        q.push(temp);

        while (!q.empty()) {
            temp = q.front();
            q.pop();

            lo = temp.l; hi = temp.h;
            mid = (lo + hi) / 2;
            int lo_val = sorted[lo], hi_val = sorted[hi], mid_val = sorted[mid];
            if (lo_val == mid_val) continue;

            int flag = 0;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] == lo_val) {
                    if (flag == 0) flag++;
                }
                else if (nums[i] == mid_val) {
                    if (flag == 0) {
                        temp.l++;
                        q.push(temp);

                        temp.l--;
                        temp.h--;
                        q.push(temp);
                    }
                    else if (flag == 1) flag++;
                }
                else if (flag == 1) {
                    if (nums[i] > lo_val && nums[i] > mid_val) return true;
                }
                else if (flag == 2) {
                    if (nums[i] > lo_val && nums[i] < mid_val) return true;
                }
            }

            if (flag == 2) {
                temp.h = mid;
                q.push(temp);

                temp.l = mid;
                temp.h = hi;
                q.push(temp);
            }
        }
        return false;
    }
};
int main() {
    
    vector<int> t = { -2,1,2,-2,1,2 };

    Solution s;
    bool b = s.find132pattern(t);
    
    cout << b << '\n';

    return 0;
} 
*/

// 스택을 활용한 답

class Solution {
public:
    //for each i, find the prefix min(nums[0:i])
    //for each i, fint the cloest larger element nums[j] (j<i)
    //  if prefix_min[j] < nums[i], then return true
    bool find132pattern(vector<int>& nums) {
        int const n = nums.size();
        vector<int> prefix_min(n);
        prefix_min[0] = INT_MAX;
        for (int i = 1; i < n; i++) {
            // i번째보다 이전 값들 중 가장 작은 값을 prefix_min[i]에 저장
            prefix_min[i] = min(prefix_min[i - 1], nums[i - 1]);
        }
        // index를 저장하는 stack
        stack<int> stk; //store index, nums[i] decreasing
        stk.push(0);
        for (int i = 1; i < n; i++) {
            // stack에 nums[i]보다 큰 값들만 두고 나머지는 pop하기
            // stack에 있는 값들은 i보다 앞에 있는 index들
            while (!stk.empty() && nums[stk.top()] <= nums[i]) {
                stk.pop();
                // stk.top()만 확인해도 되는 이유는
                // 앞에서부터 확인하여 nums[stk.top()] > nums[i]를 만족하는 nums[i]를 
                // stk에 push하기 때문에 stk.top()의 값이 stk에 들어있는 모든 값들 중 가장 작다 (min_heap을 안써도 되는 이유)
            }
            // stk에 있는 모든 j값은
            // j < i 와 nums[i] < nums[j]를 만족한다
            if (!stk.empty()) { //exist a larger element nums[j]
                // stk.top()의 prefix_min이 nums[i]보다 작다면
                // 
                // prefix_min[stk.top()] < nums[i] < nums[stk.top()] 와 
                // prefix_min[stk.top()]의 index < stk.top() < i 를 만족하므로 true
                if (prefix_min[stk.top()] < nums[i]) {
                    return true;
                }
                // stk의 top만 확인해도 되는 이유
                // stk에 push되는 조건은 stk에 이전에 먼저 들어온 모든 값들의 prefix_min보다 작거나 같아야 한다
                // 그래서 stk.top()의 prefix_min이 stk의 모든 prefix_min 중 가장 작은 값이 된다
            }
            stk.push(i);
        }
        return false;
    }
};