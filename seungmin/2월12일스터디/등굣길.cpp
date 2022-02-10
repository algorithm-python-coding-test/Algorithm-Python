/*
- (1,1) ���� (4,3)���� ���� ����� �� : ��� 4-1=3ĭ, �Ʒ��� 3-1=2ĭ�� �����Ѵ�
- ��3ĭ�� �Ʒ�2ĭ�� ������ �ٷ� ����� ���� �ȴ� : (3+2)! / (3!*2!) 
- ó���� ��ü ����� ������ puddle�� ��ġ�� ����� ���� ���� ������ ���
-> �� overflow ( 22! �� �Ѿ�� unsigned long long�� ��� )

- ������ȹ������ Ǫ�µ�, ����ؼ� ������������ �������
*/

#include <bits/stdc++.h>

using namespace std;

// ���� �迭 �ִ� ũ�� 100*100
unsigned long long ways_arr[100][100];

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;

    // 0���� ���������� m,n�� 1���� �־����Ƿ� 1 ����
    // ���⼱ n�� ��, m�� ���� �־���
    unsigned int goal_row = n - 1;
    unsigned int goal_col = m - 1;

    // 1���� �ִ� ĭ���� (0,0)���� �� �� �ִ� ����� ��� �Ѱ��� ����
    for (int i = 0; i <= goal_row; i++) ways_arr[i][0] = 1;
    // 1�࿡ �ִ� ĭ���� (0,0)���� �� �� �ִ� ����� ��� �Ѱ��� ����
    for (int i = 0; i <= goal_col; i++) ways_arr[0][i] = 1;

    // ��, 1�࿡ �ִ� ĭ�� �� �߰��� puddle�� �ִٸ�, 
    // puddle�� ���� ���θ����Ƿ� puddle �ڿ��ִ� ĭ���� ��� �� �� �ִ� ����� 0�� ��
    for (int i = 0; i < puddles.size(); i++)
    {
        // puddle�� �ִ°��� ���� �迭���� -1�� ���� ( �̶��� �ప�� �ι�°, ������ ù��°�� ����Ǿ����� )
        ways_arr[puddles[i][1] - 1][puddles[i][0] - 1] = -1;

        // puddle�� �ִ°��� 1�� �̶��
        if (puddles[i][1] - 1 == 0)
        {
            // 1���� �ִ� ĭ�� �� puddle�ڿ� �ִ� ĭ���� ��� �� �� �ִ� ����� 0
            for (int j = puddles[i][0] - 1; j <= goal_col; j++) ways_arr[0][j] = 0;
        }
        // puddle�� �ִ°��� 1�� �̶��
        if (puddles[i][0] - 1 == 0)
        {
            // 1���� �ִ� ĭ�� �� puddle�ؿ� �ִ� ĭ���� ��� �� �� �ִ� ����� 0
            for (int j = puddles[i][1] - 1; j <= goal_row; j++) ways_arr[j][0] = 0;
        }
    }

    // �ϳ��� ĭ�� �Űܰ��� ��� 
    for (int i = 1; i <= goal_row; i++)
    {
        for (int j = 1; j <= goal_col; j++)
        {
            // �ش�ĭ�� puddle�� �ƴ϶��
            if (ways_arr[i][j] != -1) {
                // ����ĭ, ��ĭ�� ��� puddle�̶�� �ش�ĭ���� �� �� �ִ� ����� ����
                if (ways_arr[i][j - 1] == -1 && ways_arr[i - 1][j] == -1) ways_arr[i][j] = 0;
                // �� ĭ�� puddle�� �ƴϸ� �� ĭ���� ���� ����ۿ� ����
                else if (ways_arr[i][j - 1] == -1) ways_arr[i][j] = ways_arr[i - 1][j];
                // �� ĭ�� puddle�� �ƴϸ� �� ĭ���� ���� ����ۿ� ����
                else if (ways_arr[i - 1][j] == -1) ways_arr[i][j] = ways_arr[i][j - 1];
                // ��ĭ, ��ĭ ��� puddle�� �ƴϸ� �� ��ο��� �� �� ����
                // �� ����� ���� �ʹ� Ŀ���� �����ϰ��� 1000000007 ������ ������ ����
                // ( a + b) ( mod n) = ( a mod n) + ( b mod n) �� �����ϹǷ� ���� ���ϴµ� ������ ���� (����, ������ ��������)
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
