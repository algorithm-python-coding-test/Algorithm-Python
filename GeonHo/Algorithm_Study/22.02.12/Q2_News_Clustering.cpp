/*
* problem : ���� Ŭ�����͸� (https://programmers.co.kr/learn/courses/30/lessons/17677)
* ��ī�� ���絵 J(A, B) = (A^B)/(AuB)
* �Է����� ���� �� ���ڿ��� �� ���ھ� ���� ���������� ���ҷ� ��ȯ ��
* ��ī�� ���絵�� ���. ��ҹ����� ���̴� �����ϸ� �������� �� ���� �ָ� ��ȿ�ϰ� ����Ѵ�.
*
* �ּ� 0.01ms / 3.66MB�� ����
* �ִ� 1.62ms / 4.34MB�� ����
*/

//�� ���ڿ��� ���̰� �ִ� 1000�̹Ƿ� �ܼ��񱳷� ����� ��� ����
//make_set : ���ڿ��� �������� ����. �빮�ڴ� �ҹ��ڷ� ��ȯ�ϸ� ���ĺ� �̿��� ���ڰ� ���ԵǸ� ������.
//intersecion : �� ������ �������� ���ϴ� �Լ�
//->intersection�� �������� ���� �־��� ��� O(N^2)���� ����

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> make_set(string str) {
    vector<string> ret;
    for (int i = 0; i < str.size() - 1; i++) {
        string temp = "";
        //ù��° ���ڰ� �빮���̸� �ҹ��ڷ� ��ȯ, �ҹ��� �̿��� �����̸� ����x
        if (isupper(str[i]))
            temp += tolower(str[i]);
        else if (str[i] <= 122 && str[i] >= 97) {
            temp += str[i];
        }
        //�ι�° ���ڰ� �빮���̸� �ҹ��ڷ� ��ȯ, �ҹ��� �̿��� �����̸� ����x
        if (isupper(str[i + 1]))
            temp += tolower(str[i + 1]);
        else if (str[i + 1] <= 122 && str[i + 1] >= 97) {
            temp += str[i + 1];
        }
        //temp�� ���̰� 2�� ���� ������ ���տ� �������� ����
        if (temp.length() == 2) {
            ret.push_back(temp);
        }
    }
    return ret;
}

vector<string> intersection(vector<string> set1, vector<string> set2) {
    vector<string> ret;
    int len = 0;
    bool isCounted[1000] = { false };
    //�� ���� �� ũ�Ⱑ ���� ������ ���ҷ� ��
    //isCounted�迭�� ����Ͽ� ũ�Ⱑ ū �迭���� �񱳰� �Ǿ����� �˻�
    if (set1.size() > set2.size()) {
        for (int i = 0; i < set2.size(); i++) {
            for (int j = 0; j < set1.size(); j++) {
                if (set2[i] == set1[j] && !isCounted[j]) {
                    ret.push_back(set2[i]);
                    isCounted[j] = true;
                    break;
                }
            }
        }
    }
    else {
        for (int i = 0; i < set1.size(); i++) {
            for (int j = 0; j < set2.size(); j++) {
                if (set1[i] == set2[j] && !isCounted[j]) {
                    ret.push_back(set1[i]);
                    isCounted[j] = true;
                    break;
                }
            }
        }
    }
    return ret;
}

int solution(string str1, string str2) {
    vector<string> set1 = make_set(str1);
    vector<string> set2 = make_set(str2);

    vector<string> set_inter = intersection(set1, set2);

    int len_inter = set_inter.size();
    int len_union = set1.size() + set2.size() - len_inter;

    //�������� 0�̸� ���絵�� 1
    if (len_union == 0) return 65536;
    else return (65536 * len_inter) / len_union;
}

void main() {
    int ret = solution("FRANCE", "french");
    cout << ret;
}