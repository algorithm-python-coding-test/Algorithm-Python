//30�� �ҿ�, ������ ��ó������ ���

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct node
{
    // �ʱ� ������ ���� 0���� �ʱ�ȭ
    float ratio = 0;
    // 1~N stage���� index ��
    int idx;
} ND;

bool cmp(ND a, ND b)
{
    if (a.ratio == b.ratio) {
        return a.idx < b.idx;
    }
    return a.ratio > b.ratio;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    //stages �迭 �� �������� ����
    sort(stages.begin(), stages.end());
    //stage�� ���� ���� ��ü ������ �� (������ ����� ���� �и�)
    int total = stages.size();
    // �� stage�� �������� ������ �迭
    vector<node> result(N);
    // �� stage�� ����
    for (int i = 0; i < N; i++) result[i].idx = i;
    // ���� ó�� ������ stage ��
    int stage = stages[0];
    // ���� stage�� ���µ� ������ ����� ��
    int cnt = 1;
    for (int i = 1; i < stages.size(); i++) {
        // ���� stage�� ���´ٸ�
        if (stage != stages[i]) {
            // ��������� stage �������� result�� ����
            result[stage - 1].ratio = (float)cnt / total;
            // ������ ��꿡�� �����ϱ� ���� total�� ���
            total -= cnt;
            // ���� stage�� �Ѿ� ����
            stage = stages[i];
            // ���� stage ���µ� ������ ��� �� 1�� �ʱ�ȭ
            if (stages[i] != N + 1) cnt = 1;
            // �� stage�� �Ѿ�µ� stages[i]�� N+1�̶��, 
            // �� stage�� ������ ����� 0�� (�ִ� stage�� N)
            else cnt = 0;
        }
        // ���� stage���̸� ���� stage�� ���µ� ������ ��� +1
        else {
            cnt++;
        }
    }
    // ���⼭ ���
    // stages[i]�� �ٲ��� �����鼭 �� for���� ���� ���´ٸ�, 
    // �ش� stage�� ������ ���� ���� ������ ����Ѵ�
    // stages[i]�� N+1�� �� for���� �������´ٸ� �ش� stage�� �������� 0�̹Ƿ� 
    // �ƹ� �۾��� ���� �ʴ´�. (������ �ʱⰪ 0���� ����)
    if (total != 0 && stage != N + 1) {
        result[stage - 1].ratio = (float)cnt / total;
    }

    // ��� stage�� ������ ���� ���� stage ������ ����Ǿ� �ִ� result �迭��
    // �������� ū stage�� ������, �������� ���ٸ� idx�� ū stage�� ������ ������ �����Ѵ�
    sort(result.begin(), result.end(), cmp);
    // answer�� ����
    for (int i = 0; i < result.size(); i++)
        answer.push_back(result[i].idx + 1);

    return answer;
}

int main() {


    vector<int> sol = solution(5,{ 1,1,1,1,1 });


    return 0;
}