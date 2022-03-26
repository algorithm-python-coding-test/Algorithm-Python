// 30분 소요
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
        // 띄어쓰기 기준으로 자르기 
        //tem : Enter / Leave / Chage
        // id : id값
        ss >> tem >> id;
        if (tem[0] == 'E') {
            // name : 닉네임 
            ss >> name;
            // "님이 들어왔습니다." 문장만 추가
            answer.push_back("님이 들어왔습니다.");
            // id에 대응되는 hash value의 첫번째(닉네임) 변경 후,
            // 두번째 배열값에 answer의 몇번째 문장에 들어가야 할지 idx값 추가
            hash[id].first = name;
            hash[id].second.push_back(idx);
        }
        else if (tem[0] == 'L') {
            // "님이 나갔습니다." 문장만 추가
            answer.push_back("님이 나갔습니다.");
            // id에 대응되는 hash value의 두번째 배열값에 answer의 몇번째 문장에 들어가야 할지 idx값 저장
            hash[id].second.push_back(idx);
        }
        else if (tem[0] == 'C') {
            // name : 닉네임
            ss >> name;
            // id에 대응되는 hash value의 첫번째(닉네임) 변경
            hash[id].first = name;
        }
    }
    
    for (auto &q : hash) {
        // 앞에서부터 hash - value를 tem에 저장
        pair<string, vector<int>> tem = hash[q.first];
        // tem의 첫번째 값이 닉네임
        string nick_name = tem.first;
        // tem의 두번째 값이 answer의 몇번째 문장에 닉네임이 들어가야 하는지 저장한 index배열
        vector<int> idx_list = tem.second;
        // index배열로부터 값을 받으며 answer 메시지 앞에 닉네임 붙여주기
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