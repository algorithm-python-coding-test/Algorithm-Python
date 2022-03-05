//0.03ms ~ 128.78ms

//vector��� queue�� ����ص� �ð��� ũ�� �ٲ��� �ʴ´�.

#include <string>
#include <queue>
#include <sstream>
#include <unordered_map>

using namespace std;
//userID - �г����� ��Ī�� �ؽ����̺�
unordered_map<string, string> um_userID;
//userID�� in-out�� ������ �迭 1 : in, 0 : out
queue<pair<string, int>> q_order;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    for (int i = 0; i < record.size(); i++) {
        //record�� �� ���Ҹ� ������ �������� �����Ͽ� str�� ����
        istringstream st(record[i]);
        string substr;
        vector<string> str;
        while (getline(st, substr, ' ')) str.push_back(substr);
        //�� ��ɾ�� ����� ����
        if (str[0] == "Enter") {
            um_userID[str[1]] = str[2];
            q_order.push({ str[1], 1 });    //1 : in
        }
        else if (str[0] == "Leave") {
            q_order.push({ str[1], 0 });    //0 : out
        }
        else if (str[0] == "Change") {
            um_userID[str[1]] = str[2];
        }
    }
    //����� ����� �� order�� �տ������� �޽��� ���
    while (!q_order.empty()) {
        if (q_order.front().second == 1) {
            answer.push_back(um_userID[q_order.front().first] + "���� ���Խ��ϴ�.");
        }
        else if (q_order.front().second == 0) {
            answer.push_back(um_userID[q_order.front().first] + "���� �������ϴ�.");
        }
        q_order.pop();
    }

    return answer;
}