#include <string>
using namespace std;

// ���� �ֺ��� ��,��,��,�� ��
// ������ ���� ���ٸ� 0, �ִٸ� 1 ����
struct adjacent {
    int up = 0;
    int down = 0;
    int left = 0;
    int right = 0;
} adj[11][11];

#define X first
#define Y second

int solution(string dirs) {
    int answer = 0;
    // ���� ��ġ (5,5)
    pair<int, int> cur = { 5,5 };
    
    for (int i = 0; i < dirs.size(); i++) {
        char dir = dirs[i];
        if (dir == 'L') {
            if (cur.Y == 0) continue;
            if (adj[cur.X][cur.Y].left == 0) answer++;
            adj[cur.X][cur.Y].left = 1;
            cur.Y -= 1;
            adj[cur.X][cur.Y].right = 1;

        } else if (dir == 'R') {
            if (cur.Y == 10) continue;
            if (adj[cur.X][cur.Y].right == 0) answer++;
            adj[cur.X][cur.Y].right = 1;
            cur.Y += 1;
            adj[cur.X][cur.Y].left = 1;

        } else if(dir == 'U') {
            if (cur.X == 0) continue;
            if (adj[cur.X][cur.Y].up == 0) answer++;
            adj[cur.X][cur.Y].up = 1;
            cur.X -= 1;
            adj[cur.X][cur.Y].down = 1;
        }
        // 'D'
        else {
            if (cur.X == 10) continue;
            if (adj[cur.X][cur.Y].down == 0) answer++;
            adj[cur.X][cur.Y].down = 1;
            cur.X += 1;
            adj[cur.X][cur.Y].up = 1;
        }
    }
    return answer;
}

int main()
{
    int sol = solution("ULURRDLLU");

    return 0;
}