

/*
2�ð� �ҿ�

- ���� �����ϴµ� �ð��� O(1)�� hash_map�� ����ر�� ��
- ��ü �����͸� hash_map�� ���� ��, �����Ǵ� ��鸸 ���� �����غ���� ��

- ���õ� ���� ��,�Ʒ��� �ű涧 ȿ������ �̵��� ����
  �������� ���� �� �� ���õ� ���� �ٷ� ������(prev), ������(next)�� index���� �����ϰ� �ִ� ����ü ND���
- ������ ���� index�� stack�� �־� �����ϰ�, ���� ���� ���� �� �� ���� ������, �������� prev,next�� ���Ḯ��Ʈó�� �� ��������
- ������ �� ���� ������, �������� prev,next�� �� ��������
- ���� �������� ������ ���� ���� ���� �����Ǳ� ������, ������ ���� ������, ������ ������ �ְ�� ���� ����

ȿ����  �׽�Ʈ
�׽�Ʈ 1 ��	��� (120.50ms, 61.9MB)
�׽�Ʈ 2 ��	��� (108.91ms, 61.9MB)
�׽�Ʈ 3 ��	��� (124.28ms, 61.9MB)
�׽�Ʈ 4 ��	��� (111.77ms, 62.1MB)
�׽�Ʈ 5 ��	��� (102.26ms, 62.2MB)
�׽�Ʈ 6 ��	���� (�ð� �ʰ�)
�׽�Ʈ 7 ��	��� (31.99ms, 27.1MB)
�׽�Ʈ 8 ��	��� (32.15ms, 29MB)
�׽�Ʈ 9 ��	���� (�ð� �ʰ�)
�׽�Ʈ 10 ��	���� (�ð� �ʰ�)
ä�� ���
��Ȯ��: 30.0
ȿ����: 49.0
�հ�: 79.0 / 100.0

- ���Ḯ��Ʈ ���·� Ǫ�°��� ������, hash_table�� �̿��Ҷ� key���� �����ϴ� �ð��� �ϳ� �ҿ�Ǵ°� ���� O(1) 
- �� �õ������� �������� ����
*/


#include <string>
#include <vector>

using namespace std;

#include <unordered_map>
#include <stack>

// hash_table�� value�� ����� ����ü ����
typedef struct node
{
    int prev;
    int next;
    char del = 0;
} ND;

string solution(int n, int k, vector<string> cmd) {
    string answer = "";

    unordered_map<int, ND> chart;

    for (int i = 0; i < n; i++) {
        ND temp;

        if (i == 0) temp.prev = -1;
        else temp.prev = i - 1;

        if (i == (n - 1)) temp.next = -1;
        else temp.next = i + 1;
        
        chart[i] = temp;
    }

    stack<int> dels;

    int curr = k;

    for (int i = 0; i < cmd.size(); i++) {

        string cur_cmd = cmd[i];
        if (cur_cmd[0] == 'U') {
            int up_cnt = stoi(cur_cmd.substr(2));

            // up_cnt�� ���� �̵�
            for (int i = 0; i < up_cnt; i++) 
                curr = chart[curr].prev;
        }
        else if (cur_cmd[0] == 'D') {
            int down_cnt = stoi(cur_cmd.substr(2));

            // down_cnt�� �Ʒ��� �̵�
            for (int i = 0; i < down_cnt; i++) 
                curr = chart[curr].next;
        }
        else if (cur_cmd[0] == 'C') {
            ND* p = &chart[curr];
            // ���� �Ǿ����� ����
            chart[curr].del = 1;
            // stack�� ������ ���� index ����
            dels.push(curr);

            int next_curr = *p.next;
            int prev_curr = chart[curr].prev;

            if (next_curr != -1) {
                chart[next_curr].prev = prev_curr;
                // ���õ� ���� �� ������
                curr = next_curr;
            }
            else // ���õ� ���� �������� �����Ƿ� ������
                curr = prev_curr;

            if (prev_curr != -1) 
                chart[prev_curr].next = next_curr;
        }
        else {
            // ������ ���� index
            int back_index = dels.top();
            dels.pop();

            chart[back_index].del = 0;

            int prev = chart[back_index].prev;
            int next = chart[back_index].next;

            if (prev != -1) 
                chart[prev].next = back_index;

            if (next != -1) 
                chart[next].prev = back_index;
        }
    }

    for (int i = 0; i < n; i++) {
        if (chart[i].del == 0)
            answer.push_back('O');
        else
            answer.push_back('X');
    }
    return answer;
}
