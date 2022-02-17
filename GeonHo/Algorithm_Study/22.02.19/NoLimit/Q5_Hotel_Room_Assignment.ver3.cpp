//��ũ�� ���鿡 ����� ���� �����ϴ°��� �ſ� ��ƴ�...
//��ũ�� ���鿡 parent���� �������� ������ ��� ��带 ��ȸ�ϴ°��� �Ұ����ϴ�
//�ᱹ ��� ������ ��ȸ���� �ʰ� ������ head�� ã�°��� �����ε�
//�Է� -> ���� ���� mapping�Ͽ� ã�ư��� ������ �غ��°� ���

//����ð� 144.19ms / 227.61ms

#include <unordered_map>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

unordered_map<ll, ll> selected_room;        //���� ������ ���
unordered_map<ll, ll> assigned_room;        //�Էµ� ��, �ֱٿ� ������ ��

vector<ll> solution(ll k, vector<ll> room_number) {
    vector<ll> answer;
    for (int i = 0; i < room_number.size(); i++) {
        //room_number[i]�� ���� �̹� �����Ǿ� �ִٸ�
        //����� ��� �� �������� head�� ã�Ƴ��� ���� ����
        if (selected_room[room_number[i]] == 1) {
            vector<ll> candidates;          /*���� �˰����� �ӵ� ���̸� ���� �κ�*/
            candidates.push_back(room_number[i]);
            ll temp = assigned_room[room_number[i]] + 1;
            candidates.push_back(temp);

            while (selected_room[temp] != 0) {  /*����� ��� ������ �˻����� �ʰ�, tail -> head�� ���� ����!*/
                temp = assigned_room[temp] + 1;
                candidates.push_back(temp);
            }

            selected_room[temp]++;
            for (int i = 0; i < candidates.size(); i++) {
                assigned_room[candidates[i]] = temp;    /*���� �˻��� ��� tail�� head�� temp�� ������Ʈ*/
            }
            answer.push_back(temp);
        }
        //room_number[i]�� ���� �����Ǿ����� �ʴٸ�
        else {
            //room_number[i]�� ���� �����ϰ�, room_number[i]�� head�� room_number[i]�� �ʱ�ȭ
            selected_room[room_number[i]]++;
            assigned_room[room_number[i]] = room_number[i];
            answer.push_back(room_number[i]);
        }
    }
    return answer;
}

int main() {
    vector<ll> ret = solution(10, { 1, 1, 2, 2, 3, 3, 4, 4 });
    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i] << '\n';
    }
}