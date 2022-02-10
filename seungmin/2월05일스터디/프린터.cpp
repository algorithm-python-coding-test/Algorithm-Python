#include <bits/stdc++.h>

using namespace std;

struct node
{
    int priority;
    int location;
};

int solution(vector<int> priorities, int location) {

    int answer = 0;

    vector<node> new_priorities;
    priority_queue<int, vector<int>> pq;

    // 매개인자 priorities 정보를 받아옴
    for (int i = 0; i < priorities.size(); i++)
    {
        // 우선순위는 max_heap에 저장
        pq.push(priorities[i]);

        node add_node;
        add_node.priority = priorities[i];
        // 처음 대기목록에 있을때의 위치를 저장하기 위함
        add_node.location = i;

        new_priorities.push_back(add_node);
    }

    // new_priorities에서 사용될 위치index값
    int index = 0;
    // location에 있는 문서를 인쇄했는지 판단하는 변수
    int find_flag = 0;

    // max_heap의 top이 가장먼저 프린트할 대상
    while(!pq.empty())
    {
        int top_priority = pq.top();
        pq.pop();
        answer++;

        while (1)
        {
            // 현재 프린터 맨 앞의 문서가 top_priority가 아니면 맨 뒤로 보냄
            if (new_priorities[index].priority != top_priority)
            {
                node temp = new_priorities[index];
                new_priorities.push_back(temp);
                index++;
            }
            // 현재 문서가 top_priority가 맞다면 출력하는데
            else
            {
                // location에 있던 문서라면 작업끝
                if (new_priorities[index].location == location)
                    find_flag = 1;
                index++;
                break;
            }
            
        }
        if (find_flag) break;
    }
    return answer;
}

