//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
////�˰��� �Էµ� ���� ����
//string str;
//
//int main()
//{
//	cin >> str;
//
//	//��� ��ȯ�� ���� ���� ����
//	int result = str[0] - '0';
//
//	for (int i = 1; i < str.length(); i++)
//	{
//		//�迭�� ���ڰ� 0�̸� �ƹ� ������ ���� ����
//		if (str[i] == '0') continue;
//		else if (str[i] == '1') result += 1;
//		else 
//		{
//			//�迭�� ���ڰ� 0�� �ƴ϶�� result * str[i]
//			result *= str[i] - '0';
//		}
//	}
//	cout << result;
//}

/*
*	//���ϱ� Ȥ�� ���ϱ�//
* ���ϱ� ������ ���ϱ� ���꺸�� ū ���� ��ȯ�ϹǷ� �׸��� �˰��� ���
* 0�� ���ϴ� ��츦 �����ϰ� ��� ���� ���Ͽ� ��� ���
* �� �� str�� char�� �迭 �̹Ƿ� ������ ������ ���� ASCII code�� ���
* str[i] �� ASCII�� - '0' �� ASCII�� : �ش� ������ int��
*/