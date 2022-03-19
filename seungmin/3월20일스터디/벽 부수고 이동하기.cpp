#include <queue>
#include <iostream>
using namespace std;

struct node {
    int x, y;
    int path;
    char wall;
};

char board[1000][1000];
// ���� �μ��� ���� ��ο� ���� �湮ǥ��
char vis1[1000][1000];
// ���� �μ� ��ο� ���� �湮 ǥ��
char vis2[1000][1000];

int n, m;
int sht_path = 1e9;

// ��->��->��->�� Ž��
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
            // board[nx][ny] == '0'�� ���
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


// ó�� ������ �ڵ�
// �ݷ�
/* �� �� �� ��
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
    // ���ݱ��� ����� ����
    int path;
    // ���� �μ����� �ִٸ� 1, ���ٸ� 0
    char wall;
};

char board[1000][1000];
// �湮ǥ��
char vis[1000][1000];

// ���� ����, ���� ����
int n, m;
// �ִ� ��� ����
int sht_path = 1e9;

// ��->��->��->�� Ž��
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