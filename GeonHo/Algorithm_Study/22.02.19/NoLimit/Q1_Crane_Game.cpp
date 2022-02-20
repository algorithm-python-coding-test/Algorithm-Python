//����ð� 0.01ms ~ 0.02ms

#include <string>
#include <vector>
#include <stack>

using namespace std;

//�ٱ��Ͽ� ���簢 ���ڸ� ǥ���� stack �ڷᱸ��
stack<int> bucket;
stack<int> machine[30];

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    //�Էµ� board�� ���� machine�� �ʱ�ȭ
    int size = board[0].size();
    for (int i = size - 1; i >= 0; i--) {
        for (int j = 0; j < size; j++) {
            if (board[i][j] != 0) {
                machine[j].push(board[i][j]);
            }
        }
    }
    //�Էµ� move�� ���� �����̱⸦ ����
    for (int i = 0; i < moves.size(); i++) {
        //�ش� ĭ�� ������ ���ٸ� �ƹ��ϵ� ���� �ʴ´�.
        if (machine[moves[i] - 1].empty())
            continue;
        //�ش� ĭ�� ������ �ִٸ� �ش� ������ �����Ѵ�.
        int doll = machine[moves[i] - 1].top();
        machine[moves[i] - 1].pop();
        //�ٱ��ϰ� ����ְų� ���õ� ������ �ٱ��� �� ���� ������ ���� �ʴٸ� push
        //���õ� ������ �ٱ��� �� ���� ������ ���� �����̶�� �� ������ ��Ʈ���� answer�� +2
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