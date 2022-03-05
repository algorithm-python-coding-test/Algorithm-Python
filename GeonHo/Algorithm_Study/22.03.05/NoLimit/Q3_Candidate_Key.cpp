//0.01ms ~ 1.20ms

#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<string> attribute[8];
vector<int> counted;

int solution(vector<vector<string>> relation) {
    int answer = 0;
    //attribute�� ����
    int att_Cnt = relation[0].size();
    //relation�� ����
    int rel_Cnt = relation.size();
    //�� attribute���� �з��Ͽ� ����
    for (int i = 0; i < relation.size(); i++) {
        for (int j = 0; j < relation[0].size(); j++) {
            attribute[j].push_back(relation[i][j]);
        }
    }
    //combination�� ����Ͽ� �ĺ�Ű �Ǻ�
    for (int i = 1; i <= att_Cnt; i++) {
        //combination�� ���� comb�迭
        vector<int> comb = {};
        for (int cnt = 0; cnt < i; cnt++) comb.push_back(1);
        for (int cnt = 0; cnt < att_Cnt - i; cnt++) comb.push_back(0);

        do {
            //���ϼ��� �˻��� �迭�� ����, cnt
            vector<string> singular(rel_Cnt);
            set<string> s_singular;
            int cnt = 0;
            //���տ� ���� attribute�� ���ο� key���� ����
            //�� �� ���� attribute�� ��ȣ�� �ּҼ� �˻縦 ���� cnt�� ��Ʈ�� ����
            for (int j = 0; j < att_Cnt; j++) {
                if (comb[j] == 1) {
                    for (int k = 0; k < rel_Cnt; k++) {
                        singular[k] += attribute[j][k];
                    }
                    cnt += (1 << j);
                }
            }
            //������� key���� set�� �־� ���ϼ� �˻�
            for (int j = 0; j < rel_Cnt; j++) s_singular.insert(singular[j]);
            //cnt���� �̿��Ͽ� �ּҼ� �˻�
            bool isCounted = false;
            for (int i = 0; i < counted.size(); i++) {
                if ((cnt & counted[i]) == counted[i]) {
                    isCounted = true;
                    break;
                }
            }
            //���ϼ��� �ּҼ��� ��� ����ϸ� answer++
            if (s_singular.size() == rel_Cnt && !isCounted) {
                answer++;
                counted.push_back(cnt);
            }
        } while (prev_permutation(comb.begin(), comb.end()));
    }

    return answer;
}