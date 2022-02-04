#include <bits/stdc++.h>

using namespace std;

// records �迭 �����ϱ� : ���� ����ȣ�� ���� ��, ������ �ð���� ����
bool cmp(string a, string b)
{
    // ����ȣ
    string sub_a = a.substr(6, 4);
    string sub_b = b.substr(6, 4);

    if (sub_a.compare(sub_b) == 0)
    {
        // ������ �ð�
        sub_a = a.substr(0, 5);
        sub_b = b.substr(0, 5);

        return sub_a < sub_b;
    }
    else return sub_a < sub_b;
}

// �����ð��� in, �����ð��� out�� �� �� �����ð�
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

    // records �迭 ���� : ����ȣ ��, �״��� ������ �ð� ��
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
            // ������ ��
            string in_car = records[index].substr(6, 4);
            if (cur_car_num.compare(in_car) != 0) break;

            // �����ð�
            string in_car_time = records[index].substr(0, 5);
            index++;

            // ������ ��
            string out_car;
            string out_car_time;
            // ���̻� ���� ���� ��츦 ���
            if (index < records.size())
            {
                // ������ ��
                out_car = records[index].substr(6, 4);
                // �����ð�
                out_car_time = records[index].substr(0, 5);
            }
            else
            {
                out_car = "";
            }

            // ����-������ ���� �����Ҷ�
            if (in_car.compare(out_car) == 0)
            {
                parking_time += ParkingTime(in_car_time, out_car_time);
            }
            // �����ϰ� ������ ���� �ʾ�����
            else
            {
                parking_time += ParkingTime(in_car_time, "23:59");

                // ���̻� cur_car_num���� ������ �ð��� �����Ƿ� while�� Ż��
                break;
            }
            index++;

            // records�� ���̻� ���� ���ٸ� Ż��
            if (index > records.size() - 1) break;
        }

        // cur_car_num�� ��� ��� : �⺻���
        fee += basic_fee;

        // �߰� ���
        if (parking_time - basic_time > 0)
        {
            // ������ �������� ������ �ø�
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