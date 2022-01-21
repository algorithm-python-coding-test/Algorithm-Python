// Solution -> Compression -> SubCompression 
// 압축길이 1부터 시작하여 압축된 문자열의 길이중 최소를 반환
// Compression 함수 : 주어진 문자열을 주어진 길이로 압축했을때 압축된 문자열의 길이 반환
// SubCompression 함수 : 
// 주어진 문자열을 주어진 위치에서 시작했을 때
// 주어진 길이의 문자열이 몇개가 연이어 반복되는지 반환

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <vector>

using namespace std;

int SubCompression(int a_compress_len, string a_s, int a_start_index);

// 주어진 압축길이 a_compress_len으로 주어진 문자열 a_s압축하기
int Compression(int a_compress_len, string a_s)
{
    // 압축된 문자열의 길이
    int compressed_size = 0;

    // 압축할 문자열에서의 위치 index 값
    int cur_index = 0;

    int count;

    // s를 벗어나지 않는 범위에서 압축
    while (cur_index < a_s.size())
    {
        // 문자열 a_s의 cur_index에서부터 a_compress_len단위로 잘랐을때
        // 중복되는 것의 개수
        count = SubCompression(a_compress_len, a_s, cur_index);

        // 중복되는 것이 2개이상이라면 
        // 압축된 문자열로 바꾼다
        if (count > 1)
        {
            // 중복된 문자열의 개수에 따라 1000개면 4칸, 100개면 3칸, 10개면 2칸, 그 미만이면 1칸만 필요하다
            int count_size = (count >= 1000) * 1 + (count >= 100) * 1 + (count >= 10) * 1 + 1;
            // 압축된 문자열의 크기를 더해준다 ( ex : 300s -> 3+1 )
            compressed_size += (count_size + a_compress_len);
            // cur_index는 그만큼 이동
            cur_index += (count * a_compress_len);
        }
        // count가 1이라는건 a_compress_len으로 자른 문자열이 하나라도 있다는 뜻
        // 1개라서 압축은 일어나지 않는다
        else if (count == 1)
        {
            compressed_size += a_compress_len;
            cur_index += a_compress_len;
        }
        // count == 0 이라는건 더이상 a_compress_len으로 자를만큼의 문자열이 남아있지 않으므로
        // 남은 문자열은 모두 압축된 문자열 뒤에 붙여주면 됨
        else 
        {
            compressed_size += (a_s.size() - cur_index);
            break;
        }
    }
    return compressed_size;
}

// 문자열 a_s의 a_start_index 부터 a_compress_len 길이만큼씩 잘라서
// 중복되는 문자열이 몇개인지 확인하는 함수
int SubCompression(int a_compress_len, string a_s, int a_start_index)
{
    // 문자열 a_s의 범위를 벗어나면 바로 0을 return
    if (a_start_index + a_compress_len > a_s.size()) return 0;
    
    string temp1;
    // 현재 위치 a_start_index로부터 a_compress_len길이의 문자열을 자름
    temp1 = a_s.substr(a_start_index, a_compress_len);
    // 다음을 확인하기 위해 위치는 그만큼 이동시킨다
    a_start_index += a_compress_len;

    // 중복된 문자열의 개수를 저장하는 변수
    // 위에서 a_compress_len으로 하나를 잘랐으므로 1로 초기화 한다.
    int compress_count = 1;

    // 이제 자른 문자열과 같은게 이후에 몇개나 있는지 확인한다
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
    
    // 자른 문자열의 개수를 return
    return compress_count;
}

int solution(string s) {

    int answer = 0;

    int s_len = s.size();
    // 문자열 s의 길이의 절반보다 큰 길이로 압축하는건 불가능하다
    int max_compress_len = s_len / 2;

    // Compression 함수를 통해 압축된 문자열의 길이를 저장하는 변수
    // 초기값은 전혀 압축되지 않은 전체 길이다
    int compressed_s_len = s_len;

    // 압축길이를 1부터 시작하여 압축한다
    for (int compress_len = 1; compress_len <= max_compress_len; compress_len++)
    {
        int len = Compression(compress_len, s);
        // compress_len으로 압축한 문자열의 길이 len이 더 작다면 len으로 갱신한다
        if (len < compressed_s_len) compressed_s_len = len;
    }

    answer = compressed_s_len;

    return answer;
}
