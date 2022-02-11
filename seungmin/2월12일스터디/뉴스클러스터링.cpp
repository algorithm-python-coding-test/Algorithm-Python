/*
- �� ���ڿ��� �� ���ھ� �ڸ� ������ ������ max_heap�� ���� (priority_queye)
- �� max_heap�� top ��Ҹ� ���ϸ� �������� ã��, �������� �����
- max_heap�� ���ڿ��� ������������ �������ֹǷ� �� ������ �̿�
*/

/* �ҿ�ð�
�ּ� : 0.01ms , 4.32MB
�ִ� : 0.34ms , 4.32MB
*/

#include <bits/stdc++.h>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;

    //�ƽ�Ű�ڵ�� �ִ� 128��
    char alphabet_int_array[128] = { 0, };

    // ��ҹ��� ������ ���ֱ� ���� �迭�� �� ���� : 'a'-> 'a' ����, 'A' -> 'a' ����
    // ���ĺ��� �ƴ� �ƽ�Ű���ڴ� 0���� �������� ��
    for (char i = 'a'; i <= 'z'; i++) alphabet_int_array[i] = (i - 'a' + 'a');
    for (char i = 'A'; i <= 'Z'; i++) alphabet_int_array[i] = (i - 'A' + 'a');

    // str1, str2�� �� ���ھ� �߶� ������ max_heap
    priority_queue<string> pq1, pq2;

    for (int i = 0; i < str1.size(); i++)
    {
        char alphabet1 = str1[i];
        string two_alphabets;

        // ���ĺ��� ��쿡�� �ϱ� ���� if��
        // alphabe1�� ���ĺ��� �ƴ� �ƽ�Ű���ڸ� alphabet_int_array[alphabet1] ���� 0
        if (alphabet_int_array[alphabet1] != 0)
        {
            two_alphabets += alphabet_int_array[alphabet1];
            i++;

            char alphabet2 = str1[i];
            // ���ĺ��� ��쿡�� �ϱ� ���� if��
            if (alphabet_int_array[alphabet2] != 0)
            {
                // �� ���ĺ����� ������ ���ڿ� two_alphabet
                two_alphabets += alphabet_int_array[alphabet2];

                // max_heap�� ����
                pq1.push(two_alphabets);
            }
            // for���� i++�� ����ϱ� ����
            i--;
        }
    }

    // str2�� ���� ������ ���� ( pq2 )
    for (int i = 0; i < str2.size(); i++)
    {
        char alphabet1 = str2[i];
        string two_alphabet;

        if (alphabet_int_array[alphabet1])
        {
            two_alphabet += alphabet_int_array[alphabet1];
            i++;

            char alphabet2 = str2[i];
            if (alphabet_int_array[alphabet2])
            {
                two_alphabet += alphabet_int_array[alphabet2];
                pq2.push(two_alphabet);
            }
            i--;
        }
    }

    // �ϴ� pq1�� pq2�� ũ�⸦ ���� ��
    // �������� ������size( intersection_size )�� ���� ������ size�� ����
    int union_size = pq1.size() + pq2.size();

    int intersetction_size = 0;

    // pq1, pq2 �� �� �ϳ��� ������������� �� ��� ��
    // max_heap�̱� ������ ������������ ����� ���ĵǾ�����
    while (!pq1.empty() && !pq2.empty())
    {
        string sub_str1 = pq1.top();
        string sub_str2 = pq2.top();

        //str1, str2�� ���ٸ�
        if (sub_str1.compare(sub_str2) == 0)
        {
            intersetction_size++;

            pq1.pop();
            pq2.pop();
        }
        // �ٸ��ٸ�
        else
        {
            // pq1,pq2�� �������� �����̹Ƿ�, 
            // str1, str2 ���� �� ������ �ִ� ���ڿ���
            // ���̻� ���� ���ڿ��� ���� �� ����
            if (sub_str1 > sub_str2) pq1.pop();
            else pq2.pop();
        }
    }

    union_size -= intersetction_size;
    if (union_size != 0) answer = floor(((float)intersetction_size / (float)union_size) * 65536);
    else answer = 65536;

    return answer;
}

int main()
{
    string str1 = "z1";
    string str2 = "zz";

    int sol = solution(str1, str2);

    cout << sol << "\n";

    return 0;
}
