/*
* problem : Ʃ�� (https://programmers.co.kr/learn/courses/30/lessons/64065)
*/

//���ڿ��� �־��� �Է�... �켱 ���ڿ� ó������ �����غ���.
//���ڿ��� ó���Ͽ� ������ ���Ѵ���, ������ ũ������� ���ο� ���Ҹ� answer�� �����Ͽ� ����
//���ڿ��� ��� ������ O(N) N = 1,000,000�̹Ƿ� ó���� �ð��� ������� �ʾƵ� ������ �� ����

//���ڿ��� ó���Ͽ� ������ ������ �ִ� 500���̹Ƿ� STL�� set_difference (O(N))�� ����Ͽ� ó�� ����

//Solving Time : 40min

#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> set[501];
int _size = 0;

vector<int> solution(string s) {
    vector<int> answer;
    queue<int> q;
    string temp = "";
    for (int i = 1; i < s.length() - 1; i++) {
        if (s[i] == '{') continue;
        else if (s[i] == ',') {
            int num = stoi(temp);
            q.push(num);
            temp = "";
        }
        else if (s[i] == '}') {
            int num = stoi(temp);
            q.push(num);
            temp = "";
            int size = q.size();
            if (size > _size) _size = size;
            while (!q.empty()) {
                set[size].push_back(q.front());
                q.pop();
            }
            i++;
        }
        else {
            temp += s[i];
        }
    }
    answer.push_back(set[1].front());
    vector<int> set_diff;
    for (int i = 2; i <= _size; i++) {
        sort(set[i].begin(), set[i].end());
        set_diff.resize(set[i].size());
        set_difference(set[i].begin(), set[i].end(), set[i - 1].begin(), set[i - 1].end(), set_diff.begin());
        answer.push_back(set_diff.front());
        set_diff.clear();
    }
    return answer;
}