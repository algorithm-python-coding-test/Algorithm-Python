/*
�ִ� : 10.27ms, 5.98MB
�ּ� : 0.01ms, 4.18MB
*/

/* 
�� �迭���� ���ڵ��� ��� �̾Ƴ� ��,
�迭�� ũ�� �������� �������� �����Ͽ�
���� ���� ���ڴ�� answer�� �߰�
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
        // �� ���� �迭�� ���� �˻�
        for (int j = 0; j < arr[i].size(); j++)
        {
            int temp_int = arr[i][j];
            // ó�� ������ ����
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
