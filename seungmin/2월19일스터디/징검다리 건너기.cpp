/*
������� ��
- ��ü ���ڸ� 1�� ���̸� �Ź� ��ȸ�ϴ� �ð��ʰ� -> O(200,000,000 * 200,000)
- �̺�Ž���� ������� ���� 
*/

/*
- �̺�Ž������ -> O(log 200,000,000)
- left,right�� ���� �ּ�, �ִ�� ���ٸ��� �ǳ� �� �ִ� �ο����� ����
- mid���� �ٸ��� �ǳ� �� �ִ��� üũ

- �ٸ� �Ǿտ�������, mid�� �ǳʰ� �� �� ���ٸ� k���� 1�� ����
- mid�� �ǳʰ� �� �� �ִٸ� k�� �ʱ�ȭ
- k�� 0�� �ȴٸ� mid���� �ٸ��� �ǳ� �� ����

ȿ���� �׽�Ʈ ����
�ִ� : 3.66ms, 10.3MB
�ּ� : 2.48ms, 10.4MB

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
