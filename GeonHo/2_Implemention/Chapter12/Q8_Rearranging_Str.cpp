#include <iostream>
#include <algorithm>

using namespace std;

string str;

int main()
{
	cin >> str;

	sort(str.begin(), str.end());

	//���ڰ� ó�� ������ ��ġ�� ������ ����
	int pos = 0;
	//���ڵ��� ���� ������ ����
	int sum = 0;

	for (; pos < str.size(); pos++)
	{
		//���ڰ� ������ �����ϸ� �ݺ��� Ż��
		if ((int)str[pos] > 58) break;

		//���ڰ� ������ ������ ���� �� ���
		sum += (int)str[pos] - '0';
	}
	//sum + ���ڹ��ڸ� ������ ���ڿ� ��� erase : 0~pos������ ���� ����
	cout << sum << str.erase(0, pos);
}

/*
* ���ڿ� ���ڰ� �������� ���, ���� �� ���ڰ� ���ں��� ������ ���ĵ�
*/

/*
string str;
vector<char> result;
int value = 0

int main(void)
{
	cin >> str;

	for(int i = 0; i < str.size(); i++)
	{
		if(isalpha(str[i]))
		{
			result.push_back(str[i]);
		}
		else value += str[i] - '0';
	}

	sort(result.begin(), result.end());

	for (int i = 0; i < result.size(); i++) cout << result[i];
	
	cout << value;
}

*/