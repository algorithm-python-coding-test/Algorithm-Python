#include <bits/stdc++.h>

using namespace std;

// records 배열 정렬하기 : 같은 차번호로 정렬 후, 입출차 시간대로 정렬
bool cmp(string a, string b)
{
    // 차번호
    string sub_a = a.substr(6, 4);
    string sub_b = b.substr(6, 4);

    if (sub_a.compare(sub_b) == 0)
    {
        // 입출차 시간
        sub_a = a.substr(0, 5);
        sub_b = b.substr(0, 5);

        return sub_a < sub_b;
    }
    else return sub_a < sub_b;
}

// 입차시간이 in, 출차시간이 out일 때 총 주차시간
int ParkingTime(string in, string out)
{
    int parking_time = 0;
    
    int in_hour, out_hour, in_min, out_min;

    in_hour = (in[0] - '0') * 10 + (in[1] - '0');
    in_min = (in[3] - '0') * 10 + (in[4] - '0');

    int park_hour, park_min;

    out_hour = (out[0] - '0') * 10 + (out[1] - '0');
    out_min = (out[3] - '0') * 10 + (out[4] - '0');

    if (in_min > out_min)
    {
        park_min = 60 + (out_min - in_min);
        park_hour = out_hour - in_hour - 1;
    }
    else
    {
        park_min = out_min - in_min;
        park_hour = out_hour - in_hour;
    }
    parking_time = 60 * park_hour + park_min;

    return parking_time;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;

    // records 배열 정렬 : 차번호 순, 그다음 입출차 시간 순
    sort(records.begin(), records.end(), cmp);

    int basic_time = fees[0];
    int basic_fee = fees[1];
    int add_time = fees[2];
    int add_fee = fees[3];

    int index = 0;
    while (index < records.size())
    {
        int fee = 0;
        int parking_time = 0;

        string cur_car_num = records[index].substr(6, 4);

        while (1)
        {
            // 입차한 차
            string in_car = records[index].substr(6, 4);
            if (cur_car_num.compare(in_car) != 0) break;

            // 입차시간
            string in_car_time = records[index].substr(0, 5);
            index++;

            // 출차한 차
            string out_car;
            string out_car_time;
            // 더이상 차가 없을 경우를 대비
            if (index < records.size())
            {
                // 출차한 차
                out_car = records[index].substr(6, 4);
                // 출차시간
                out_car_time = records[index].substr(0, 5);
            }
            else
            {
                out_car = "";
            }

            // 입차-출차한 차가 동일할때
            if (in_car.compare(out_car) == 0)
            {
                parking_time += ParkingTime(in_car_time, out_car_time);
            }
            // 입차하고 출차는 하지 않았을때
            else
            {
                parking_time += ParkingTime(in_car_time, "23:59");

                // 더이상 cur_car_num으로 주차한 시간은 없으므로 while문 탈출
                break;
            }
            index++;

            // records에 더이상 차가 없다면 탈출
            if (index > records.size() - 1) break;
        }

        // cur_car_num의 요금 계산 : 기본요금
        fee += basic_fee;

        // 추가 요금
        if (parking_time - basic_time > 0)
        {
            // 나누어 떨어지지 않으면 올림
            if ((parking_time - basic_time) % add_time)
            {
                fee += ((parking_time - basic_time) / add_time + 1) * add_fee;
            }
            else
            {
                fee += ((parking_time - basic_time) / add_time) * add_fee;
            }
        }
        answer.push_back(fee);

    }
    return answer;
}