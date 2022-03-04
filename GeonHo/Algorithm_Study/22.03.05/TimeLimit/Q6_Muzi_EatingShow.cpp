/*
* problem : ������ �Թ� ���̺� (https://programmers.co.kr/learn/courses/30/lessons/42891)
*/

//�ڷᱸ���� ���� ���ذ� ����� �Ҹ��ϴ�.
//���α׷��ӽ� ���� ���̵� �򰡰� �̻��ϴ�.

//Solving Time : 1hour

#include <string>
#include <vector>
#include <queue>

using namespace std;

priority_queue<pair<long long, int>> pq;
bool isOver[200001] = { false };
long long leftCnt = 0;

int solution(vector<int> food_times, long long k) {
    leftCnt = food_times.size();
    for (int i = 0; i < food_times.size(); i++) {
        pq.push({ -food_times[i], i + 1 });
    }
    long long prev = 0;
    while (k >= (-pq.top().first - prev) * leftCnt && !pq.empty()) {
        k -= (-pq.top().first - prev) * leftCnt;
        prev = -pq.top().first;
        isOver[pq.top().second] = true;
        pq.pop();
        leftCnt--;
        while (!pq.empty() && prev == -pq.top().first) {
            isOver[pq.top().second] = true;
            pq.pop();
            leftCnt--;
        }
    }

    if (pq.empty()) return -1;

    int remain = k % leftCnt;
    int cnt = 0;
    for (int i = 1; i <= food_times.size(); i++) {
        if (!isOver[i] && cnt == remain) return i;
        else if (!isOver[i]) cnt++;
    }
}