//����ð� 0.01ms ~ 15.03ms

#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

//Ʃ���� ������ ������ ���� �迭
vector<int> set[501];
//set�迭�� ����Ǵ� ������ ���� ������ ����
int _size = 0;

vector<int> solution(string s) {
    vector<int> answer;
    //queue �ڷᱸ���� Ȱ���Ͽ� ���ڿ� s�� ó��
    queue<int> q;
    string temp = "";
    //���ڿ� s�� ��� ��ȸ�ϸ� ������ ã�Ƴ�
    //queue�� ���. FIFO�� Ȱ���Ͽ� ������ ������ ����
    for (int i = 1; i < s.length() - 1; i++) {
        if (s[i] == '{') continue;
        //��ǥ�� ���� ������ ��ǥ�� ó���ȴ�.
        else if (s[i] == ',') {
            int num = stoi(temp);
            q.push(num);
            temp = "";
        }
        //��ȣ�� �������� �ϳ��� ������ �ϼ��Ǵ� ���
        else if (s[i] == '}') {
            int num = stoi(temp);
            q.push(num);
            temp = "";
            int size = q.size();
            if (size > _size) _size = size;
            while (!q.empty()) {
                set[size].push_back(q.front());
                q.pop();
            }
            //��ȣ�� ������ �� ĭ�� �ǳʶپ� ��ȣ ������ ��ǥ�� ó��
            i++;
        }
        //���ڰ� ������ ���� temp�� ���ڸ� ������
        else {
            temp += s[i];
        }
    }
    answer.push_back(set[1].front());
    //���� ���հ��� �������� ���ذ��� Ʃ���� ����
    //i������ - i-1������ => Ʃ���� i��° ����
    vector<int> set_diff;
    for (int i = 2; i <= _size; i++) {
        sort(set[i].begin(), set[i].end());
        set_diff.resize(set[i].size());
        set_difference(set[i].begin(), set[i].end(), set[i - 1].begin(), set[i - 1].end(), set_diff.begin());
        answer.push_back(set_diff.front());
        set_diff.clear();
    }
    return answer;
}