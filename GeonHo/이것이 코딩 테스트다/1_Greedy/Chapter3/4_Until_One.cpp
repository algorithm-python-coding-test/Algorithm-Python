//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
////�Էµ� ������ ����
//int n, k;
//
//int main()
//{
//	//n�� k�� ������ �������� �Է¹���
//	cin >> n >> k;
//	int cnt = 0;
//
//	//n�� 1�� �� ������
//	while (n > 1)
//	{
//		//n�� k�� ���� �� �ִٸ�
//		if (n % k == 0)
//		{
//			n /= k;
//			cnt++;
//		}
//		//n�� k�� ���� �� ���ٸ�
//		else
//		{
//			n--;
//			cnt++;
//		}
//	}
//
//	cout << "the result is : " << cnt;
//}

/*
*	//1�� �� ������//
* ������ ������ -1 ���꺸�� ���ڸ� �۰��ϹǷ� �׸��� �˰��� ���
* N�� K�� ���� �� �ִٸ� ������ ������ �� �� count++
* N�� K�� ���� �� ���ٸ� N-- �� count++
*/