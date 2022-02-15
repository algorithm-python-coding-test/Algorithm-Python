/*
* problem : ���� ���� (https://programmers.co.kr/learn/courses/30/lessons/67258)
* ��� ������ �ϳ� �̻� �����ϴ� ���� ª�� ���� ã��
*
* �������� �˰��� �õ�
* ->�����̵� ������ �˰��� �õ�
* ->�������� ���...
*
* ȿ���� �׽�Ʈ ����
* �ּ� 2.04ms / 3.95MB�� ����
* �ִ� 64.65ms / 12MB�� ����
*/

//�������� �˰����� ���
//s : gems�� �ִ� ��� ���� ������ ������ ���ϱ� ���� ���
//kinds : �������� ���� ���� ���� ������ ������ ���ϱ� ���� ���

//left~right�� �������� ��� ���� ������ ���� �� �ִ��� ��
//���� ��� ������ ���� �� �ִٸ� �ش� ������ ���̰� ���� ª���� �� �� answer����
//gem�� ��� ��ȸ �� ���ŵ� answer�� ����

//set. insert : O(logN)
//map. insert, find, erase : O(logN)
//�������� �˰��� : O(N)
//-> solution�� �ð� ���⵵ : O(NlogN)������ ����

//map,set -> unordered_map���� �ڷᱸ�� ����.
//unordered_map�� insert������ O(1)�̹Ƿ� solution�� �ð����⵵�� O(N)���� ����
//->�ּ� 0.95ms, �ִ� 27.68ms�� �ӵ����
//-->���ʿ��� ���� ���� �� �ִ� 19.81ms�� �ӵ����

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    answer.push_back(1);
    answer.push_back(1);
    //gems���� ��� ���� ������ ������ ���ϱ� ���� s ���
    unordered_map<string, int> s;
    for (int i = 0; i < gems.size(); i++)
        s[gems[i]]++;
    //gems�� ������ ������ 1���ۿ� ���ٸ� �״�� answer�� ����
    if (s.size() == 1)
        return answer;
    //�������� �˰��� ����
    //kinds : string �̸��� ������ int�� ��ŭ ����
    int left = 0, right = 1;
    unordered_map<string, int> kinds;
    int minDistance = 1e9;
    kinds[gems[0]]++;
    while (right < gems.size()) {
        kinds[gems[right]]++;
        //gems[right]�� gems[left]�� ���ٸ� left�� ������ �����ص� ����
        if (gems[right] == gems[left]) {
            kinds[gems[left]]--;
            left++;
        }
        //gems[left]�� gems[left+1]�� ���ٸ� left�� ������ �����ص� ����
        while (left < right && gems[left] == gems[left + 1]) {
            kinds[gems[left]]--;
            left++;
        }
        //���� ������ ������ ������ ������ ��ü ������ ������ ���ٸ�
        if (kinds.size() == s.size()) {
            //gems[right]�� gems[right - 1]�� ���ٸ� right�� ������ �����ص� ����
            /*while (left < right && gems[right] == gems[right - 1]) {
            //    kinds[gems[right]]--;
            //    right--;
            */} // -> ���ʿ��� ����
            //���� ������ minDistance���� ª�ٸ� answer����
            if (right - left < minDistance) {
                minDistance = right - left;
                answer[0] = left + 1;
                answer[1] = right + 1;
            }
            //���� ������ �����ϱ� ���� ���� ó��
            kinds[gems[left]]--;
            if (kinds[gems[left]] == 0) {
                kinds.erase(gems[left]);
            }
            left++;
            kinds[gems[right]]--;
            right--;
        }
        right++;
    }
    return answer;
}

int main() {
    vector<int> ret = solution({ "DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA" });
    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i] << '\n';
    }
    return 0;
}
