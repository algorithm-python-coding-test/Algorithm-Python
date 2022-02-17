/*
* problem : ȣ�� �� ���� (https://programmers.co.kr/learn/courses/30/lessons/64063)
*/

//long long ���� ó���ϴ°� ���� array�� vector�� �� ��ȣ�� ���ϴ� �����δ� ���� ���� ���ϰڴ�
//room_number�� 200,000�����̹Ƿ� �ܼ��������δ� ������� ����.
//������ �ð������� ���� �ؽ��ؼ� ���ռ��� �������

//Solving Time : 10min
//��Ȯ�� 78.8, ȿ���� 0 -> 78.8

#include <string>
#include <vector>
#include <unordered_map>

typedef long long ll;

using namespace std;

unordered_map<ll, int> um;

vector <ll> solution(ll k, vector<ll> room_number) {
    vector<ll> answer;
    for (int i = 0; i < room_number.size(); i++) {
        while (um[room_number[i]] != 0) {
            room_number[i]++;
        }
        um[room_number[i]]++;
        answer.push_back(room_number[i]);
    }
    return answer;
}