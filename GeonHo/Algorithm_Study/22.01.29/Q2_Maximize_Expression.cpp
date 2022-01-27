
/*
* problem : Maximize Number
* 숫자들과 3가지의 연산문자 (+, -, *)만으로 이루어진 연산 수식이 주어질 때
* 연산자의 우선순위를 자유롭게 재정의하여 만들 수 있는 절대값이 가장 큰 숫자를 도출
*
* 최소 0.01ms / 3.66MB의 성능
* 최대 0.04ms / 4.34MB의 성능
*/
#include <string>
#include <algorithm>
#include <list>

using namespace std;
//연산자에 따라 연산을 진행하는 함수
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
    //expression의 숫자와 연산자를 분리하여 num_list에 노드로 삽입
    //각 노드는 숫자와 바로 뒤에 오는 연산자로 구성
    //ex) 100 + 200 - ... -> {100, +}, {200, -}...
    list<Node> num_list;
    string temp = "";
    for (int i = 0; i < expression.length(); i++) {
        //expression[i]가 연산자가 아니라면 temp로 숫자를 구성
        if (expression[i] != '-' && expression[i] != '+' && expression[i] != '*') {
            temp += expression[i];
            //expression[i]가 연산자가 아니지만 문자열의 끝이라면
            //현재까지 만들어진 숫자와 연산자대신 x로 노드를 구성하여 삽입
            if (i == expression.length() - 1)
                num_list.push_back({ stoll(temp), 'x' });
        }
        //expression[i]가 연산자라면 만들어진 숫자와 연산자로 노드를 구성하여 삽입
        else {
            num_list.push_back({ stoll(temp), expression[i] });
            temp = "";
        }
    }
    //permutation을 사용하기 위해 연산자를 오름차순으로 구성
    string op_str = "*+-";
    //permutation에 따라 연산자 우선순위가 결정
    //각 우선순위별로 계산을 진행한다.
    //첫번째 while : 1순위 연산자만 연산, 두번째 while : 2순위 연산자만 연산...
    do {
        //num_list을 그대로 사용하면 다음 연산에 사용할 수 없으므로 
        //num_list의 값을 tempList에 복사하여 사용
        list<Node> tempList;
        tempList.assign(num_list.begin(), num_list.end());
        //1순위 연산자 연산 시작
        list<Node>::iterator iter = tempList.begin();
        while (iter->next_op != 'x') {
            if (iter->next_op == op_str[0]) {
                long long num1 = iter->data;
                iter = tempList.erase(iter);
                long long num2 = iter->data;
                char newOp = iter->next_op;
                iter = tempList.erase(iter);
                long long newNum = calculate(op_str[0], num1, num2);
                tempList.insert(iter, { newNum, newOp });
                iter--;
                continue;
            }
            iter++;
        }
        //2순위 연산자 연산 시작
        iter = tempList.begin();
        while (iter->next_op != 'x') {
            if (iter->next_op == op_str[1]) {
                long long num1 = iter->data;
                iter = tempList.erase(iter);
                long long num2 = iter->data;
                char newOp = iter->next_op;
                iter = tempList.erase(iter);
                long long newNum = calculate(op_str[1], num1, num2);
                tempList.insert(iter, { newNum, newOp });
                iter--;
                continue;
            }
            iter++;
        }
        //3순위 연산자 연산 시작
        iter = tempList.begin();
        while (iter->next_op != 'x') {
            if (iter->next_op == op_str[2]) {
                long long num1 = iter->data;
                iter = tempList.erase(iter);
                long long num2 = iter->data;
                char newOp = iter->next_op;
                iter = tempList.erase(iter);
                long long newNum = calculate(op_str[2], num1, num2);
                tempList.insert(iter, { newNum, newOp });
                iter--;
                continue;
            }
            iter++;
        }
        //연산 후 남은 노드의 data를 현재 case의 결과로 반환
        long long case_ret = tempList.begin()->data;
        //현재까지 계산된 answer와 현재 case의 결과를 비교하여 큰 값을 answer에 저장
        answer = (abs(answer) > abs(case_ret)) ? abs(answer) : abs(case_ret);

    } while (next_permutation(op_str.begin(), op_str.end()));

    return answer;
}

int main() {
    int ret = solution("50*6-3*2");
    return 0;
}