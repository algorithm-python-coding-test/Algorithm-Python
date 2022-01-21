/*
* Problem : ���ڿ� ����
* : �ݺ��Ǵ� ���ڿ��� �����Ͽ� ��Ÿ�� �� �ִ� ���ڿ��� �ּұ��� ���ϱ�
* ���ڿ� s�� ���̴� 1�̻� 1000���� -> ���� Ž���� ��쿡�� 10000�� �̸��� Ž��
*
* >>�ּ� 0.01ms, 3.68MB�� ����
* >>�ִ� 0.65ms, 4.28MB�� ����
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string s;

int main()
{
	cin >> s;
	//���ڿ��� �ִ� ������ s.length()�� ���ϰ��� �ϴ� �ּұ��� �ʱ�ȭ
	int min_len = s.length();
	//������ ���ڿ��� ���̴� 1���� s.length()/2 ����
	//s.length()/2�� �Ѿ�� �����ϴ� �ǹ̰� ������
	for (int i = 1; i <= s.length() / 2; i++) {
		//���� ���ڿ� ����
		string prev_str = s.substr(0, i);
		//���� ���ڿ��� ��� �ݺ��Ǵ��� ����
		int cnt = 1;
		//������� ����� ���ڿ��� ����
		int curr_len = 0;
		//���ڸ� i���� �ǳʶٸ� ���� ����
		for (int j = i; j <= s.length(); j += i) {
			//���� ������ġ j���� i��ŭ �ǳʶ� ��ġ�� ���ڿ��� ���̸� �Ѿ�ٸ�
			if (j + i > s.length())
			{
				//���ڿ��� �ѹ� �̻� ����Ǿ��ٸ�
				if (cnt > 1) {
					int n = 0;
					//����� Ƚ���� ���� �������� ���� ���
					//2~9�� : 1, 10~99�� : 2, 100~1000�� : 3
					while (cnt > 0) {
						n++;
						cnt /= 10;
					}
					//����� ���ڿ� ���� + ���� ���̸� ������
					curr_len += i + n;
				}
				//���ڿ��� ������� �ʾҴٸ� ����� ���ڿ� ���̸� ������
				else curr_len += i;
				break;
			}
			//���ڿ� ������ �����ϴٸ�
			else if (prev_str == s.substr(j, i)) {
				cnt++;
				continue;
			}
			//���ڿ� ������ �Ұ����ϴٸ�
			else {
				if (cnt > 1) {
					int n = 0;
					while (cnt > 0) {
						n++;
						cnt /= 10;
					}
					curr_len += i + n;
				}
				else curr_len += i;

				prev_str = s.substr(j, i);
				cnt = 1;
			}
		}
		//���ڿ� ���� �� ���� ���ڿ��� �״�� ������
		int remain = s.length() % i;
		curr_len += remain;
		//�ּ� ���� ����
		min_len = min(min_len, curr_len);
	}
	cout << min_len;
}