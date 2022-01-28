#include <string>
#include <algorithm>

using namespace std;

int solution(string name)
{
    int answer = 0;
    int shift = name.length() - 1; //Ŀ���� �� �Ǵ� �� �� �� ���⸸���� �̵����� ��
    for (int i = 0; i < name.length(); i++)
    {
        if (name[i] == 'A')
        {
            int target = i;
            while (target < name.length() && name[target] == 'A')
                target += 1; //A�θ� �̷���� ���ڿ� ã��
            int left = i == 0 ? 0 : i - 1; //ã�� ���ڿ� ���ʿ����� �̵�Ƚ��
            int right = name.length() - target;  //ã�� ���ڿ� �����ʿ����� �̵�Ƚ��
            shift = min(shift, left + right + min(left, right)); //���� ������ ã��
        }
    }
    answer += shift;
    for (auto c : name)
        answer += min(c - 'A', 'Z' - c + 1); //���� �̵�Ƚ��
    return answer;
}