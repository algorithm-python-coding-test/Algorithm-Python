#include <bits/stdc++.h>

// 문자열 삽입/삭제/변환 최소 횟수 구하는 알고리즘 적용

using namespace std;

int main()
{
    int input_size, output_size;

    cin >> input_size >> output_size;

    string input, output;

    cin >> input >> output;

    // (input_size + 1) * (output_size + 1) 크기의 배열을 선언
    vector<vector<int>> ctp_array(input_size + 1, vector<int>(output_size + 1, 0));

    // 첫번째 행 0 ~ output_size 까지 하나씩 증가하며 채우기
    for (int i = 0; i < output_size + 1; i++) ctp_array[0][i] = i;
    // 첫번째 열 0 ~ input_size 까지 하나씩 증가하며 채우기
    for (int i = 0; i < input_size + 1; i++) ctp_array[i][0] = i;

    // 행을 기준으로 (1,1)부터 하나씩 채우기
    for (int i = 0; i < input_size; i++)
    {
        char input_char = input[i];
        for (int j = 0; j < output_size; j++)
        {
            char output_char = output[j];

            // 비교하는 두 문자가 같다면, 대각선 기준 이전 칸에 있는 값을 그대로 가져온다
            // 이는 이전칸에서 문자가 추가되더라도 같은 문자이기 때문에 삽입/삭제/변환은 일어나지 않기 때문이다.
            if (input_char == output_char)
            {
                ctp_array[i + 1][j + 1] = ctp_array[i][j];
            }
            // i / j,l
            else if (input_char == 'i' && (output_char == 'j' || output_char == 'l'))
            {
                ctp_array[i + 1][j + 1] = ctp_array[i][j];
            }
            // v / w
            else if (input_char == 'v' && output_char == 'w')
            {
                ctp_array[i + 1][j + 1] = ctp_array[i][j];
            }
            // 두 문자가 다르다면 삽입/삭제/변환 중 가장 적은 횟수의 경우를 가져온다
            // 삽입/삭제/변환 중 하나가 발생하므로 +1된 값이 들어간다
            else
            {
                int min_num = min(min(ctp_array[i][j], ctp_array[i][j + 1]), ctp_array[i + 1][j]);
                ctp_array[i + 1][j + 1] = min_num + 1;
            }
        }
    }

    // 가장 마지막 값이 최종 변환 시 최소 횟수이다
    cout << ctp_array[input_size][output_size];

    return 0;
}
