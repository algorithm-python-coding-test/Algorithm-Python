/*
* problem : ����ä�ù� (https://programmers.co.kr/learn/courses/30/lessons/42888)
*/

//userID�� key, �г����� value�� �ϸ� userID�� ���� �г��� ���� ����
//in, out ������ �����ϴ� �ڷᱸ���� �ϳ� �ʿ�
//?? level 1 ���� �̰� �� ���???

//Solving Time : 15min

#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

unordered_map<string, string> um_userID;
vector<pair<string, int>> order;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    for (int i = 0; i < record.size(); i++) {
        istringstream st(record[i]);
        string substr;
        vector<string> str;
        while (getline(st, substr, ' ')) str.push_back(substr);

        if (str[0] == "Enter") {
            um_userID[str[1]] = str[2];
            order.push_back({ str[1], 1 });    //1 : in
        }
        else if (str[0] == "Leave") {
            order.push_back({ str[1], 0 });    //0 : out
        }
        else if (str[0] == "Change") {
            um_userID[str[1]] = str[2];
        }
    }

    for (int i = 0; i < order.size(); i++) {
        if (order[i].second == 1) {
            answer.push_back(um_userID[order[i].first] + "���� ���Խ��ϴ�.");
        }
        else if (order[i].second == 0) {
            answer.push_back(um_userID[order[i].first] + "���� �������ϴ�.");
        }
    }

    return answer;
}
