//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include "test.h"
//
//using namespace std;
//
////�˰��� �Էµ� int�� ���� ����
//int N, M, K;
////�˰��� �Էµ� �迭 ����
//vector<int> v;
//
//int main()
//{
//	//N, M, K�� ������ �������� �����Ͽ� �Է� �ޱ�
//	cin >> N >> M >> K;
//
//	//N���� ���� ������ �������� �����Ͽ� �Է� �ޱ�
//	for (int i = 0; i < N; i++)
//	{
//		int x;
//		cin >> x;
//		v.push_back(x);
//	}
//
//	//sort�Լ��� ����Ϸ��� algorithm��� �ʿ�
//	//vector�� ���� (v.begin()) ~ ��(v.end())���� ���Ҹ� �������� ����
//	sort(v.begin(), v.end());
//	//���ĵ� vector���� ���� ū ��
//	int first = v[N - 1];
//	//���ĵ� vector���� �� ��°�� ū ��
//	int second = v[N - 2];
//
//	//first�� K��, second�� 1�� �������� ���� M / (K+1)�� �ݺ���
//	int cnt = M / (K+1);
//	//���� �� �ִ� ���� ū ���� second�� cnt��, first�� M - cnt�� �������� ��� �̹Ƿ�
//	int result = second * cnt + first * (M - cnt);
//	cout << "The result is : " << result << endl;
//
//}

/*
*	//ū ���� ��Ģ//
* ���� ū ���� �����ؼ� ���ϴ� ���� �ٸ� ������ ���ϴ� �ͺ��� ū ��� �̹Ƿ� �׸��� �˰��� ���
* N���� ���� �Է¹��� ��, �Է¹��� �迭�� �����Ͽ� ���� ū ���� �� ���� ū ���� ã��
* ���� ū ���� K�� ���� �� �� ���� ū ���� 1�� ���ϴ� ������� ��� ���
*/