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

    // �Ű����� priorities ������ �޾ƿ�
    for (int i = 0; i < priorities.size(); i++)
    {
        // �켱������ max_heap�� ����
        pq.push(priorities[i]);

        node add_node;
        add_node.priority = priorities[i];
        // ó�� ����Ͽ� �������� ��ġ�� �����ϱ� ����
        add_node.location = i;

        new_priorities.push_back(add_node);
    }

    // new_priorities���� ���� ��ġindex��
    int index = 0;
    // location�� �ִ� ������ �μ��ߴ��� �Ǵ��ϴ� ����
    int find_flag = 0;

    // max_heap�� top�� ������� ����Ʈ�� ���
    while(!pq.empty())
    {
        int top_priority = pq.top();
        pq.pop();
        answer++;

        while (1)
        {
            // ���� ������ �� ���� ������ top_priority�� �ƴϸ� �� �ڷ� ����
            if (new_priorities[index].priority != top_priority)
            {
                node temp = new_priorities[index];
                new_priorities.push_back(temp);
                index++;
            }
            // ���� ������ top_priority�� �´ٸ� ����ϴµ�
            else
            {
                // location�� �ִ� ������� �۾���
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

