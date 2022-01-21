// Solution -> CheckBoard -> QueenMove
// 퀸은 행 하나에 하나씩만 놓아야한다
// 하나의 행에서 각각의 열에 퀸을 놓았을때 가능한 모든 경우를 센다.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <vector>

using namespace std;

// a_row 행 a_col 열에 위치한 queen이 이동할 수 있는곳에 모두 값 1을 대입
void QueenMove(vector<vector<int>> &a_board, int a_board_size, int a_row, int a_col)
{
    // 가장 위 행부터 아래로 queen을 둘 것이기 때문에 아래부분만 기록하면 된다.

    // a_row에 있는, 모든 칸에 Queen의 방문을 기록
    for (int i = a_col; i < a_board_size; i++)
    {
        a_board[a_row][i] = 1;
    }

    // a_col에 있는, 모든 칸에 Queen의 방문을 기록
    for (int i = a_row; i < a_board_size; i++)
    {
        a_board[i][a_col] = 1;
    }

    // 아래 대각선에 있는 것들 중, 모든 칸에 Queen의 방문을 기록
    int temp_row = a_row + 1;

    for (int i = 1; temp_row < a_board_size; temp_row++, i++)
    {
        if (a_col - i >= 0)
        {
            a_board[temp_row][a_col - i] = 1;
        }
        if (a_col + i < a_board_size)
        {
            a_board[temp_row][a_col + i] = 1;
        }
    }
}

// a_row 행 a_col 열에 queen이 있을때, 나머지 queen을 둘 수 있는 경우의 수를 반환
int CheckBoard(int a_row, int a_col, vector<vector<int>> a_board, int a_board_size, int queen_count)
{
    // queen_count가 0이 되면 모든 queen을 체스판에 둔 것이므로 1개의 완성된 경우가 된다.
    // 그래서 1을 바로 반환
    if (queen_count == 0) return 1;

    // 가능한 경우의 수를 저장할 변수
    int possible_cases = 0;

    // a_row, a_col에 queen을 둘 때 그 queen이 이동 가능한 곳을 체스판에 기록
    QueenMove(a_board, a_board_size, a_row, a_col);

    // 다음 퀸은 무조건 바로 다음 행에만 둘 수 있다 (1행 1퀸)
    int next_row = a_row + 1;
    
    // 다음 행에서 어느 위치의 열에 퀸을 둘 수 있는지 하나씩 체크한다
    for (int next_col = 0; next_col < a_board_size; next_col++)
    {
        // 해당 위치에 이전 queen들의 이동 기록 1이 있다면 안됨
        if (a_board[next_row][next_col]) continue;
        else
        {
            // 아니라면 그 위치에 퀸을 두고, queen_count를 하나 감소시킨 상황에서 재귀호출
            possible_cases += CheckBoard(next_row, next_col, a_board, a_board_size, queen_count - 1);
        }
    }
    return possible_cases;
}

int solution(int n) {
    int answer = 0;

    // 체스판 배열
    vector<vector<int>> board;

    // 12*12 크기의 체스판 초기화
    for (int i = 0; i < n; i++)
    {
        vector<int> sub(12);
        board.push_back(sub);
    }

    // 첫번째 행에서 첫번째 퀸이 어디에 있냐에 따라 하나씩 체크한다.
    // 퀸을 배열 할 수 있는 경우는 체스판의 중점을 기준으로 좌우가 같다
    // 그래서 반만 계산하여 곱2를 해준다
    for (int i = 0; i < n /2 ; i++)
    {
        int row = i / n;
        int col = i % n;

        // 첫번째 퀸이 위 row, col에 위치했을때, 나머지 퀸을 배치할 수 있는 경우의 수를 계산
        answer += CheckBoard(row, col, board, n, n - 1);
    }
    answer *= 2;

    // 체스판 크기가 홀수일 경우엔 중간지점에 퀸이 위치할 경우를 따로 계산해준다
    if (n % 2)  answer += CheckBoard((n / 2) / n, (n / 2) % n, board, n, n - 1);

    return answer;
}
