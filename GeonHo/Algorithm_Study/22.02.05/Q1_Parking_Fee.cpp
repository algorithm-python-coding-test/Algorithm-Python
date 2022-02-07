/*
* problem : Parking Fee (https://programmers.co.kr/learn/courses/30/lessons/92341)
* �������� ���ǥ�� ������ ����� �־��� �� ���� ��ȣ�� ���� ������ ������ ���� ����� ����Ͽ� ����
*
* �ּ� 0.03ms / 3.7MB�� ����
* �ִ� 0.64ms / 4.33MB�� ����
*/
#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;
//���� ������ �����ϴ� ����ü ����
struct Car {
    int in_Time = 0;
    float duration = 0;
    bool isOut = true;
};
//index�� ���� ��ȣ�� ������ Car�迭 ex) 0912�� ���� -> cars[912]
Car cars[10000];

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    //�Է� ������ �����ϹǷ� stringstream���� �Ľ̾��� ���ڿ� ó��
    //��-���� ���ο� ���� ��ȣ�� �������� ������ ó��
    for (int i = 0; i < records.size(); i++) {
        string inOut = records[i].substr(11);
        int carNum = stoi(records[i].substr(6, 4));
        //(1)������ ���
        if (inOut == "IN") {
            int inTime = (stoi(records[i].substr(0, 2)) * 60) + stoi(records[i].substr(3, 2));
            cars[carNum].in_Time = inTime;
            cars[carNum].isOut = false;
        }
        //(2)������ ���
        else if (inOut == "OUT") {
            int outTime = (stoi(records[i].substr(0, 2)) * 60) + stoi(records[i].substr(3, 2));
            cars[carNum].duration += outTime - cars[carNum].in_Time;
            cars[carNum].isOut = true;
        }
    }
    //0000�� �������� 9999�� �������� ������ �����ߴ� ����� �ְų�
    //�������� ���� �����鿡 ���ؼ� ������� ����
    for (int i = 0; i < 10000; i++) {
        if (cars[i].duration > 0 || !cars[i].isOut) {
            if (!cars[i].isOut) {
                cars[i].duration += 1439 - cars[i].in_Time;
            }
            int fee = 0;
            if (cars[i].duration <= fees[0]) {
                fee = fees[1];
            }
            else if (cars[i].duration > fees[0]) {
                fee = fees[1] + fees[3] * ceil((cars[i].duration - fees[0]) / fees[2]);
            }
            answer.push_back(fee);
        }
    }
    return answer;
}


int main() {
    vector<int> ret = solution({ 180, 5000, 10, 600 }, { "05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT",
        "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT" });
    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i] << '\n';
    }
    return 0;
}