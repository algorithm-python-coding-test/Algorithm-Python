#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, C;
vector<int> house;

int main()
{
	cin >> N >> C;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		house.push_back(temp);
	}
	//���� Ž���� ����ϱ� ���� �������� ����
	sort(house.begin(), house.end());

	//������ ���� �� �Ÿ��� ª�� �Ÿ��� ���
	int low = 1;
	int high = house[N - 1] - house[0];
	//����� ������ ����
	int minDistance = 0;
	//������ �Ÿ� ���̿��� ����Ž��
	while (low <= high)
	{
		int mid = (low + high) / 2;
		int num_Router = 1;
		//ó�� ��ġ�Ǵ� ��Ҵ� ������ ù��° ��
		int router_Install = house[0];

		for (int i = 1; i < N; i++)
		{
			//���ʷ� ��ȸ�ϸ� �Ÿ��� mid���� Ŀ����
			if (house[i] - router_Install >= mid)
			{
				//�ش� ��ҿ� �����⸦ ��ġ
				router_Install = house[i];
				num_Router += 1;
			}
		}
		//��ġ�� �������� ���� C���� Ŀ����
		if (num_Router >= C)
		{
			//�����Ⱓ�� �Ÿ��� �ּڰ��� mid���� Ŭ �� �����Ƿ�
			low = mid + 1;
			//���� ����� ������ ����� ����
			minDistance = mid;
		}
		else
		{
			//��ġ�� �������� ���� C���� �۴ٸ� �����Ⱓ�� �Ÿ��� �ּڰ��� mid���� Ŭ �� �����Ƿ�
			high = mid - 1;
		}
	}

	cout << minDistance;
}

//max(minDistance)