#include <iostream>
#include <queue>

using namespace std;

int n, m;
int maze[201][201];

// �̵��� �� ���� ���� ���� (��, ��, ��, ��) 
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int main(void) {
    // N, M�� ������ �������� �����Ͽ� �Է� �ޱ�
    cin >> n >> m;
    // 2���� ����Ʈ�� �� ���� �Է� �ޱ�
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf_s("%1d", &maze[i][j]);
        }
    }
    // ť(Queue) ������ ���� queue ���̺귯�� ��� 
    queue<pair<int, int> > q;
    q.push({0, 0});
    // ť�� �� ������ �ݺ��ϱ� 
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        // ���� ��ġ���� 4���� ���������� ��ġ Ȯ��
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            // �̷� ã�� ������ ��� ��� ����
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            // ���� ��� ����
            if (maze[nx][ny] == 0) continue;
            // �ش� ��带 ó�� �湮�ϴ� ��쿡�� �ִ� �Ÿ� ���
            if (maze[nx][ny] == 1) {
                maze[nx][ny] = maze[x][y] + 1;
                q.push({ nx, ny });
            }
        }
    }

    cout << maze[n - 1][m - 1];
}