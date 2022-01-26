
#include <bits/stdc++.h>

using namespace std;


long long solution(string expression) {

    long long answer = 0;

    // �ƽ�Ű�ڵ� ������� �ǿ����� �迭 : next_permutation�� ���� ����
    vector<char> basic_operators = { '*','+','-' };

    // expression���� �ǿ����� ����
    vector<long long> operands;
    // expression���� ������ ����
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

    // * + - �� 6���� ���տ� ���� ����
    do {
        vector<long long> temp_operands = operands;
        vector<char> temp_operators = operators;

        for (int i = 0; i < basic_operators.size(); i++)
        {
            // �����ڸ� �ϳ��� ����
            for (int j = 0; j < temp_operators.size(); j++)
            {
                // �켱������ �����ڰ� ������ 
                if (basic_operators[i] == temp_operators[j])
                {
                    long long number;
                    // ������ ��, �ڿ� �ִ� �ǿ����� ����
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

                    // ���� �ǿ����� 2���� ��������Ƿ� �����
                    temp_operands.erase(temp_operands.begin() + j, temp_operands.begin() + j + 2);
                    // ���� ���� �ǿ����ڸ� ���ڸ��� ����
                    temp_operands.insert(temp_operands.begin() + j, number);

                    // �ǿ����� ���� ��������Ƿ� �����
                    temp_operators.erase(temp_operators.begin() + j);
                    // �ǿ����� �ϳ��� ���������Ƿ�, ��ġ index�� j�� �ϳ� ���ҽ�Ű�� �����ؾ� �Ѵ�
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
