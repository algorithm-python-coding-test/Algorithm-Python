//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
////�Էµ� ������ ����
//int N;
//vector<int> adv;
//
//int main()
//{
//	cin >> N;
//	for (int i = 0; i < N; i++)
//	{
//		int x;
//		cin >> x;
//		adv.push_back(x);
//	}
//	//vector�� ���� (adv.begin()) ~ ��(adv.end())���� ���Ҹ� �������� ����
//	sort(adv.begin(), adv.end());
//
//	int num = 0, groupCnt = 0;
//
//	//��� ���谡�� ���Ͽ�
//	for (int i = 0; i < N; i++)
//	{
//		//�׷쿡 ���谡 1�� �߰�
//		num++;
//		//�׷쿡 �ִ� ���谡�� ���ڰ� ���� ���谡�� ���������� ���ų� ������
//		if (num >= adv[i])
//		{
//			//�׷� ����
//			groupCnt++;
//			//���ο� �׷� ������ ���� �ʱ�ȭ
//			num = 0;
//		}
//	}
//	cout << groupCnt;
//}

/*
*	//���谡 ���//
* �������� ���� ���� ������� �׷��� �����ϴ� �׸��� �˰��� ���
* �������� �迭�� �Է¹��� �� sort�Լ��� ����Ͽ� �������� ������������ ����
* �� �� �������� ���� �������� �׷��� �����Ͽ� �׷��� �����Ǹ� groupCount++
*/