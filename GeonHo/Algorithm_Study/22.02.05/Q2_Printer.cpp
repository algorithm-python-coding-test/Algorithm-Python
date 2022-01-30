/*
* problem : Printer (https://programmers.co.kr/learn/courses/30/lessons/42587)
* ������ ��û�� ������� �μ��ϵ�, �߿䵵�� ���� �������� ��µǵ��� ����Ʈ ��
* �� �� location�� ������ �� ��° ��µǴ��� ����
*
* ȿ�����׽�Ʈ
* �ּ� 0.01ms / 3.66MB �� ����
* �ִ� 0.02ms / 4.34MB �� ����
*/
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    //�������� ��� ������ ��Ÿ�� queue
    queue<pair<int, int>> q;
    //�켱������ ������ priority queue
    priority_queue<int> pq;
    //�Է¹��� priorities�� �̿��Ͽ� q�� pq�� �ʱ�ȭ
    for (int i = 0; i < priorities.size(); i++) {
        q.push({ priorities[i], i });
        pq.push(priorities[i]);
    }
    //��� ������ ����
    int cnt = 1;
    while (true) {
        //queue�� �� ������ �켱������ ��ü �켱�������� ���ٸ� 
        //�� �� ���Ҹ� ���� �� �ڷ� ������ �۾�
        if (q.front().first < pq.top()) {
            pair<int, int> elem = q.front();
            q.pop();
            q.push(elem);
            continue;
        }
        //queue�� �� ������ �켱������ ��ü �켱�������� ���� ���ٸ�
        //���� ������ ���� index�� location�� ������ �˻�
        //���� location�� ���� ���̶�� �ݺ��� Ż��
        pair<int, int> temp = q.front();
        if (temp.second == location) {
            break;
        }
        //location�� ���� ���� �ƴ϶�� �ش� ���Ҹ� queue���� ����
        //���� priority queue������ �켱������ ������ �ش�.
        q.pop();
        pq.pop();
        cnt++;
    }
    return cnt;
}

int main() {
    int ret = solution({ 2, 1, 3, 2 }, 2);
    cout << ret;
    return 0;
}
