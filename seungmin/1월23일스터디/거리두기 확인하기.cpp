// �� ������ Ž���Ѵ�.
// ���� ����� �ɾ��ִ� �� 'P'�� ã�� �ű⼭ Ž���� �����Ѵ�.
// Ž���� �����ϴ� ���� 'P'�� 'X'�� �ٲٰ� Ž���� �����Ѵ�. (�׷��� �� ĭ ������ �Ÿ��α� Ȯ�� �� ������ ���� �ʴ´�.)
// �����¿츦 Ȯ���Ͽ�, ��� 'P'�� ������ false (�� ĭ ������ �Ÿ��α� Ȯ��)
// ��Ƽ�� 'X'�� ������ �״�� �Ѿ��.
// ����� 'O'�� ������ �� ��������� �����¿츦 Ȯ���Ͽ� ��� 'P'�� �ִ��� Ȯ���Ѵ�. (�� ĭ ������ �Ÿ��α� Ȯ��)
// Ž���� false�� �ѹ��̶� ������ ��� �ݺ����� �������´�.


#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <vector>

using namespace std;

// ��, ��, ��, �� Ȯ���� ���� ��
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

bool SocialDistance2(vector<string> ap_place, int a_row, int a_col);

// ���� �� ���� ��ġ(a_row, a_col)���� 1ĭ ������ �����¿� Ȯ��
bool SocialDistance(vector<string> ap_place, int a_row, int a_col)
{
    // �Ÿ��αⰡ �� �Ǿ����� �����ϴ� ����
    bool is_success = true;

    // (�湮ó��) ���߿� �湮���� �ʱ����� ���� ��ġ�� ���¸� ��Ƽ�� 'X'�� �ٲٱ�
    ap_place[a_row][a_col] = 'X';

    // ���� ��ġ���� 1ĭ ������ �����¿� Ž��
    for (int i = 0; i < 4; i++)
    {
        // Ž���� ��ġ�� row, col ��
        int other_row = a_row + dy[i];
        int other_col = a_col + dx[i];

        // Ž���� ��ġ�� row, col�� ��ȿ�� ���� �ƴ϶�� ���� ��ġ�� �Ѿ
        if (other_row < 0 || other_row > 4) continue;
        if (other_col < 0 || other_col > 4) continue;

        // Ž���� ��ġ�� ���°��� �����ϴ� ����
        char other_condition = ap_place[other_row][other_col];

        // Ž���� ��ġ�� ���°��� 'P' ��� �Ÿ��αⰡ �� �Ȱ��̹Ƿ�
        // false ������ for���� ��� ���� ���´�
        if (other_condition == 'P')
        {
            is_success = false;
            break;
        }
        // Ž���� ��ġ�� ���°��� 'X' ��� �Ÿ��αⰡ  �Ȱ��̹Ƿ�
        // �ٷ� ���� ��ġ�� �Ѿ��
        else if (other_condition == 'X') continue;

        // Ž���� ��ġ�� ���°��� 'O' ��� �ű⿡�� �ٽ� �����¿츦 Ȯ���ؾ��Ѵ�. (���� ��ġ���� 2ĭ ������ ��)
        else
        {
            // Ž���� ��ġ���� �����¿츦 Ȯ���ϴ� �Լ� : �Ÿ��αⰡ �Ǿ��ٸ� true, �ƴϸ� false ��ȯ
            is_success = SocialDistance2(ap_place, other_row, other_col);

            // ���� ������ Ȯ���� ��� �Ÿ��αⰡ �ȵǾ��ٸ� ��� for�� Ż��
            if (is_success == false) break;
        }
    }
    // ���� ��ġ�� �Ÿ��α� ����� ��ȯ
    return is_success;
}

// �� ĭ ������ �Ÿ��α⸦ Ȯ���ϴ� �Լ�
// �����¿츦 Ȯ���Ͽ� 'P'�� �ִٸ� �Ÿ��αⰡ �� �ȰŰ�, 'O'�� 'X'�� �ִٸ� �Ÿ��αⰡ �� ��
bool SocialDistance2(vector<string> ap_place, int a_row, int a_col)
{
    bool is_success = true;

    for (int i = 0; i < 4; i++)
    {
        int other_row = a_row + dy[i];
        int other_col = a_col + dx[i];

        if (other_row < 0 || other_row > 4) continue;
        if (other_col < 0 || other_col > 4) continue;

        // Ž���� ��ġ�� ���°�
        char other_condition = ap_place[other_row][other_col];

        // 'P'�� ������ �Ÿ��α⸦ �� ��Ų��
        if (other_condition == 'P')
        {
            is_success = false;
            break;
        }
        // 'X'�� 'O'�� ������ �Ÿ��α⸦ ��Ų��
        else continue;
    }
    return is_success;
}


vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;

    // �� ������ �Ÿ��α⸦ ��Ű���� üũ�ϰ�
    // �� ���ο� ���� 0, 1 �� answer �迭�� ����
    for (int place_index = 0; place_index < 5; place_index++)
    {
        // �Ÿ��αⰡ ���������� ��Ÿ���� ����
        bool temp = true;

        // place_index��° ���ǿ��� �� ��Ұ� �Ÿ��α⸦ ��Ű���� �ϳ��� üũ
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                // ����� ���� �� ('P')�� �Ÿ��α� Ȯ��
                // SocialDistance�Լ� return ���� false��� �Ÿ��αⰡ �� ������ ���̹Ƿ� �ٷ� for�� Ż��
                if (places[place_index][i][j] == 'P' && !SocialDistance(places[place_index], i, j))
                {
                    temp = false;
                    break;
                }
            }
            // �Ÿ��αⰡ �� �������� for�� Ż��
            if (temp == false) break;
        }
        // place_index��° ������ �Ÿ��α��� ������� answer �迭�� ����
        answer.push_back(temp);
    }
    return answer;
}
