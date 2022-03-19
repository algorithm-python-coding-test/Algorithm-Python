#include <queue>
#include <iostream>
using namespace std;

struct node {
    int x, y;
    int path;
    char wall;
};

char board[1000][1000];
// 벽을 부수지 않은 경로에 대한 방문표시
char vis1[1000][1000];
// 벽을 부순 경로에 대한 방문 표시
char vis2[1000][1000];

int n, m;
int sht_path = 1e9;

// 상->우->하->좌 탐색
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    queue<node> Q;
    vis1[0][0] = 1;
    vis2[0][0] = 1;
    Q.push({ 0,0,1,0 });
    while (!Q.empty()) {
        node cur = Q.front(); Q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (cur.wall == 0 && vis1[nx][ny]) continue;
            if (cur.wall == 1 && (vis2[nx][ny] || board[nx][ny] == '1')) continue;
            if (nx == n - 1 && ny == m - 1) {
                if (cur.path + 1 < sht_path)
                    sht_path = cur.path + 1;
                continue;
            }
            if (cur.wall == 0) vis1[nx][ny] = 1;
            else vis2[nx][ny] = 1;

            if (board[nx][ny] == '1' && cur.wall == 0) {
                Q.push({ nx, ny, cur.path + 1, 1 });
            }
            // board[nx][ny] == '0'인 경우
            else {
                Q.push({ nx, ny, cur.path + 1, cur.wall });
            }
        }
    }
    if (n == 1 && m == 1) sht_path = 1;
    if (sht_path == 1e9) sht_path = -1;
    cout << sht_path << '\n';

    return 0;
}


// 처음 구현한 코드
// 반례
/* 상 우 하 좌
4 6
011111
011111
011000
000010

#include <queue>
#include <iostream>
using namespace std;

struct node {
    int x, y;
    // 지금까지 경로의 길이
    int path;
    // 벽을 부순적이 있다면 1, 없다면 0
    char wall;
};

char board[1000][1000];
// 방문표시
char vis[1000][1000];

// 행의 길이, 열의 길이
int n, m;
// 최단 경로 길이
int sht_path = 1e9;

// 상->우->하->좌 탐색
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    queue<node> Q;
    Q.push({ 0,0,1,0 });
    vis[0][0] = 1;
    while (!Q.empty()) {
        node cur = Q.front(); Q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (vis[nx][ny] || (cur.wall == 1 && board[nx][ny] == '1')) continue;
            if (nx == n - 1 && ny == m - 1) {
                if (cur.path + 1 < sht_path)
                    sht_path = cur.path + 1;
                continue;
            }
            vis[nx][ny] = 1;
            if (board[nx][ny] == '1' && cur.wall == 0) {
                Q.push({ nx, ny, cur.path + 1, 1 });
            } else {
                Q.push({ nx, ny, cur.path + 1, cur.wall });
            }
        }
    }
    if (sht_path == 1e9) sht_path = -1;
    cout << sht_path << '\n';

    return 0;
}

*/