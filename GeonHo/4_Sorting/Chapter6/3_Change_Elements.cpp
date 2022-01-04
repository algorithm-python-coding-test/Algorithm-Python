#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

int N, K;
vector<int> arr_A;
vector<int> arr_B;

//���� �ʱ�ȭ�� �Լ�
void Initialize();

int main()
{
	Initialize();
	//A�� �������� ����
	sort(arr_A.begin(), arr_A.end());
	//B�� �������� ����
	sort(arr_B.begin(), arr_B.end(), greater<>());

	for (int i = 0; i < K; i++)
	{
		if (arr_A[i] > arr_B[i]) break;

		arr_A[i] = arr_B[i];
	}

	//accumulate : arr_A.begin()~ end()���� ������ ��, �ʱⰪ�� 0
	//numeric ��� �ʿ�
	cout << accumulate(arr_A.begin(), arr_A.end(), 0);
}