#include <string>
#include <queue>
#include <iostream>
using namespace std;

#define X first
#define Y second

string maze[1000];
// 지훈이의 도착시간
int jihun[1000][1000];
// 불이 번지는 시간
int fire[1000][1000];

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int r, c;
    cin >> r >> c;
    
    // 지훈이 도착시간, 불이번지는 시간 모두 -1로 초기화
    for (int i = 0; i < r; i++) {
        fill(jihun[i], jihun[i] + c, -1);
        fill(fire[i], fire[i] + c, -1);
    }

    // 지훈이 도착, 불의 번짐을 bfs처리 하기 위한 큐
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
    // 불 번짐 연산
    while (!q2.empty()) {
        pair<int, int> cur = q2.front();
        q2.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            // 불이 벌써 번진 곳이거나 벽이라면 continue ( bfs라서 순차적으로 불이 번짐)
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
            // 미로 밖 탈출
            if (nx < 0 || nx >= r || ny < 0 || ny >= c) {
                cout << jihun[cur.X][cur.Y] + 1;
                return 0;
            }
            // 지훈이가 벌써 지나간 곳이거나 벽이라면 continue
            if (jihun[nx][ny] != -1 || maze[nx][ny] == '#') continue;
            // 불이 번진 곳인데 지훈이 도착시간과 동시에 또는 일찍 번진 불이라면 continue
            if (fire[nx][ny] != -1 && jihun[cur.X][cur.Y] + 1 >= fire[nx][ny]) continue;
            jihun[nx][ny] = jihun[cur.X][cur.Y] + 1;
            q1.push({ nx,ny });
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}