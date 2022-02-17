/*
������� ��
- ������ ��� ��츦 dfs�� �ƴ� next_permutation���� ���Ϸ��ٰ� ����
- Set �ڷᱸ���� ���� ������ ��� �ߺ� ó���� ������� -> ������ ������ �ִ� 7823ms �ҿ�
*/

/*
�ٸ� ����� Ǯ�� : dfs ���

- user_id�� ��� ��츦 dfsŽ���Ͽ� ���� ���̵� ���� �����ϰ�,
- ������̵�� Set�� ���� ( �ߺ� ��� X )

�ִ� : 20.79ms, 4.11MB
�ּ� : 0.01ms, 4.1MB
*/

#include <bits/stdc++.h>
using namespace std;

bool used[10];
set<string> S;

// �ҷ����̵� ���� Ȯ��
bool possi(string a, string b) {
    if (a.length() != b.length())
        return false;
    for (int i = 0; i < a.length(); i++)
        if (a[i] != b[i] && b[i] != '*')
            return false;
    return true;
}

void dfs(int p, vector<string> user_id, vector<string> banned_id) {
    // �ҷ����̵� ��� ã�Ҵٸ�
    if (p == banned_id.size()) {
        string tmp;
        // index�� �̾� �ٿ� tmp�� ����
        // user_id = { "abc", "fff", "wer", "def" } �̰�
        // < "abc", "def" > , < "def" , "abc" >�� ���� ���̵���
        // user_id �տ��� ���� Ž���ϹǷ� tmp�� �Ѵ� "03"�� ��
        for (int i = 0; i < user_id.size(); i++)
            if (used[i]) tmp += i + '0';
        // ���� "03"�̹Ƿ� Set���� �ϳ��� ��޵�
        S.insert(tmp);
        return;
    }
    // dfs Ž�� : Ž���� ���̵�� true ó��
    for (int i = 0; i < user_id.size(); i++)
        if (!used[i] && possi(user_id[i], banned_id[p]))
            used[i] = true, dfs(p + 1, user_id, banned_id), used[i] = false;
}

int solution(vector<string> user_id, vector<string> banned_id) {
    dfs(0, user_id, banned_id);
    return S.size();
}

int main()
{
    
    return 0;
}
