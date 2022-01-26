
#include <bits/stdc++.h>

using namespace std;


long long solution(string expression) {

    long long answer = 0;

    // 아스키코드 순서대로 피연산자 배열 : next_permutation을 쓰기 위함
    vector<char> basic_operators = { '*','+','-' };

    // expression에서 피연산자 모음
    vector<long long> operands;
    // expression에서 연산자 모음
    vector<char> operators;

    string number = "";

    for (int i = 0; i < expression.size(); i++)
    {
        if (expression[i] == '*' || expression[i] == '+' || expression[i] == '-')
        {
            operators.push_back(expression[i]);
            operands.push_back(stoll(number));

            number = "";
        }
        else number += expression[i];
    }
    operands.push_back(stoll(number));

    long long max_number = 0;

    // * + - 의 6가지 조합에 따라 연산
    do {
        vector<long long> temp_operands = operands;
        vector<char> temp_operators = operators;

        for (int i = 0; i < basic_operators.size(); i++)
        {
            // 연산자를 하나씩 돌며
            for (int j = 0; j < temp_operators.size(); j++)
            {
                // 우선순위의 연산자가 나오면 
                if (basic_operators[i] == temp_operators[j])
                {
                    long long number;
                    // 연산자 앞, 뒤에 있는 피연산자 연산
                    if (basic_operators[i] == '*')
                    {
                        number = temp_operands[j] * temp_operands[j + 1];
                    }
                    else if (basic_operators[i] == '+')
                    {
                        number = temp_operands[j] + temp_operands[j + 1];
                    }
                    else
                    {
                        number = temp_operands[j] - temp_operands[j + 1];
                    }

                    // 계산된 피연산자 2개는 사라졌으므로 지우기
                    temp_operands.erase(temp_operands.begin() + j, temp_operands.begin() + j + 2);
                    // 새로 계산된 피연산자를 그자리에 삽입
                    temp_operands.insert(temp_operands.begin() + j, number);

                    // 피연산자 또한 사용했으므로 지우기
                    temp_operators.erase(temp_operators.begin() + j);
                    // 피연산자 하나를 삭제했으므로, 위치 index값 j를 하나 감소시키고 진행해야 한다
                    j--;
                }
            }
        }
        temp_operands[0] = abs(temp_operands[0]);
        if (temp_operands[0] > max_number) max_number = temp_operands[0];

    } while (next_permutation(basic_operators.begin(), basic_operators.end()));

    answer = max_number;

    return answer;
}
