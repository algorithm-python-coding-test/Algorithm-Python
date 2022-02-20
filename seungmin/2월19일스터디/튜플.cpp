/*
최대 : 10.27ms, 5.98MB
최소 : 0.01ms, 4.18MB
*/

/* 
각 배열에서 숫자들을 모두 뽑아낸 후,
배열의 크기 기준으로 오름차순 정렬하여
먼저 나온 숫자대로 answer에 추가
*/

#include <bits/stdc++.h>

using namespace std;

#include "unordered_map"

bool cmp(vector<int> a, vector<int> b)
{
    return a.size() < b.size();
}

vector<int> solution(string s) {
    vector<int> answer;

    int index = 1;
    vector<vector<int>> arr;
    char temp1;

    while (1)
    {
        index++; // {

        vector<int> sub_arr;

        while (1)
        {
            string temp_str;
            temp1 = s[index];

            while (temp1 != ',' && temp1 != '}')
            {
                temp_str += temp1;

                index++;
                temp1 = s[index];
            }
            sub_arr.push_back(stoi(temp_str));

            index++;

            if (temp1 == '}') break;
        }
        arr.push_back(sub_arr);

        if (s[index] == '}') break;
        index++;
    }

    sort(arr.begin(), arr.end(), cmp);

    unordered_map<int, int> hash_table;

    for (int i = 0; i < arr.size(); i++)
    {
        // 각 숫자 배열에 대해 검사
        for (int j = 0; j < arr[i].size(); j++)
        {
            int temp_int = arr[i][j];
            // 처음 나오는 숫자
            if (hash_table[temp_int] == 0) {
                hash_table[temp_int] = 1;
                answer.push_back(temp_int);
            }
        }
    }
    return answer;
}

int main()
{
    
    return 0;
}
