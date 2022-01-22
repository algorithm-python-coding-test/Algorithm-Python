/*
* Problem : �ùٸ� ��ȣ (https://programmers.co.kr/learn/courses/30/lessons/12909)
*'(' �Ǵ� ')' �θ� �̷���� ���ڿ� s�� �־����� ��,
*���ڿ� s�� �ùٸ� ��ȣ�̸� true�� return �ϰ�, 
*�ùٸ��� ���� ��ȣ�̸� false�� return
* �ùٸ� ��ȣ : (�� ������ )�� ������ ��ȣ
* 
* stack�� �̿��ϰų� cnt�� �̿��ϰų�...
*/

#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    //stack��� cnt�� �̿��ؼ� ���̴� ��ȣ ǥ��
    int cnt = 0;
    //���ڿ��� ó������ ������ ��ȸ
    for (int index = 0; index < s.length(); index++)
    {
        //���� '(' ��� ���ÿ� push�ϴ� �� ó�� cnt++
        if (s[index] == '(') cnt++;
        else
        {
            //cnt�� 0�ε� ')'�� �´ٸ� �ùٸ��� ���� ��ȣ
            if (cnt == 0) return false;
            //')'�� �Դٸ� ������ pop�ϴ� �� ó�� cnt--
            cnt--;
        }
    }
    //���� ��ȣ�� ���ٸ� true, ���� ��ȣ�� �ִٸ� false
    return cnt == 0;
}