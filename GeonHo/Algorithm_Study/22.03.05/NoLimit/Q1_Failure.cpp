// 0.01ms ~ 1.05ms

#include <string>
#include <vector>
#include <algorithm>

using namespace std;
//�� stage�� Ŭ������ ����ڼ��� ����
float clear[502] = { 0 };
//������ ���Ľ� �̿�
//�������� ������ �������� ��ȣ���� ��������
bool comp(pair<double, int> a, pair<double, int> b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    //stages������ �� stage�� Ŭ������ ����ڼ��� ����
    for (int i = 0; i < stages.size(); i++) {
        clear[stages[i]]++;
    }
    //N������������ Ŭ������ ����ڼ��� �����Ѵ�.
    int users = clear[N + 1];
    //�� ���������� �������� ����.
    //�������� ������ �������� ��ȣ�� ����ؾ� �ϹǷ� pair�� ���� �������
    pair<float, int> failure[502] = { {0, 0} };
    //N������������ ����ϸ� ����ڼ� ����
    for (int i = N; i > 0; i--) {
        users += clear[i];
        if (users == 0) {
            failure[i] = { 0, i };
            continue;
        }
        failure[i] = { clear[i] / users, i };
    }

    sort(failure + 1, failure + N + 1, comp);

    for (int i = 1; i <= N; i++) {
        answer.push_back(failure[i].second);
    }

    return answer;
}