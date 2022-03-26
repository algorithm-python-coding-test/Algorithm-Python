#include <string>
#include <queue>
#include <iostream>
using namespace std;

#define X first
#define Y second

string maze[1000];
// �������� �����ð�
int jihun[1000][1000];
// ���� ������ �ð�
int fire[1000][1000];

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int r, c;
    cin >> r >> c;
    
    // ������ �����ð�, ���̹����� �ð� ��� -1�� �ʱ�ȭ
    for (int i = 0; i < r; i++) {
        fill(jihun[i], jihun[i] + c, -1);
        fill(fire[i], fire[i] + c, -1);
    }

    // ������ ����, ���� ������ bfsó�� �ϱ� ���� ť
    queue<pair<int, int>> q1;
    queue<pair<int, int>> q2;

    for (int i = 0; i < r; i++) {
        cin >> maze[i];
        for (int j = 0; j < c; j++) {
            if (maze[i][j] == 'J') {
                jihun[i][j] = 0;
                q1.push({ i,j });
            }
            if (maze[i][j] == 'F') {
                fire[i][j] = 0;
                q2.push({ i,j });
            }
        }
    }
    // �� ���� ����
    while (!q2.empty()) {
        pair<int, int> cur = q2.front();
        q2.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            // ���� ���� ���� ���̰ų� ���̶�� continue ( bfs�� ���������� ���� ����)
            if (fire[nx][ny] != -1 || maze[nx][ny] == '#') continue;
            fire[nx][ny] = fire[cur.X][cur.Y] + 1;
            q2.push({ nx,ny });
        }
    }

    while (!q1.empty()) {
        pair<int, int> cur = q1.front();
        q1.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            // �̷� �� Ż��
            if (nx < 0 || nx >= r || ny < 0 || ny >= c) {
                cout << jihun[cur.X][cur.Y] + 1;
                return 0;
            }
            // �����̰� ���� ������ ���̰ų� ���̶�� continue
            if (jihun[nx][ny] != -1 || maze[nx][ny] == '#') continue;
            // ���� ���� ���ε� ������ �����ð��� ���ÿ� �Ǵ� ���� ���� ���̶�� continue
            if (fire[nx][ny] != -1 && jihun[cur.X][cur.Y] + 1 >= fire[nx][ny]) continue;
            jihun[nx][ny] = jihun[cur.X][cur.Y] + 1;
            q1.push({ nx,ny });
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}