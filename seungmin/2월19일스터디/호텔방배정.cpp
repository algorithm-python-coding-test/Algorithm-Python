/*
������� ��
 - left = 0, right =  1.0e12 �� �̺�Ž������ �õ�
 - left, right, mid�� ������ ã�� ���ϰ� ����

*/


/*
Ǯ�� Ȯ�� -> hashmap (hashtable) �� ����

ȿ���� �׽�Ʈ ����
�ִ� : 194.45ms, 51.8MB
�ּ� : 107.77ms, 52.3MB

*/


#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

// �濡 ���� ����
typedef struct node
{
    // ���� �ִ��� ������
    char is_occupied = 0;
    // �θ� ��� ����
    long long parent = -1;
} ND;

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;

    // �� ���� ������ ��� �ִ� hash_table
    unordered_map<long long, node> hash_map;

    for (int i = 0; i < room_number.size(); i++) {

        // ���� ���ϴ� ��
        long long want_index = room_number[i];

        // ���� ����
        ND want_node = hash_map[want_index];

        // �մ��� ���ٸ� �ٷ� ����
        if (want_node.is_occupied == 0) {
            
            want_node.is_occupied = 1;
            want_node.parent = want_index + 1;
            hash_map[want_index] = want_node;

            answer.push_back(want_index);
        }
        else {
            // �� ���� ã�� ������ �湮�� ����� ������ ������ �迭
            vector<long long> index;
            index.push_back(want_index);

            long long parent_index = want_node.parent;
            ND parent_node = hash_map[parent_index];
            index.push_back(parent_index);

            while (parent_node.is_occupied != 0) {
                parent_index = parent_node.parent;
                parent_node = hash_map[parent_index];
                index.push_back(parent_index);
            }

            parent_node.is_occupied = 1;
            parent_node.parent = parent_index + 1;
            hash_map[parent_index] = parent_node;

            // �湮�� ��� ����� �θ��带 �ٲ���
            for (long long j = 0; j < index.size(); j++) {
                hash_map[index[j]].parent = parent_index + 1;
            }
            answer.push_back(parent_index);
        }
    }
    return answer;
}

int main()
{
    vector<long long> sol = solution(10, { 1, 3, 4, 1, 3, 1 });
    
    return 0;
}
