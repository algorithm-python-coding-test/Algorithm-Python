/*
* Problem : N-Queens
* ü������ ����/���� ���� n�� �Ű������� �־��� ��
* n���� ���� ���� ���ݰ������� �ʵ��� ��ġ�ϴ� ����� �� (1<= n <= 12)
*
* �� �ٿ� �� �̻��� ���� ������ �� ����.
* BackTracking �˰����� ��ǥ�� ����!!
* 
* >>�ּ� 0.01ms, 3.67MB�� ����
* >>�ִ� 281.47ms, 4.27MB�� ����
*/
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void dfs(int i);

int n;
int column[13];	//i��° ���� column[i]��° ���� ���� ����
int ret = 0;

int main()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		column[1] = i;
		dfs(2);
	}

	cout << ret;
}

void dfs(int i)
{
	//������ Ž���� �ȴٸ� ret�� 1 ������Ű�� ����
	if (i > n)
	{
		ret++;
		return;
	}
	else
	{
		//i�� j�� �˻�
		for (int j = 1; j <= n; j++)
		{
			bool flag = true;
			//k�� column[k]���� ���ؼ�
			for (int k = 1; k <= i - 1; k++)
			{
				pair<int, int> prev_Post = { k, column[k] };	//���� ���� ��ġ
				if (j == column[k] || (abs(k - i) == abs(column[k] - j)))	//���� ���� ���� ���� �ְų� || �밢���� ��ġ�Ѵٸ�
				{
					flag = false;											//�÷��׺����� false��
					break;
				}
			}
			//���� ������ ���ݹ����� ��� ����ٸ�
			if (flag)
			{
				column[i] = j;					//i�� j���� ���� ��ġ
				dfs(i + 1);						//i+1������ �˻� ����
			}
		}
	}
}

//���α׷��ӽ� ����� �ڵ�
//#include <cmath>
//#include <vector>
//
//using namespace std;
//
//void dfs(int i, int n);
//int column[13];
//int ret = 0;
//
//int solution(int n) {
//	for (int i = 1; i <= n; i++)
//	{
//		column[1] = i;
//		dfs(2, n);
//	}
//	return ret;
//}
//
//void dfs(int i, int n)
//{
//	if (i > n)
//	{
//		ret++;
//		return;
//	}
//	else
//	{
//		for (int j = 1; j <= n; j++)
//		{
//			bool flag = true;
//			for (int k = 1; k <= i - 1; k++)
//			{
//				pair<int, int> prev_Post = { k, column[k] };
//				if (j == column[k] || (abs(k - i) == abs(column[k] - j)))
//					flag = false;
//			}
//			if (flag)
//			{
//				column[i] = j;
//				dfs(i + 1, n);
//			}
//		}
//	}
//}