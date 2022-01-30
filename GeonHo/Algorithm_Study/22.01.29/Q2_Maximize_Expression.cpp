
/*
* problem : Maximize Number
* ���ڵ�� 3������ ���깮�� (+, -, *)������ �̷���� ���� ������ �־��� ��
* �������� �켱������ �����Ӱ� �������Ͽ� ���� �� �ִ� ���밪�� ���� ū ���ڸ� ����
*
* �ּ� 0.01ms / 3.66MB�� ����
* �ִ� 0.04ms / 4.34MB�� ����
*/
#include <string>
#include <algorithm>
#include <list>

using namespace std;
//�����ڿ� ���� ������ �����ϴ� �Լ�
long long calculate(char op, long long num1, long long num2) {
    switch (op) {
    case '*':
        return num1 * num2;
    case '+':
        return num1 + num2;
    case '-':
        return num1 - num2;
    }
}

struct Node {
    long long data;
    char next_op;
};

long long solution(string expression) {
    long long answer = 0;
    //expression�� ���ڿ� �����ڸ� �и��Ͽ� num_list�� ���� ����
    //�� ���� ���ڿ� �ٷ� �ڿ� ���� �����ڷ� ����
    //ex) 100 + 200 - ... -> {100, +}, {200, -}...
    list<Node> num_list;
    string temp = "";
    for (int i = 0; i < expression.length(); i++) {
        //expression[i]�� �����ڰ� �ƴ϶�� temp�� ���ڸ� ����
        if (expression[i] != '-' && expression[i] != '+' && expression[i] != '*') {
            temp += expression[i];
            //expression[i]�� �����ڰ� �ƴ����� ���ڿ��� ���̶��
            //������� ������� ���ڿ� �����ڴ�� x�� ��带 �����Ͽ� ����
            if (i == expression.length() - 1)
                num_list.push_back({ stoll(temp), 'x' });
        }
        //expression[i]�� �����ڶ�� ������� ���ڿ� �����ڷ� ��带 �����Ͽ� ����
        else {
            num_list.push_back({ stoll(temp), expression[i] });
            temp = "";
        }
    }
    //permutation�� ����ϱ� ���� �����ڸ� ������������ ����
    string op_str = "*+-";
    //permutation�� ���� ������ �켱������ ����
    //�� �켱���� ������ ����� �����Ѵ�.
    do {
        //num_list�� �״�� ����ϸ� ���� ���꿡 ����� �� �����Ƿ� 
        //num_list�� ���� tempList�� �����Ͽ� ���
        list<Node> tempList;
        tempList.assign(num_list.begin(), num_list.end());
        //�켱������ ���� ��� ����
        //�� ������ ���� ����� next_op�� 'x'�� �� ������ �ݺ�
        //����� next_op�� ���� �����ڿ� ��ġ�Ѵٸ�
        //���� ���� ���� �� ���� ����� ���� ����� next_op�� ������ ���ο� ��� ����
        //���꿡 ���� ������ ����
        for (int i = 0; i < 3; i++) {
            list<Node>::iterator iter = tempList.begin();
            while (iter->next_op != 'x') {
                if (iter->next_op == op_str[i]) {
                    long long num1 = iter->data;
                    iter = tempList.erase(iter);
                    long long num2 = iter->data;
                    char newOp = iter->next_op;
                    iter = tempList.erase(iter);
                    long long newNum = calculate(op_str[i], num1, num2);
                    tempList.insert(iter, { newNum, newOp });
                    iter--;
                    continue;
                }
                iter++;
            }
        }
        //���� �� ���� ����� data�� ���� case�� ����� ��ȯ
        long long case_ret = tempList.begin()->data;
        //������� ���� answer�� ���� case�� ����� ���Ͽ� ū ���� answer�� ����
        answer = (abs(answer) > abs(case_ret)) ? abs(answer) : abs(case_ret);

    } while (next_permutation(op_str.begin(), op_str.end()));

    return answer;
}

int main() {
    int ret = solution("50*6-3*2");
    return 0;
}