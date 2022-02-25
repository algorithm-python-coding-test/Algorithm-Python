//Union - Find���꿡 �����Ͽ� ������ �� ������ ����
//�ٵ� k���� ������ �ʹ� Ŀ�� parent ���� �迭�� ���� �Ұ���... 
//Node�� �����ϰ�, mapping�Ͽ� Node�� ã�ư��� ������� ����
//->�����迭�� �����Ǵ� union-find�� �ٸ��� ��ũ�� ������ parent ���� �����ϱ� �����

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
typedef long long ll;

struct roomNode {
    ll rNumber;
    roomNode* next = this;
    roomNode* head = this;
}roomNodes[200001];

unordered_map<ll, roomNode*> um;

int nodeCnt = 0;

roomNode* find_parent(roomNode* rm) {
    if (rm->next == rm) return rm;
    else {
        return rm = find_parent(rm->next);
    }
}

vector<ll> solution(ll k, vector<ll> room_number) {
    vector<ll> answer;
    for (int i = 0; i < room_number.size(); i++) {
        //room_number[i]�� ���� �������� �ʴ°��
        if (um.count(room_number[i]) == 0) {
            roomNodes[nodeCnt].rNumber = room_number[i];
            um[room_number[i]] = &roomNodes[nodeCnt];
            //room_number[i] - 1�� ���� �����ϸ� ���� ��� ����
            if (um.count(room_number[i] - 1)) {
                um[room_number[i] - 1]->next = &roomNodes[nodeCnt];
                um[room_number[i] - 1]->head = &roomNodes[nodeCnt];
            }
            //room_number[i] + 1�� ���� �����ϸ� ���� ��� ����
            if (um.count(room_number[i] + 1)) {
                roomNode* rm = find_parent(um[room_number[i] + 1]);
                um[room_number[i]]->next = um[room_number[i] + 1];
                um[room_number[i]]->head = rm;
            }
            answer.push_back(room_number[i]);
        }

        //room_number[i]�� ���� �����ϴ� ���
        else {
            roomNode* rm = find_parent(um[room_number[i]]);
            roomNodes[nodeCnt].rNumber = rm->rNumber + 1;
            um[roomNodes[nodeCnt].rNumber] = &roomNodes[nodeCnt];
            rm->next = &roomNodes[nodeCnt];
            //roomNodes[nodeCnt].rNumber + 1 �� ���� �����ϸ� rm�� ���� �� ��� ����
            if (um.count(roomNodes[nodeCnt].rNumber + 1)) {
                roomNode* nm = find_parent(um[roomNodes[nodeCnt].rNumber + 1]);
                roomNodes[nodeCnt].next = um[roomNodes[nodeCnt].rNumber + 1];
                roomNodes[nodeCnt].head = nm;
                rm->head = nm;
            }
            else {
                rm->head = &roomNodes[nodeCnt];
            }
            answer.push_back(roomNodes[nodeCnt].rNumber);
        }
        nodeCnt++;
    }
    return answer;
}

int main() {
    vector<ll> ret = solution(10, { 1, 3, 4, 1, 3, 1 });
    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i] << '\n';
    }
}