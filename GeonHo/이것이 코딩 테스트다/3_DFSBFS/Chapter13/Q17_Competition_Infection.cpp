#include <iostream>
#include <queue>

using namespace std;

//���̷��� Ŭ���� ����
//second�ʿ� (y, x)�� �����ϴ� index��ȣ�� ���̷���
class Virus {
public:
    int index;
    int second;
    int x;
    int y;
    Virus(int index, int second, int x, int y) {
        this->index = index;
        this->second = second;
        this->x = x;
        this->y = y;
    }

    // ���� ������ '��ȣ�� ���� ����'
    bool operator <(Virus& other) {
        return this->index < other.index;
    }
};

int N, K;
int graph[200][200];
int S, X, Y;

vector<Virus> viruses;
//���̷����� ������ �� �ִ� ���
//��, ��, ��, ��
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

int main()
{
    //N, K �Է�
    cin >> N >> K;
    //����� ���� �Է�
    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < N; y++)
        {
            cin >> graph[x][y];
            //������� (i, j)ĭ�� ���̷����� ������ ���
            if (graph[x][y] != 0)
            {
                //���̷����� ����, �ð�, ��ġ �Է�
                viruses.push_back(Virus(graph[x][y], 0, x, y));
            }
        }
    }
    //S, X, Y �Է�
    cin >> S >> X >> Y;
    //���� ��ȣ�� ���̷����� �տ� ������ ����
    sort(viruses.begin(), viruses.end());

    //BFS����
    queue<Virus> q;
    for (int i = 0; i < viruses.size(); i++)
    {
        q.push(viruses[i]);
    }
    while (!q.empty())
    {
        Virus virus = q.front();
        q.pop();

        if (virus.second == S) break;

        for (int i = 0; i < 4; i++)
        {
            //���̷����� ���� �� �ִ� �׹����� ���ɼ� �˻�
            int next_x = virus.x + dx[i];
            int next_y = virus.y + dy[i];

            //���� ������ ������� ����� ������
            if (0 <= next_x && 0 <= next_y && N > next_x && N > next_y)
            {
                //���� �湮���� ���� ����� �̶��
                if (graph[next_x][next_y] == 0)
                {
                    //�ش� ������� ���̷��� ����
                    graph[next_x][next_y] = virus.index;
                    //���̷����� �����ϴ� queue�� ���� ������ ���̷��� ����
                    q.push(Virus(virus.index, virus.second + 1, next_x, next_y));
                }
            }
        }
    }

    cout << graph[X - 1][Y - 1];
}