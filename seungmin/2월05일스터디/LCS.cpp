/*
동적계획법
- 두 문자열을 앞에서부터 하나씩 비교하여 최대 부분 수열의 길이를 매번 갱신해준다
- 비교하는 문자가 같다면, 이전 비교에서의 최대 부분 수열의 길이에 1을 더한 값
  ( 여기서 이전값은 두 문자열의 길이가 모두 현재 비교 길이보다 하나씩 적을때의 비교값)
- 비교하는 문자가 다르다면, 이전 비교에서의 최대 부분 수열의 길이값
  ( 여기서 이전값은 두 문자열 중 하나는 현재 비교 길이, 하나는 현재 비교 길이보다 하나 적을때의 비교값)
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
