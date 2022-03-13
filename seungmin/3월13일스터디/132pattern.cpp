// nums���� �޾ƿͼ� ������������ ����
// lo < hi �ǵ��� �ΰ��� ���� lo, hi�� ����, mid = ( lo + hi ) / 2
// mid���� �߽�����, nums�� �տ������� ��ȸ�Ѵ�
// (1) mid���� lo���� ���� ���´ٸ� { lo+1, hi } , {lo , hi+1} �� ���� ���̽��� ���� �ٽ� �˻�
// (2) mid���ʿ� �ִ� �ִ� �� �� �ϳ��� lo���� ũ�� mid���� ũ�ٸ� true
// (3) mid�����ʿ� �ִ� �� �� �ϳ��� lo���� ũ�� mid���� �۴ٸ� true
// (2),(3) ��� �ƴ϶��  { lo, mid } , {mid , hi} �ΰ��� ���̽��� ���� �ٽ� �˻�
// 
//  { -2,1,2,-2,1,2 } ���� �ȵ� �ߺ��Ǵ� ���� ������ �տ������� ��ȸ�ϴ� ����� ������ ����!

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

// ������ Ȱ���� ��

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
            // i��°���� ���� ���� �� ���� ���� ���� prefix_min[i]�� ����
            prefix_min[i] = min(prefix_min[i - 1], nums[i - 1]);
        }
        // index�� �����ϴ� stack
        stack<int> stk; //store index, nums[i] decreasing
        stk.push(0);
        for (int i = 1; i < n; i++) {
            // stack�� nums[i]���� ū ���鸸 �ΰ� �������� pop�ϱ�
            // stack�� �ִ� ������ i���� �տ� �ִ� index��
            while (!stk.empty() && nums[stk.top()] <= nums[i]) {
                stk.pop();
                // stk.top()�� Ȯ���ص� �Ǵ� ������
                // �տ������� Ȯ���Ͽ� nums[stk.top()] > nums[i]�� �����ϴ� nums[i]�� 
                // stk�� push�ϱ� ������ stk.top()�� ���� stk�� ����ִ� ��� ���� �� ���� �۴� (min_heap�� �Ƚᵵ �Ǵ� ����)
            }
            // stk�� �ִ� ��� j����
            // j < i �� nums[i] < nums[j]�� �����Ѵ�
            if (!stk.empty()) { //exist a larger element nums[j]
                // stk.top()�� prefix_min�� nums[i]���� �۴ٸ�
                // 
                // prefix_min[stk.top()] < nums[i] < nums[stk.top()] �� 
                // prefix_min[stk.top()]�� index < stk.top() < i �� �����ϹǷ� true
                if (prefix_min[stk.top()] < nums[i]) {
                    return true;
                }
                // stk�� top�� Ȯ���ص� �Ǵ� ����
                // stk�� push�Ǵ� ������ stk�� ������ ���� ���� ��� ������ prefix_min���� �۰ų� ���ƾ� �Ѵ�
                // �׷��� stk.top()�� prefix_min�� stk�� ��� prefix_min �� ���� ���� ���� �ȴ�
            }
            stk.push(i);
        }
        return false;
    }
};