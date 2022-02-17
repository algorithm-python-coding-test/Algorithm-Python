/*
어려웠던 점
- 전체 숫자를 1씩 줄이며 매번 순회하니 시간초과 -> O(200,000,000 * 200,000)
- 이분탐색을 고려하지 못함 
*/

/*
- 이분탐색구현 -> O(log 200,000,000)
- left,right를 각각 최소, 최대로 돌다리를 건널 수 있는 인원으로 잡음
- mid명이 다리를 건널 수 있는지 체크

- 다리 맨앞에서부터, mid를 건너게 할 수 없다면 k값을 1씩 감소
- mid를 건너게 할 수 있다면 k값 초기화
- k가 0이 된다면 mid명이 다리를 건널 수 없음

효율성 테스트 기준
최대 : 3.66ms, 10.3MB
최소 : 2.48ms, 10.4MB

*/

#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 0;

    int left = 0, right = 200000000;
    int mid;

    while (left <= right) {
        mid = (left + right) / 2;

        int temp_k = k;
        int i;
        for (i = 0; i < stones.size(); i++) {
            if (stones[i] < mid) temp_k--;
            else temp_k = k;

            if (temp_k == 0) break;
        }
        if (i == stones.size()) left = mid + 1;
        else right = mid - 1;
    }
    answer = right;

    return answer;
}

int main()
{
    
    return 0;
}
