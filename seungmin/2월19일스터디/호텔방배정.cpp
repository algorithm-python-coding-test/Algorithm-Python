/*
어려웠던 점
 - left = 0, right =  1.0e12 인 이분탐색으로 시도
 - left, right, mid의 기준을 찾지 못하고 실패

*/


/*
풀이 확인 -> hashmap (hashtable) 로 구현

효율성 테스트 기준
최대 : 194.45ms, 51.8MB
최소 : 107.77ms, 52.3MB

*/


#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

// 방에 대한 정보
typedef struct node
{
    // 고객이 있는지 없는지
    char is_occupied = 0;
    // 부모 노드 정보
    long long parent = -1;
} ND;

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;

    // 각 방의 정보를 담고 있는 hash_table
    unordered_map<long long, node> hash_map;

    for (int i = 0; i < room_number.size(); i++) {

        // 고객이 원하는 방
        long long want_index = room_number[i];

        // 방의 정보
        ND want_node = hash_map[want_index];

        // 손님이 없다면 바로 배정
        if (want_node.is_occupied == 0) {
            
            want_node.is_occupied = 1;
            want_node.parent = want_index + 1;
            hash_map[want_index] = want_node;

            answer.push_back(want_index);
        }
        else {
            // 빈 방을 찾을 때까지 방문한 방들의 정보를 저장할 배열
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

            // 방문한 모든 방들의 부모노드를 바꿔줌
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
