// Solution -> CheckBoard -> QueenMove
// ���� �� �ϳ��� �ϳ����� ���ƾ��Ѵ�
// �ϳ��� �࿡�� ������ ���� ���� �������� ������ ��� ��츦 ����.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <vector>

using namespace std;

// a_row �� a_col ���� ��ġ�� queen�� �̵��� �� �ִ°��� ��� �� 1�� ����
void QueenMove(vector<vector<int>> &a_board, int a_board_size, int a_row, int a_col)
{
    // ���� �� ����� �Ʒ��� queen�� �� ���̱� ������ �Ʒ��κи� ����ϸ� �ȴ�.

    // a_row�� �ִ�, ��� ĭ�� Queen�� �湮�� ���
    for (int i = a_col; i < a_board_size; i++)
    {
        a_board[a_row][i] = 1;
    }

    // a_col�� �ִ�, ��� ĭ�� Queen�� �湮�� ���
    for (int i = a_row; i < a_board_size; i++)
    {
        a_board[i][a_col] = 1;
    }

    // �Ʒ� �밢���� �ִ� �͵� ��, ��� ĭ�� Queen�� �湮�� ���
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

// a_row �� a_col ���� queen�� ������, ������ queen�� �� �� �ִ� ����� ���� ��ȯ
int CheckBoard(int a_row, int a_col, vector<vector<int>> a_board, int a_board_size, int queen_count)
{
    // queen_count�� 0�� �Ǹ� ��� queen�� ü���ǿ� �� ���̹Ƿ� 1���� �ϼ��� ��찡 �ȴ�.
    // �׷��� 1�� �ٷ� ��ȯ
    if (queen_count == 0) return 1;

    // ������ ����� ���� ������ ����
    int possible_cases = 0;

    // a_row, a_col�� queen�� �� �� �� queen�� �̵� ������ ���� ü���ǿ� ���
    QueenMove(a_board, a_board_size, a_row, a_col);

    // ���� ���� ������ �ٷ� ���� �࿡�� �� �� �ִ� (1�� 1��)
    int next_row = a_row + 1;
    
    // ���� �࿡�� ��� ��ġ�� ���� ���� �� �� �ִ��� �ϳ��� üũ�Ѵ�
    for (int next_col = 0; next_col < a_board_size; next_col++)
    {
        // �ش� ��ġ�� ���� queen���� �̵� ��� 1�� �ִٸ� �ȵ�
        if (a_board[next_row][next_col]) continue;
        else
        {
            // �ƴ϶�� �� ��ġ�� ���� �ΰ�, queen_count�� �ϳ� ���ҽ�Ų ��Ȳ���� ���ȣ��
            possible_cases += CheckBoard(next_row, next_col, a_board, a_board_size, queen_count - 1);
        }
    }
    return possible_cases;
}

int solution(int n) {
    int answer = 0;

    // ü���� �迭
    vector<vector<int>> board;

    // 12*12 ũ���� ü���� �ʱ�ȭ
    for (int i = 0; i < n; i++)
    {
        vector<int> sub(12);
        board.push_back(sub);
    }

    // ù��° �࿡�� ù��° ���� ��� �ֳĿ� ���� �ϳ��� üũ�Ѵ�.
    // ���� �迭 �� �� �ִ� ���� ü������ ������ �������� �¿찡 ����
    // �׷��� �ݸ� ����Ͽ� ��2�� ���ش�
    for (int i = 0; i < n /2 ; i++)
    {
        int row = i / n;
        int col = i % n;

        // ù��° ���� �� row, col�� ��ġ������, ������ ���� ��ġ�� �� �ִ� ����� ���� ���
        answer += CheckBoard(row, col, board, n, n - 1);
    }
    answer *= 2;

    // ü���� ũ�Ⱑ Ȧ���� ��쿣 �߰������� ���� ��ġ�� ��츦 ���� ������ش�
    if (n % 2)  answer += CheckBoard((n / 2) / n, (n / 2) % n, board, n, n - 1);

    return answer;
}
