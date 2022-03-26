// 30�� �ҿ�
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

#include <unordered_map>

vector<string> solution(vector<string> record) {
    vector<string> answer;
    
    unordered_map<string, pair<string,vector<int>>> hash;

    for (int i = 0; i < record.size(); i++) {
        string cmd = record[i];

        char sort = cmd[0];
        stringstream ss(cmd);
        
        string tem, id, name;
        int idx = answer.size();
        // ���� �������� �ڸ��� 
        //tem : Enter / Leave / Chage
        // id : id��
        ss >> tem >> id;
        if (tem[0] == 'E') {
            // name : �г��� 
            ss >> name;
            // "���� ���Խ��ϴ�." ���常 �߰�
            answer.push_back("���� ���Խ��ϴ�.");
            // id�� �����Ǵ� hash value�� ù��°(�г���) ���� ��,
            // �ι�° �迭���� answer�� ���° ���忡 ���� ���� idx�� �߰�
            hash[id].first = name;
            hash[id].second.push_back(idx);
        }
        else if (tem[0] == 'L') {
            // "���� �������ϴ�." ���常 �߰�
            answer.push_back("���� �������ϴ�.");
            // id�� �����Ǵ� hash value�� �ι�° �迭���� answer�� ���° ���忡 ���� ���� idx�� ����
            hash[id].second.push_back(idx);
        }
        else if (tem[0] == 'C') {
            // name : �г���
            ss >> name;
            // id�� �����Ǵ� hash value�� ù��°(�г���) ����
            hash[id].first = name;
        }
    }
    
    for (auto &q : hash) {
        // �տ������� hash - value�� tem�� ����
        pair<string, vector<int>> tem = hash[q.first];
        // tem�� ù��° ���� �г���
        string nick_name = tem.first;
        // tem�� �ι�° ���� answer�� ���° ���忡 �г����� ���� �ϴ��� ������ index�迭
        vector<int> idx_list = tem.second;
        // index�迭�κ��� ���� ������ answer �޽��� �տ� �г��� �ٿ��ֱ�
        for (int i = 0; i < idx_list.size(); i++) {
            answer[idx_list[i]] = nick_name + answer[idx_list[i]];
        }
    }
    return answer;
}

int main() {


    vector<string> sol = solution({ "Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan" });
    return 0;
}