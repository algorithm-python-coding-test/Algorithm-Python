// Solution -> Compression -> SubCompression 
// ������� 1���� �����Ͽ� ����� ���ڿ��� ������ �ּҸ� ��ȯ
// Compression �Լ� : �־��� ���ڿ��� �־��� ���̷� ���������� ����� ���ڿ��� ���� ��ȯ
// SubCompression �Լ� : 
// �־��� ���ڿ��� �־��� ��ġ���� �������� ��
// �־��� ������ ���ڿ��� ��� ���̾� �ݺ��Ǵ��� ��ȯ

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <vector>

using namespace std;

int SubCompression(int a_compress_len, string a_s, int a_start_index);

// �־��� ������� a_compress_len���� �־��� ���ڿ� a_s�����ϱ�
int Compression(int a_compress_len, string a_s)
{
    // ����� ���ڿ��� ����
    int compressed_size = 0;

    // ������ ���ڿ������� ��ġ index ��
    int cur_index = 0;

    int count;

    // s�� ����� �ʴ� �������� ����
    while (cur_index < a_s.size())
    {
        // ���ڿ� a_s�� cur_index�������� a_compress_len������ �߶�����
        // �ߺ��Ǵ� ���� ����
        count = SubCompression(a_compress_len, a_s, cur_index);

        // �ߺ��Ǵ� ���� 2���̻��̶�� 
        // ����� ���ڿ��� �ٲ۴�
        if (count > 1)
        {
            // �ߺ��� ���ڿ��� ������ ���� 1000���� 4ĭ, 100���� 3ĭ, 10���� 2ĭ, �� �̸��̸� 1ĭ�� �ʿ��ϴ�
            int count_size = (count >= 1000) * 1 + (count >= 100) * 1 + (count >= 10) * 1 + 1;
            // ����� ���ڿ��� ũ�⸦ �����ش� ( ex : 300s -> 3+1 )
            compressed_size += (count_size + a_compress_len);
            // cur_index�� �׸�ŭ �̵�
            cur_index += (count * a_compress_len);
        }
        // count�� 1�̶�°� a_compress_len���� �ڸ� ���ڿ��� �ϳ��� �ִٴ� ��
        // 1���� ������ �Ͼ�� �ʴ´�
        else if (count == 1)
        {
            compressed_size += a_compress_len;
            cur_index += a_compress_len;
        }
        // count == 0 �̶�°� ���̻� a_compress_len���� �ڸ���ŭ�� ���ڿ��� �������� �����Ƿ�
        // ���� ���ڿ��� ��� ����� ���ڿ� �ڿ� �ٿ��ָ� ��
        else 
        {
            compressed_size += (a_s.size() - cur_index);
            break;
        }
    }
    return compressed_size;
}

// ���ڿ� a_s�� a_start_index ���� a_compress_len ���̸�ŭ�� �߶�
// �ߺ��Ǵ� ���ڿ��� ����� Ȯ���ϴ� �Լ�
int SubCompression(int a_compress_len, string a_s, int a_start_index)
{
    // ���ڿ� a_s�� ������ ����� �ٷ� 0�� return
    if (a_start_index + a_compress_len > a_s.size()) return 0;
    
    string temp1;
    // ���� ��ġ a_start_index�κ��� a_compress_len������ ���ڿ��� �ڸ�
    temp1 = a_s.substr(a_start_index, a_compress_len);
    // ������ Ȯ���ϱ� ���� ��ġ�� �׸�ŭ �̵���Ų��
    a_start_index += a_compress_len;

    // �ߺ��� ���ڿ��� ������ �����ϴ� ����
    // ������ a_compress_len���� �ϳ��� �߶����Ƿ� 1�� �ʱ�ȭ �Ѵ�.
    int compress_count = 1;

    // ���� �ڸ� ���ڿ��� ������ ���Ŀ� ��� �ִ��� Ȯ���Ѵ�
    while (a_start_index + a_compress_len <= a_s.size())
    {
        string temp2 = a_s.substr(a_start_index, a_compress_len);

        if (temp1.compare(temp2) == 0)
        {
            compress_count++;
            a_start_index += a_compress_len;
        }
        else break;
    }
    
    // �ڸ� ���ڿ��� ������ return
    return compress_count;
}

int solution(string s) {

    int answer = 0;

    int s_len = s.size();
    // ���ڿ� s�� ������ ���ݺ��� ū ���̷� �����ϴ°� �Ұ����ϴ�
    int max_compress_len = s_len / 2;

    // Compression �Լ��� ���� ����� ���ڿ��� ���̸� �����ϴ� ����
    // �ʱⰪ�� ���� ������� ���� ��ü ���̴�
    int compressed_s_len = s_len;

    // ������̸� 1���� �����Ͽ� �����Ѵ�
    for (int compress_len = 1; compress_len <= max_compress_len; compress_len++)
    {
        int len = Compression(compress_len, s);
        // compress_len���� ������ ���ڿ��� ���� len�� �� �۴ٸ� len���� �����Ѵ�
        if (len < compressed_s_len) compressed_s_len = len;
    }

    answer = compressed_s_len;

    return answer;
}
