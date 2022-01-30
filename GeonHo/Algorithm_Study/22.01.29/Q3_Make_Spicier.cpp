/*
* problem : More Spicier
* ��� ������ ���ں� ������ K�̻����� ����� ���� ����� �ϴ� �ּ� Ƚ���� ����
* ���� ������ ���ں� ���� = ���� ���� ���� ������ ���ں� ���� + (�� ��°�� ���� ���� ������ ���ں� ���� * 2)
*
* ȿ�����׽�Ʈ
* �ּ� 19.84ms / 7.91MB �� ����
* �ִ� 231.14ms / 41.3MB �� ����
*/
#include <iostream>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int cnt = 0;
    priority_queue<int> pq;
    for (int i = 0; i < scoville.size(); i++) {
        //c++�� �켱����ť�� �������� ����
        pq.push(-scoville[i]);
    }
    //pq�� ������ ������ 2���̻� ���������鼭
    //���� ���� ���ں� ������ K �̸� �̶��
    while (pq.size() > 1 && -pq.top() < K) {
        int scv1 = -pq.top();
        pq.pop();
        int scv2 = -pq.top();
        pq.pop();

        int newScv = scv1 + 2 * scv2;
        pq.push(-newScv);
        cnt++;
    }

    int answer = (-pq.top() < K) ? -1 : cnt;
    return answer;
}

int main() {
    int ret = solution({ 1, 2, 3, 9, 10 ,12 }, 7);
    cout << ret;
    return 0;
}
