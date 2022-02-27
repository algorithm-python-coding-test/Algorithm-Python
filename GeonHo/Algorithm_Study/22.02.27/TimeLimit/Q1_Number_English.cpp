/*
* problem : ���� ���ڿ��� ���ܾ� (https://programmers.co.kr/learn/courses/30/lessons/81301)
*/

//��� ������ ���̴� �ִ� 10�ڸ�
//�� �ڸ����� ���ܾ�� �˻����ָ� ������ �����ε�
//�ܼ��ϰ� Ǯ� ����� �����̹Ƿ� ����ȭ�� �������� ���� �ܼ� �������� �ذ�����
//ó���� �ѱ��ھ� ���ϰ�, ���� ���ڰ� ������ �߰� ���̽� �з��� �����Ͽ�����
//�����غ��� �� ���ھ� ���ϸ� �߰� ���̽� �з��� ���� �ʾƵ� �ȴ�!

//Solving Time : 10min

#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    string original_number;
    for (int i = 0; i < s.length(); i++) {
        //s[i]�� ������ ���
        if (s[i] >= 48 && s[i] <= 57) {
            original_number += s[i];
            continue;
        }

        if (s.substr(i, 2) == "ze") {
            original_number += '0';
            i += 3;
            continue;
        }
        if (s.substr(i, 2) == "on") {
            original_number += '1';
            i += 2;
            continue;
        }
        if (s.substr(i, 2) == "tw") {
            original_number += '2';
            i += 2;
            continue;
        }
        if (s.substr(i, 2) == "th") {
            original_number += '3';
            i += 4;
            continue;
        }
        if (s.substr(i, 2) == "fo") {
            original_number += '4';
            i += 3;
            continue;
        }
        if (s.substr(i, 2) == "fi") {
            original_number += '5';
            i += 3;
            continue;
        }
        if (s.substr(i, 2) == "si") {
            original_number += '6';
            i += 2;
            continue;
        }
        if (s.substr(i, 2) == "se") {
            original_number += '7';
            i += 4;
            continue;
        }
        if (s.substr(i, 2) == "ei") {
            original_number += '8';
            i += 4;
            continue;
        }
        if (s.substr(i, 2) == "ni") {
            original_number += '9';
            i += 3;
            continue;
        }
    }
    answer = stoi(original_number);
    return answer;
}