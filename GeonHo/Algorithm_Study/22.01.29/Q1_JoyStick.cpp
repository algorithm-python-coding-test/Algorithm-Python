/*
* problem : JoyStick
* ���̽�ƽ���� ���ĺ� �̸� �ϼ��ϱ�
* �ʱ⿡�� A�θ� �̷���� �̸� -> ��ǥ�ϴ� �̸��� ����� ���� �ּ� ����Ƚ�� ����
* 
* �ּ� 0.01ms / 3.66MB �� ����
* �ִ� 0.01ms / 4.35MB �� ����
*/
#include<iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string name) {
    //����� ������ ����
    int cnt = 0;
    //���̽�ƽ�� �����ؾ� �ϴ� index�� ����
    vector<int> idx;
    //name�� ù ���ں��� ������ ���ڱ��� ��ȸ�Ͽ�
    //�� ��ġ���� ����Ƚ���� ����ϰ�, �ش� ��ġ�� index�� idx�� �����Ѵ�.
    for (int i = 0; i < name.length(); i++) {
        int move = name[i] - 'A';
        //move�� 13�� �Ѿ�� z���� ���ƿ��°��� �� �����Ƿ� �������ش�.
        if (move > 13) {
            move = 26 - move;
        }
        cnt += move;
        //ù��° ���ڴ� �̵��� �ʿ䰡 �����Ƿ� �������� ����
        //move�� 0�ΰ���� ��ġ���� �ݵ�� �̵��� �ʿ䰡 �����Ƿ� �������� ����
        if (i != 0 && move != 0) 
            idx.push_back(i);
    }
    //idx�� size�� 0�ΰ�� : AA....
    if (idx.size() == 0) return cnt;
    //idx�� size�� 1�� ��� : ���������θ� �̵��ϰų� / �������θ� �̵��Ѵ�
    else if (idx.size() == 1) {
        cnt += (idx[0] < name.length() - idx[0]) ? idx[0] : name.length() - idx[0];
        return cnt;
    }
    //idx�� size�� 2 �̻��� ���
    //1) ���������θ� �̵��ϰų� / �������θ� �̵��ϴ� ��� �� ������
    int move_cnt = (idx[idx.size() - 1] < name.length() - idx[0]) ? idx[idx.size() - 1] : name.length() - idx[0];
    //2)���������� �̵��ϴ� �������� �̵��ϰų� / �������� �̵��ϴ� ���������� �̵��ϴ� ��� �� ���� ��
    for (int i = 0; i < idx.size() - 1; i++){
        int left = idx[i];
        int right = idx[i + 1];
        int temp_cnt = (2 * (name.length() - right) + left < (2 * left) + (name.length() - right)) ? 2 * (name.length() - right) + left : (2 * left) + (name.length() - right);
        move_cnt = move_cnt < temp_cnt ? move_cnt : temp_cnt;
    }
    //���������� �����̴� Ƚ���� ���� �������� cnt�� �����ش�.
    cnt += move_cnt;
    return cnt;
}

int main() {
    int answer = solution("JEROEN");
    cout << answer;
    return 0;
}