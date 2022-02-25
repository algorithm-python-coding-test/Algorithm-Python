/*
* problem : ǥ ���� (https://programmers.co.kr/learn/courses/30/lessons/81303)
*/

//�߰��� ����-���� ������ ���̻���� -> list ����ϴ� �����ΰ�?
//cmd�� ��-�Ʒ� ���� ��� �̵��� �����ϴ� -> double linked list�� �������
//�������� ���� ���� �ֱ� ������ ��带 ���ƿ� �� �ְ� �ؾ��Ѵ� -> stack�ڷᱸ���� ����Ͽ� ���� �ֱ� ������ ��带 �ҷ�����
//linkedlist�� ����ϴ� edge case�� �����ؼ� ��������

//Solving Time : 40min

#include <string>
#include <vector>
#include <stack>
#include <cstring>

using namespace std;

//STL�� list�� ������� �ʰ� ���� ����
//memory pooling ���
struct Node {
    int number;
    Node* next = nullptr;
    Node* prev = nullptr;
    bool isRemoved = false;
}list[1000000];
//Ŀ���� ��ġ�� ��Ÿ�� ptr
Node* ptr = nullptr;
//memory pool�� ũ�⸦ ��Ÿ�� listSize
int listSize = 0;

string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    //������ ������ ���� stack. (removed Node)
    stack<Node*> rmNode;
    //�Է¿����� ��� ��带 �ʱ�ȭ
    listSize = n;
    for (int i = 0; i < listSize; i++) {
        if (i == 0) {
            list[0].next = &list[1];
            list[0].number = 0;
            continue;
        }
        if (i == listSize - 1) {
            list[listSize - 1].prev = &list[listSize - 2];
            list[listSize - 1].number = listSize - 1;
            continue;
        }

        list[i].next = &list[i + 1];
        list[i].prev = &list[i - 1];
        list[i].number = i;
    }

    ptr = &list[k];

    //cmd �� ��ȸ�ϸ� ��� ��ɾ ����
    for (int i = 0; i < cmd.size(); i++) {
        //Up ��ɾ�
        if (cmd[i][0] == 'U') {
            int cnt = stoi(cmd[i].substr(2));
            int iter = 0;
            while (iter < cnt) {
                ptr = ptr->prev;
                iter++;
            }
            continue;
        }
        //Down ��ɾ�
        if (cmd[i][0] == 'D') {
            int cnt = stoi(cmd[i].substr(2));
            int iter = 0;
            while (iter < cnt) {
                ptr = ptr->next;
                iter++;
            }
            continue;
        }
        //Remove ��ɾ�
        if (cmd[i][0] == 'C') {
            ptr->isRemoved = true;
            rmNode.push(ptr);
            if (ptr->next == nullptr) {
                ptr = ptr->prev;
                ptr->next = nullptr;
            }
            else if (ptr->prev == nullptr) {
                ptr = ptr->next;
                ptr->prev = nullptr;
            }
            else {
                ptr->prev->next = ptr->next;
                ptr->next->prev = ptr->prev;
                ptr = ptr->next;
            }
            continue;
        }
        //Restore ��ɾ�
        if (cmd[i][0] == 'Z') {
            if (rmNode.top()->next == nullptr) {
                rmNode.top()->prev->next = rmNode.top();
            }
            else if (rmNode.top()->prev == nullptr) {
                rmNode.top()->next->prev = rmNode.top();
            }
            else {
                rmNode.top()->next->prev = rmNode.top();
                rmNode.top()->prev->next = rmNode.top();
            }
            rmNode.top()->isRemoved = false;
            rmNode.pop();
            continue;
        }
    }

    //��� ����� ���� �� ���� ���ο� ���� O, X�� ����
    for (int i = 0; i < n; i++) {
        if (list[i].isRemoved) {
            answer += "X";
        }
        else {
            answer += "O";
        }
    }
    return answer;
}