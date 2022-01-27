

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

    // 가장 작은 요소가 K미만 이고 개수가 2개 이상일 때 조합함
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

    // 하나밖에 없는 요소가 K미만일 경우 실패
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
