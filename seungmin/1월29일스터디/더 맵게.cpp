

#include <bits/stdc++.h>

using namespace std;

struct compare
{
    bool operator()(int a, int b)
    {
        return a > b;
    }
};

int solution(vector<int> scoville, int K) {
    int answer = 0;

    priority_queue<int, vector<int>, compare> pq;

    for (int i = 0; i < scoville.size(); i++)
    {
        pq.push(scoville[i]);
    }

    int count = 0;

    // ���� ���� ��Ұ� K�̸� �̰� ������ 2�� �̻��� �� ������
    while (pq.top() < K && pq.size() != 1)
    {
        int s1 = pq.top();
        pq.pop();
        int s2 = pq.top();
        pq.pop();

        int s = s1 + 2 * s2;

        pq.push(s);
        count++;
    }

    // �ϳ��ۿ� ���� ��Ұ� K�̸��� ��� ����
    if (pq.size() == 1 && pq.top() < K) answer = -1;
    else answer = count;

    return answer;
}

int main()
{
    int sol = solution({ 1, 2, 3, 9, 10, 12 }, 7);

    cout << sol << endl;


   
    return 0;
}
