//30분 소요, 마지막 값처리에서 헤맴

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct node
{
    // 초기 실패율 값은 0으로 초기화
    float ratio = 0;
    // 1~N stage들의 index 값
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
    //stages 배열 값 오름차순 정렬
    sort(stages.begin(), stages.end());
    //stage를 진행 중인 전체 유저의 수 (실패율 계산을 위한 분모값)
    int total = stages.size();
    // 각 stage의 실패율을 저장할 배열
    vector<node> result(N);
    // 각 stage값 저장
    for (int i = 0; i < N; i++) result[i].idx = i;
    // 가장 처음 실패한 stage 값
    int stage = stages[0];
    // 현재 stage를 깨는데 실패한 사람의 수
    int cnt = 1;
    for (int i = 1; i < stages.size(); i++) {
        // 다음 stage가 나온다면
        if (stage != stages[i]) {
            // 현재까지의 stage 실패율을 result에 저장
            result[stage - 1].ratio = (float)cnt / total;
            // 실패율 계산에서 제외하기 위해 total값 계산
            total -= cnt;
            // 다음 stage로 넘어 가기
            stage = stages[i];
            // 현재 stage 깨는데 실패한 사람 수 1로 초기화
            if (stages[i] != N + 1) cnt = 1;
            // 새 stage로 넘어갔는데 stages[i]가 N+1이라면, 
            // 그 stage를 실패한 사람은 0명 (최대 stage는 N)
            else cnt = 0;
        }
        // 같은 stage값이면 현재 stage를 깨는데 실패한 사람 +1
        else {
            cnt++;
        }
    }
    // 여기서 헤맴
    // stages[i]가 바뀌지 않으면서 위 for문을 빠져 나온다면, 
    // 해당 stage의 실패율 값을 따로 저장해 줘야한다
    // stages[i]가 N+1로 위 for문을 빠져나온다면 해당 stage의 실패율은 0이므로 
    // 아무 작업도 하지 않는다. (실패율 초기값 0으로 설정)
    if (total != 0 && stage != N + 1) {
        result[stage - 1].ratio = (float)cnt / total;
    }

    // 모든 stage의 실패율 값이 작은 stage 순서로 저장되어 있는 result 배열을
    // 실패율이 큰 stage를 앞으로, 실패율이 같다면 idx가 큰 stage를 앞으로 보내며 정렬한다
    sort(result.begin(), result.end(), cmp);
    // answer에 저장
    for (int i = 0; i < result.size(); i++)
        answer.push_back(result[i].idx + 1);

    return answer;
}

int main() {


    vector<int> sol = solution(5,{ 1,1,1,1,1 });


    return 0;
}