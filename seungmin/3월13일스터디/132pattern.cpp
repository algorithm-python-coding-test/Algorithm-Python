// nums값을 받아와서 오름차순으로 정렬
// lo < hi 되도록 두가지 값을 lo, hi에 저장, mid = ( lo + hi ) / 2
// mid값을 중심으로, nums를 앞에서부터 순회한다
// (1) mid값이 lo보다 먼저 나온다면 { lo+1, hi } , {lo , hi+1} 두 가지 케이스에 대해 다시 검사
// (2) mid왼쪽에 있는 있는 값 중 하나라도 lo보다 크고 mid보다 크다면 true
// (3) mid오른쪽에 있는 값 중 하나라도 lo보다 크고 mid보다 작다면 true
// (2),(3) 모두 아니라면  { lo, mid } , {mid , hi} 두가지 케이스에 대해 다시 검사
// 
//  { -2,1,2,-2,1,2 } 에서 안됨 중복되는 값이 있으면 앞에서부터 순회하는 방식이 먹히지 않음!


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