/*
* problem : ¡�˴ٸ� �ǳʱ� (https://programmers.co.kr/learn/courses/30/lessons/64062)
*/

//stones�迭�� ũ�� : 200,000, ���Ұ��� �ִ� : 200,000,000 -> �ܼ��������� ȿ���� ��� ���� �Ұ����Ұ�
//�������� ���ϴ°� : ���ӵ� k���� ���ҿ��� �������� �ִ񰪵� �� ���� ���� ��
//�����̵� ������ �˰����� �� �����ϸ� O(N...)�뿡 ���� �� ���� ������?
//ȿ���� ��ƺ����� �ð� ���� ����...

//Solving Time : 1h 40min
//��Ȯ�� 64.1, ȿ���� 25.6 -> 89.7

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> stones, int k) {
    int range_max = *max_element(stones.begin(), stones.begin() + k);
    int range_max_idx = max_element(stones.begin(), stones.begin() + k) - stones.begin();
    int left = 0, right = k - 1;
    int ret = range_max;
    int next_max = 0, next_max_idx = 0;
    while (right < stones.size()) {
        if (stones[right] >= range_max) {
            range_max = stones[right];
            range_max_idx = right;
            next_max = 0, next_max_idx = 0;
        }
        else if (stones[right] >= next_max) {
            next_max = stones[right];
            next_max_idx = right;
        }
        if (left > range_max_idx) {
            range_max = *max_element(stones.begin() + left, stones.begin() + next_max_idx);
            range_max_idx = max_element(stones.begin() + left, stones.begin() + next_max_idx) - (stones.begin() + left);
            range_max_idx = next_max < range_max ? range_max_idx : next_max_idx;
            range_max = next_max < range_max ? range_max : next_max;
            next_max = 0, next_max_idx = 0;
        }
        if (ret > range_max) ret = range_max;
        left++; right++;
    }
    return ret;
}
