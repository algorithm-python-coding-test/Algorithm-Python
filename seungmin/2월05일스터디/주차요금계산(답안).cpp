#include <bits/stdc++.h>
using namespace std;

int conv(string& t) {
    int h = (t[0] - 48) * 10 + t[1] - 48;
    int m = (t[3] - 48) * 10 + t[4] - 48;
    return h * 60 + m;
}

vector<int> solution(vector<int> fees, vector<string> records) {

    vector<int> vec[10000];
    for (auto& record : records) {
        stringstream ss(record);
        string a, b, c;
        ss >> a >> b >> c;
        // 차량번호로 index 구분하여, 입출차 시간을 정수로 변환한 값을 넣기
        vec[stoi(b)].push_back(conv(a));
    }

    vector<int> ans;
    for (int i = 0; i < 10000; ++i) if (!vec[i].empty()) {
        // 총 입차,출차 횟수가 홀수라면 마지막에 나가지 않은 것이므로 23:59 추가
        if (vec[i].size() & 1) vec[i].push_back(23 * 60 + 59);

        // i 차의 총 입출차 시간 계산
        int sum = 0;
        for (int j = 1; j < vec[i].size(); j += 2) sum += vec[i][j] - vec[i][j - 1];

        // 기본요금으로 시작
        int val = fees[1];
        // 올림 : fees[2] - 1 을 더함으로써 구현
        if (sum > fees[0]) val += (sum - fees[0] + fees[2] - 1) / fees[2] * fees[3];

        ans.push_back(val);
    }

    return ans;
}
