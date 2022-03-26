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
        //float으로 받으면 안됨 ( %f가 float)
        sscanf_s(lines[i].c_str(), "%d-%d-%d %d:%d:%d.%d %lfs", &y, &mo, &d, &h, &m, &s, &ms, &f_t);
        // 비주얼 스튜디오에서 sscanf쓰려면 _CRT_SECURE_NO_WARNINGS 선언
        // 코테 채점에서 _s붙은 함수는 런타임 에러
        // sscanf가 간단하나 직접 파싱하는것보다 좀더 오래 걸림
        int t = (int)(f_t * 1000);

        node tem;
        tem.ed = 1000 * (60 * (60 * h + m) + s) + ms;
        tem.st = tem.ed - t + 1;

        ed_first[i] = tem;
    }

    for (int i = 0; i < size; i++) {
        // 가장 먼저끝나는 작업종료시간을 기준으로 1초 범위내에서 시작하는 작업들을 세어준다
        // 작업이 2000개 뿐이므로 2000*2000 충분한 시간 복잡도
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