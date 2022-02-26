// 18분 소요
#include <string>
#include <vector>

using namespace std;

// 0~9 까지 숫자문자열의 길이를 저장한 배열
int alpha_len[] = { 4,3,3,5,4,4,3,5,5,4 };

int solution(string s) {
    int answer = 0;

    int index = 0;

    while (index != s.size()) {

        char curr = s[index];

        // 숫자만 먼저 저장
        if (curr >= '0' && curr <= '9') {
            answer = answer * 10 + (curr - '0');
            index++;
        }
        else {
            int s_to_i;

            switch (curr) {
            case 'z': //zero
                s_to_i = 0;
                break;
            case 'o': //one
                s_to_i = 1;
                break;
            case 't': //two, three
                s_to_i = 23;
                break;
            case 'f': //four, five
                s_to_i = 45;
                break;
            case 's': //six, seven
                s_to_i = 67;
                break;
            case 'e': //eight
                s_to_i = 8;
                break;
            case 'n': //nine
                s_to_i = 9;
                break;
            }
            // two, three 구분
            if (s_to_i == 23) {
                if (s[index + 1] == 'w')
                    s_to_i = 2;
                else
                    s_to_i = 3;
            }
            // four, five 구분
            if (s_to_i == 45) {
                if (s[index + 1] == 'o')
                    s_to_i = 4;
                else
                    s_to_i = 5;
            }
            // six, seven 굽누
            if (s_to_i == 67) {
                if (s[index + 1] == 'i')
                    s_to_i = 6;
                else
                    s_to_i = 7;
            }
            answer = answer * 10 + s_to_i;
            index = (index + alpha_len[s_to_i]);
        }
    }

    return answer;
}