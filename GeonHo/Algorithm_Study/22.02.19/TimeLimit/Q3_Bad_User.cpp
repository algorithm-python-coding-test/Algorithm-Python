/*
* problem : �ҷ� ����� (https://programmers.co.kr/learn/courses/30/lessons/64064)
*/

//�ƴ� īī�� ���ڿ� ó���ϴ°� ���̸� ������...
//user_id�� banned_id�� ũ��� ���̵� ���̰� �׷��� ���� �����Ƿ� ������ �� �ϸ� ����ҵ�?
//user_id�� banned_id�� ���̺��� �������� ���Ͽ� �� ���̽����� ���� ������� �����ִ� �������� ����
//���̺��� ���� ���̽����� �� ���̵� ��� ���ؾ� �ұ�...?

//Solving Time : ...

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> user_divided_len[9];
vector<string> banned_divided_len[9];

bool comp_user(string user, string ban) {
    int len = user.length();
    bool ret = true;
    for (int i = 0; i < len; i++) {
        if (ban[i] == '*' || user[i] == ban[i]) continue;
        else if (user[i] != ban[i]) {
            ret = false;
            break;
        }
    }
    return ret;
}

using namespace std;

int solution(vector<string> user_id, vector<string> banned_id) {
    for (int i = 0; i < user_id.size(); i++) {
        user_divided_len[user_id[i].length()].push_back(user_id[i]);
    }
    for (int i = 0; i < banned_id.size(); i++) {
        banned_divided_len[banned_id[i].length()].push_back(banned_id[i]);
    }
    int answer = 1;

    
    return answer;
}