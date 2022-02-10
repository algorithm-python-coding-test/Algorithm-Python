/*
������ȹ��
- �� ���ڿ��� �տ������� �ϳ��� ���Ͽ� �ִ� �κ� ������ ���̸� �Ź� �������ش�
- ���ϴ� ���ڰ� ���ٸ�, ���� �񱳿����� �ִ� �κ� ������ ���̿� 1�� ���� ��
  ( ���⼭ �������� �� ���ڿ��� ���̰� ��� ���� �� ���̺��� �ϳ��� �������� �񱳰�)
- ���ϴ� ���ڰ� �ٸ��ٸ�, ���� �񱳿����� �ִ� �κ� ������ ���̰�
  ( ���⼭ �������� �� ���ڿ� �� �ϳ��� ���� �� ����, �ϳ��� ���� �� ���̺��� �ϳ� �������� �񱳰�)
*/


#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s1, s2;

    cin >> s1 >> s2;

    int s1_size = s1.size();
    int s2_size = s2.size();

    vector<vector<int>> answer_arr(s2_size + 1, vector<int>(s1_size + 1, 0));

    for (int i = 1; i < s2_size + 1; i++)
    {
        for (int j = 1; j < s1_size + 1; j++)
        {
            if (s1[j - 1] == s2[i - 1]) answer_arr[i][j] = answer_arr[i - 1][j - 1] + 1;
            else
            {
                answer_arr[i][j] = max(answer_arr[i - 1][j], answer_arr[i][j - 1]);
            }
        }
    }

    int answer = answer_arr[s2_size][s1_size];
    
    cout << answer << "\n";

    return 0;
}
