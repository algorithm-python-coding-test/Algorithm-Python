#include <bits/stdc++.h>

// ���ڿ� ����/����/��ȯ �ּ� Ƚ�� ���ϴ� �˰��� ����

using namespace std;

int main()
{
    int input_size, output_size;

    cin >> input_size >> output_size;

    string input, output;

    cin >> input >> output;

    // (input_size + 1) * (output_size + 1) ũ���� �迭�� ����
    vector<vector<int>> ctp_array(input_size + 1, vector<int>(output_size + 1, 0));

    // ù��° �� 0 ~ output_size ���� �ϳ��� �����ϸ� ä���
    for (int i = 0; i < output_size + 1; i++) ctp_array[0][i] = i;
    // ù��° �� 0 ~ input_size ���� �ϳ��� �����ϸ� ä���
    for (int i = 0; i < input_size + 1; i++) ctp_array[i][0] = i;

    // ���� �������� (1,1)���� �ϳ��� ä���
    for (int i = 0; i < input_size; i++)
    {
        char input_char = input[i];
        for (int j = 0; j < output_size; j++)
        {
            char output_char = output[j];

            // ���ϴ� �� ���ڰ� ���ٸ�, �밢�� ���� ���� ĭ�� �ִ� ���� �״�� �����´�
            // �̴� ����ĭ���� ���ڰ� �߰��Ǵ��� ���� �����̱� ������ ����/����/��ȯ�� �Ͼ�� �ʱ� �����̴�.
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
            // �� ���ڰ� �ٸ��ٸ� ����/����/��ȯ �� ���� ���� Ƚ���� ��츦 �����´�
            // ����/����/��ȯ �� �ϳ��� �߻��ϹǷ� +1�� ���� ����
            else
            {
                int min_num = min(min(ctp_array[i][j], ctp_array[i][j + 1]), ctp_array[i + 1][j]);
                ctp_array[i + 1][j + 1] = min_num + 1;
            }
        }
    }

    // ���� ������ ���� ���� ��ȯ �� �ּ� Ƚ���̴�
    cout << ctp_array[input_size][output_size];

    return 0;
}
