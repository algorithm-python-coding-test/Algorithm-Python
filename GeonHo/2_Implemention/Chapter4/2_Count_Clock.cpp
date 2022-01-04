#include <iostream>
#include <algorithm>
#include <string>

#define MUL_HOUR_CASE 3600		//�ÿ� 3�� ��� �ִ� ��� : 60 * 60 = 3600
#define MUL_MIN_CASE  900		//�п� 3�� ��� �ִ� ��� : 15 * 60 = 900
#define MUL_SEC_CASE  675		//�ʿ� 3�� ��� �ִ� ��� : 45 * 15 = 675

using namespace std;

int N;

int main()
{
	cin >> N;

	int ret = 0;

	//�ÿ� 3�� ����ִ� ����� �� 0
	if (N < 3)
	{
		ret = (N + 1) * (MUL_MIN_CASE + MUL_SEC_CASE);
	}
	//�ÿ� 3�� ����ִ� ����� �� 1 (3)
	else if (N < 13)
	{
		ret = N * (MUL_MIN_CASE + MUL_SEC_CASE) + MUL_HOUR_CASE;
	}
	//�ÿ� 3�� ����ִ� ����� �� 2 (3, 13)
	else if (N < 23)
	{
		ret = (N - 1) * (MUL_MIN_CASE + MUL_SEC_CASE) + MUL_HOUR_CASE * 2;
	}
	//�ÿ� 3�� ����ִ� ����� �� 3 (3, 13, 23)
	else
	{
		ret = (N - 2) * (MUL_MIN_CASE + MUL_SEC_CASE) + MUL_HOUR_CASE * 3;
	}
	cout << ret;
}

//if 3, 13, 23h : 3600
//else if xh 3 13 23 30~39 43 53m : 60
//else xh xm : 3 13 23 30~39 43 53s