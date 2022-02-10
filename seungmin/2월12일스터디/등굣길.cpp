/*
- (1,1) 에서 (4,3)으로 가는 경우의 수 : 우로 4-1=3칸, 아래로 3-1=2칸을 가야한다
- 우3칸과 아래2칸의 조합이 바로 경우의 수가 된다 : (3+2)! / (3!*2!) 
- 처음에 전체 경우의 수에서 puddle을 거치는 경우의 수를 빼는 것으로 계산
-> 값 overflow ( 22! 만 넘어가도 unsigned long long을 벗어남 )

- 동적계획법으로 푸는데, 계속해서 나머지연산을 해줘야함
*/

#include <bits/stdc++.h>

using namespace std;

// 격자 배열 최대 크기 100*100
unsigned long long ways_arr[100][100];

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;

    // 0부터 시작이지만 m,n은 1부터 주어지므로 1 뺄셈
    // 여기선 n이 행, m이 열로 주어짐
    unsigned int goal_row = n - 1;
    unsigned int goal_col = m - 1;

    // 1열에 있는 칸들은 (0,0)에서 갈 수 있는 방법이 모두 한가지 뿐임
    for (int i = 0; i <= goal_row; i++) ways_arr[i][0] = 1;
    // 1행에 있는 칸들은 (0,0)에서 갈 수 있는 방법이 모두 한가지 뿐임
    for (int i = 0; i <= goal_col; i++) ways_arr[0][i] = 1;

    // 단, 1행에 있는 칸들 중 중간에 puddle이 있다면, 
    // puddle에 의해 가로막히므로 puddle 뒤에있는 칸들은 모두 갈 수 있는 방법이 0이 됨
    for (int i = 0; i < puddles.size(); i++)
    {
        // puddle이 있는곳은 격자 배열에서 -1로 설정 ( 이때도 행값이 두번째, 열값이 첫번째에 저장되어있음 )
        ways_arr[puddles[i][1] - 1][puddles[i][0] - 1] = -1;

        // puddle이 있는곳이 1행 이라면
        if (puddles[i][1] - 1 == 0)
        {
            // 1행이 있는 칸들 중 puddle뒤에 있는 칸들은 모두 갈 수 있는 방법이 0
            for (int j = puddles[i][0] - 1; j <= goal_col; j++) ways_arr[0][j] = 0;
        }
        // puddle이 있는곳이 1열 이라면
        if (puddles[i][0] - 1 == 0)
        {
            // 1열이 있는 칸들 중 puddle밑에 있는 칸들은 모두 갈 수 있는 방법이 0
            for (int j = puddles[i][1] - 1; j <= goal_row; j++) ways_arr[j][0] = 0;
        }
    }

    // 하나의 칸씩 옮겨가며 계산 
    for (int i = 1; i <= goal_row; i++)
    {
        for (int j = 1; j <= goal_col; j++)
        {
            // 해당칸이 puddle이 아니라면
            if (ways_arr[i][j] != -1) {
                // 왼쪽칸, 윗칸이 모두 puddle이라면 해당칸으로 갈 수 있는 방법은 없음
                if (ways_arr[i][j - 1] == -1 && ways_arr[i - 1][j] == -1) ways_arr[i][j] = 0;
                // 위 칸만 puddle이 아니면 위 칸에서 가는 방법밖에 없음
                else if (ways_arr[i][j - 1] == -1) ways_arr[i][j] = ways_arr[i - 1][j];
                // 왼 칸만 puddle이 아니면 왼 칸에서 가는 방법밖에 없음
                else if (ways_arr[i - 1][j] == -1) ways_arr[i][j] = ways_arr[i][j - 1];
                // 왼칸, 위칸 모두 puddle이 아니면 둘 모두에서 갈 수 있음
                // 단 경우의 수가 너무 커짐을 방지하고자 1000000007 나머지 연산을 해줌
                // ( a + b) ( mod n) = ( a mod n) + ( b mod n) 을 만족하므로 답을 구하는데 지장이 없다 (뺄셈, 곱셈도 마찬가지)
                else
                {
                    ways_arr[i][j] = (ways_arr[i - 1][j] + ways_arr[i][j - 1]) % 1000000007;
                }
            }
        }
    }
    
    answer = ways_arr[goal_row][goal_col];

    return answer;
}

int main()
{
    
    return 0;
}
