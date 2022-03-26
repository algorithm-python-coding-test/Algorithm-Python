#include <bits/stdc++.h>

using namespace std;

struct node {
    int st, ed;
};
node ed_first[2000];

int solution(vector<string> lines) {
    int answer = 0;
    int size = lines.size();

    for (int i = 0; i < size; i++) {
        string line = lines[i];
        /*
        int h = 10 * (line[11] - '0') + line[12] - '0';
        int m = 10 * (line[14] - '0') + line[15] - '0';
        int s = 10 * (line[17] - '0') + line[18] - '0';
        int ms = 100 * (line[20] - '0') + 10 * (line[21] - '0') + line[22] - '0';
        int t = 0;
        int j = 24;
        while (line[j] != 's') {
            if (line[j] == '.') {
                j++;
                break;
            }
            t = 10 * t + line[j] - '0';
            j++;
        }
        int mt = 0;
        int unit = 100;
        while (line[j] != 's') {
            mt = mt + (line[j] - '0') * unit;
            j++;
            unit = unit / 10;
        }
        t = 1000 * t + mt;
        */
        
        int y, mo, d, h, m, s, ms;
        double f_t; 
        //float���� ������ �ȵ� ( %f�� float)
        sscanf_s(lines[i].c_str(), "%d-%d-%d %d:%d:%d.%d %lfs", &y, &mo, &d, &h, &m, &s, &ms, &f_t);
        // ���־� ��Ʃ������� sscanf������ _CRT_SECURE_NO_WARNINGS ����
        // ���� ä������ _s���� �Լ��� ��Ÿ�� ����
        // sscanf�� �����ϳ� ���� �Ľ��ϴ°ͺ��� ���� ���� �ɸ�
        int t = (int)(f_t * 1000);

        node tem;
        tem.ed = 1000 * (60 * (60 * h + m) + s) + ms;
        tem.st = tem.ed - t + 1;

        ed_first[i] = tem;
    }

    for (int i = 0; i < size; i++) {
        // ���� ���������� �۾�����ð��� �������� 1�� ���������� �����ϴ� �۾����� �����ش�
        // �۾��� 2000�� ���̹Ƿ� 2000*2000 ����� �ð� ���⵵
        int t = ed_first[i].ed;
        int range = t + 999;
        
        int count = 0;
        for (int j = i; j < lines.size(); j++) {
            if (ed_first[j].st <= range) count++;
        }

        if (count > answer) answer = count;
    }
    return answer;
}

int main() {

    int sol = solution({ "2016-09-15 01:00:04.002 2.0s", "2016-09-15 01:00:07.000 2s" });
    return 0;
}