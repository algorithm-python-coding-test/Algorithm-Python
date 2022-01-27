#include <bits/stdc++.h>

using namespace std;

string in = "님이 들어왔습니다.";
string out = "님이 나갔습니다.";

vector<string> solution(vector<string> record) {
    vector<string> answer;

    map<string, string> nickname_array;
    vector<vector<string>> order_id_nickname;

    for (int i = 0; i < record.size(); i++)
    {
        vector<string> s = {"","",""};

        int temp = 0;
        for (int k = 0; k < record[i].size(); k++)
        {
            if (record[i][k] == ' ')
            {
                temp++;
            }
            else 
            {
                s[temp] += record[i][k];
            }
        }

        order_id_nickname.push_back(s);

        if (s[0] == "Enter" || s[0] == "Change")
        {
            nickname_array[s[1]] = s[2];
        }
    }

    for (int i = 0; i < order_id_nickname.size(); i++)
    {
        if (order_id_nickname[i][0] == "Enter") answer.push_back(nickname_array[order_id_nickname[i][1]] + in);
        else if(order_id_nickname[i][0] == "Leave") answer.push_back(nickname_array[order_id_nickname[i][1]] + out);
    }

    return answer;
}



int main()
{
    vector<string> sol = solution({ "Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan" });

   
    return 0;
}
