

/*
2시간 소요

- 값을 참조하는데 시간이 O(1)인 hash_map을 사용해기로 함
- 전체 데이터를 hash_map에 저장 후, 삭제되는 행들만 따로 관리해보기로 함

- 선택된 행을 위,아래로 옮길때 효율적인 이동을 위해
  삭제되지 않은 행 중 선택된 행의 바로 이전행(prev), 이후행(next)의 index값을 저장하고 있는 구조체 ND사용
- 삭제된 행의 index는 stack에 넣어 관리하고, 행이 삭제 됐을 시 그 행의 이전행, 이후행의 prev,next를 연결리스트처럼 잘 연결해줌
- 복원된 행 또한 이전행, 이후행의 prev,next를 잘 연결해줌
- 가장 마지막에 삭제된 행이 가장 먼저 복원되기 때문에, 복원된 행의 이전행, 이후행 정보가 왜곡될 일은 없음

효율성  테스트
테스트 1 〉	통과 (120.50ms, 61.9MB)
테스트 2 〉	통과 (108.91ms, 61.9MB)
테스트 3 〉	통과 (124.28ms, 61.9MB)
테스트 4 〉	통과 (111.77ms, 62.1MB)
테스트 5 〉	통과 (102.26ms, 62.2MB)
테스트 6 〉	실패 (시간 초과)
테스트 7 〉	통과 (31.99ms, 27.1MB)
테스트 8 〉	통과 (32.15ms, 29MB)
테스트 9 〉	실패 (시간 초과)
테스트 10 〉	실패 (시간 초과)
채점 결과
정확성: 30.0
효율성: 49.0
합계: 79.0 / 100.0

- 연결리스트 형태로 푸는것은 맞으나, hash_table을 이용할때 key값을 참조하는 시간이 꽤나 소요되는것 같음 O(1) 
- 더 시도했으나 개선하지 못함
*/


#include <string>
#include <vector>

using namespace std;

#include <unordered_map>
#include <stack>

// hash_table의 value로 사용할 구조체 정보
typedef struct node
{
    int prev;
    int next;
    char del = 0;
} ND;

string solution(int n, int k, vector<string> cmd) {
    string answer = "";

    unordered_map<int, ND> chart;

    for (int i = 0; i < n; i++) {
        ND temp;

        if (i == 0) temp.prev = -1;
        else temp.prev = i - 1;

        if (i == (n - 1)) temp.next = -1;
        else temp.next = i + 1;
        
        chart[i] = temp;
    }

    stack<int> dels;

    int curr = k;

    for (int i = 0; i < cmd.size(); i++) {

        string cur_cmd = cmd[i];
        if (cur_cmd[0] == 'U') {
            int up_cnt = stoi(cur_cmd.substr(2));

            // up_cnt번 위로 이동
            for (int i = 0; i < up_cnt; i++) 
                curr = chart[curr].prev;
        }
        else if (cur_cmd[0] == 'D') {
            int down_cnt = stoi(cur_cmd.substr(2));

            // down_cnt번 아래로 이동
            for (int i = 0; i < down_cnt; i++) 
                curr = chart[curr].next;
        }
        else if (cur_cmd[0] == 'C') {
            ND* p = &chart[curr];
            // 삭제 되었음을 저장
            chart[curr].del = 1;
            // stack에 삭제된 행의 index 저장
            dels.push(curr);

            int next_curr = *p.next;
            int prev_curr = chart[curr].prev;

            if (next_curr != -1) {
                chart[next_curr].prev = prev_curr;
                // 선택된 행은 그 다음행
                curr = next_curr;
            }
            else // 선택된 행은 다음행이 없으므로 이전행
                curr = prev_curr;

            if (prev_curr != -1) 
                chart[prev_curr].next = next_curr;
        }
        else {
            // 복원될 행의 index
            int back_index = dels.top();
            dels.pop();

            chart[back_index].del = 0;

            int prev = chart[back_index].prev;
            int next = chart[back_index].next;

            if (prev != -1) 
                chart[prev].next = back_index;

            if (next != -1) 
                chart[next].prev = back_index;
        }
    }

    for (int i = 0; i < n; i++) {
        if (chart[i].del == 0)
            answer.push_back('O');
        else
            answer.push_back('X');
    }
    return answer;
}
