//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
////�Էµ� ���� ����
//int n, m;
//
//int main()
//{
//	//��� ��ȯ�� ���� ���� ����
//	int result;
//	//n �� m�� ������ �������� �����Ͽ� �Է¹���
//	cin >> n >> m;
//
//	//0 ~ n-1��° �����
//	for (int i = 0; i < n; i++)
//	{
//		//�Էµ� �ִ��� 10000�̹Ƿ� min_value�� 10000���� ����
//		int min_value = 10001;
//		for (int j = 0; j < m; j++)
//		{
//			int x;
//			cin >> x;
//			//������� min_value�� ���� �Էµ� x�� ���Ͽ� ���� ���� min_value�� ����
//			min_value = min(min_value, x);
//		}
//
//		//�ش� �࿡�� ã���� min_value�� result�� ���Ͽ� ū ���� result�� ����
//		result = max(min_value, result);
//	}
//
//	cout << result;
//}

/*
*	//���� ī�� ����//
* �� �࿡�� ���� ���� ���� �̿��Ͽ� ���ϴ� ����̹Ƿ� �׸��� �˰��� ���
* �� �࿡�� �Է¹��� �� ���� ���� ���� ����ϰ�, ������� �Էµ� ���� ���� ���� ���Ͽ� ���
*/