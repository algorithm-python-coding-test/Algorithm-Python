/*
- 두 문자열을 두 글자씩 자른 단위를 각각의 max_heap에 저장 (priority_queye)
- 두 max_heap의 top 요소를 비교하며 교집합을 찾고, 합집합을 계산함
- max_heap은 문자열을 내림차순으로 정렬해주므로 그 성질을 이용
*/

/* 소요시간
최소 : 0.01ms , 4.32MB
최대 : 0.34ms , 4.32MB
*/

#include <bits/stdc++.h>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;

    //아스키코드는 최대 128자
    char alphabet_int_array[128] = { 0, };

    // 대소문자 구분을 없애기 위해 배열에 값 대입 : 'a'-> 'a' 저장, 'A' -> 'a' 저장
    // 알파벳이 아닌 아스키문자는 0값을 가지도록 함
    for (char i = 'a'; i <= 'z'; i++) alphabet_int_array[i] = (i - 'a' + 'a');
    for (char i = 'A'; i <= 'Z'; i++) alphabet_int_array[i] = (i - 'A' + 'a');

    // str1, str2를 두 글자씩 잘라서 저장할 max_heap
    priority_queue<string> pq1, pq2;

    for (int i = 0; i < str1.size(); i++)
    {
        char alphabet1 = str1[i];
        string two_alphabets;

        // 알파벳인 경우에만 하기 위한 if문
        // alphabe1이 알파벳이 아닌 아스키문자면 alphabet_int_array[alphabet1] 값은 0
        if (alphabet_int_array[alphabet1] != 0)
        {
            two_alphabets += alphabet_int_array[alphabet1];
            i++;

            char alphabet2 = str1[i];
            // 알파벳인 경우에만 하기 위한 if문
            if (alphabet_int_array[alphabet2] != 0)
            {
                // 두 알파벳으로 구성된 문자열 two_alphabet
                two_alphabets += alphabet_int_array[alphabet2];

                // max_heap에 삽입
                pq1.push(two_alphabets);
            }
            // for문의 i++을 상쇄하기 위함
            i--;
        }
    }

    // str2도 같은 과정을 수행 ( pq2 )
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

    // 일단 pq1과 pq2의 크기를 더한 후
    // 마지막에 교집합size( intersection_size )를 빼야 합집합 size가 나옴
    int union_size = pq1.size() + pq2.size();

    int intersetction_size = 0;

    // pq1, pq2 둘 중 하나가 비어있을때까지 각 멤버 비교
    // max_heap이기 때문에 내림차순으로 멤버가 정렬되어있음
    while (!pq1.empty() && !pq2.empty())
    {
        string sub_str1 = pq1.top();
        string sub_str2 = pq2.top();

        //str1, str2가 같다면
        if (sub_str1.compare(sub_str2) == 0)
        {
            intersetction_size++;

            pq1.pop();
            pq2.pop();
        }
        // 다르다면
        else
        {
            // pq1,pq2가 내림차순 정렬이므로, 
            // str1, str2 둘중 더 우위에 있는 문자열은
            // 더이상 같은 문자열이 있을 수 없다
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
