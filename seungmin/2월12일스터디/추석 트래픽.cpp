/* 소요시간 (효율성 테스트)
최소 : 0.02ms, 4.1MB
최대 : 2.02ms, 4.38MB
*/

#include <bits/stdc++.h>

using namespace std;

int solution(vector<string> lines) {
    int answer = 0;

    string date, end_time, how_long;

    map<int, vector<int>> hash_table;
    priority_queue<int, vector<int>, greater<int>> start_pq;

    for (int i = 0; i < lines.size(); i++)
    {
        stringstream ss(lines[i]);

        ss >> date >> end_time >> how_long;

        int hour = stoi(end_time.substr(0, 2));
        int min = stoi(end_time.substr(3, 2));
        int sec = stoi(end_time.substr(6, 2));
        int mil_sec = stoi(end_time.substr(9));

        int end_time_int = 1000 * (60 * (60 * hour + min) + sec) + mil_sec;

        sec = how_long[0] - '0';
        int how_long_int = 1000 * sec;
        if (how_long.size() > 2) how_long_int += stoi(how_long.substr(2, how_long.size() - 3));

        int start_time_int = end_time_int - how_long_int + 1;

        //end_time_int가 오름차순으로 정렬되어 있음
        hash_table[start_time_int].push_back(end_time_int);

        start_pq.push(start_time_int);
    }

    priority_queue<int, vector<int>, greater<int>> end_pq;

    int process_count = 0;

    while (!start_pq.empty())
    {
        int standard_time = start_pq.top();
        start_pq.pop();

        vector<int> end_time_array = hash_table[standard_time];

        if (end_time_array.size() != 0) {
            for (int i = end_time_array.size() - 1; i >= 0; i--)
            {
                end_pq.push(end_time_array[i]);
                // 중요~! 시작 시간이 동일한 것들을 한번에 다 처리하므로 
                // vector 비워줘야함
                hash_table[standard_time].pop_back();
            }

            int temp_process = end_pq.size();

            // 1s 
            standard_time -= 999;

            if (standard_time >= 0)
            {
                while (1)
                {
                    int temp = end_pq.top();

                    if (temp < standard_time) end_pq.pop();
                    else break;
                }
                temp_process = end_pq.size();
            }

            if (temp_process > process_count) process_count = temp_process;
        }
    }
    answer = process_count;

    return answer;
}


int main()
{

    vector<string> s = { "2016-09-15 23:59:59.999 1.0s", "2016-09-15 01:00:06.001 2s", "2016-09-15 01:00:07.001 3s" };

    int sol = solution(s);

    cout << sol << endl;


    return 0;
}
