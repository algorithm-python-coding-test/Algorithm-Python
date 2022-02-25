//���� �����ϴ� ������δ� �־��� ��� O(N^2)�� ���Ҽ��� ����!
//max_element������ ���ְ� �ܼ� ������ �����̵� �˰������� ������ �ȴٸ� O(N)
//->�������� �ִ��� ��� ã�°��� �����. next_max�� �����Ѵ� �ص� ���ڰ� ������������ ���ĵǴ� ��� ��簪�� �˰� �־����
//O(NlogN) -> �־��� ��� �� 166���̹Ƿ� ������ ����ϵ�
//->����Ž���� ����� �� �ִ� �����ΰ�???
//����Ž���� �����Ϸ���, Ž���� ������ ���� ���ĵǾ� �ְų�, �ִ� �ּҰ��� �˰ų�...
//stones�� �ִ�, �ּҰ����� �����Ѵٸ�?

//����ð� 2.50ms / 3.55ms

//https://www.acmicpc.net/problem/2110

#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 1;
    //stones�� �ִ��� Ž��
    int stones_max = *max_element(stones.begin(), stones.end());
    int right = stones_max; int left = 1;
    //stones�� max, min���� ����Ž��
    while (left <= right) {
        bool pos = true;
        int mid = (right + left) / 2;
        int cnt = 0;
        //�����ؼ� k�� �̻��� stone�� mid���϶�� �ǳʶ� �� ����.
        for (int i = 0; i < stones.size(); i++) {
            if (stones[i] < mid) cnt++;
            else if (stones[i] >= mid) cnt = 0;

            if (cnt >= k) {
                pos = false;
                break;
            }
        }
        //���� mid������ �����ϴٸ� answer�� mid�� ����, ����Ž���� ����
        if (pos) {
            answer = mid;
            left = mid + 1;
        }
        //���� mid������ �Ұ����ϴٸ� �ٷ� ����Ž���� ����
        else right = mid - 1;
    }
    return answer;
}