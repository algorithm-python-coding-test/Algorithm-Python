/*
* problem : ũ���� �����̱� (https://programmers.co.kr/learn/courses/30/lessons/64061)
*/

//�ٱ��Ͽ� ���� ��� �������� ������ ������ -> stack�� ����Ͽ� Ǯ�̸� ��������
//board�� moves�� ũ�� ��� ����� �����Ƿ� �ð����⵵�� ������� �ʰ� ������ �� �ִ�.

//Solving Time : 20min

#include <string>
#include <vector>
#include <stack>

using namespace std;

stack<int> bucket;
stack<int> machine[30];

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int size = board[0].size();
    for (int i = size - 1; i >= 0; i--) {
        for (int j = 0; j < size; j++) {
            if (board[i][j] != 0) {
                machine[j].push(board[i][j]);
            }
        }
    }

    for (int i = 0; i < moves.size(); i++) {
        if (machine[moves[i] - 1].empty())
            continue;
        int doll = machine[moves[i] - 1].top();
        machine[moves[i] - 1].pop();

        if (bucket.empty())
            bucket.push(doll);
        else if (bucket.top() == doll) {
            bucket.pop();
            answer += 2;
        }
        else {
            bucket.push(doll);
        }
    }
    return answer;
}