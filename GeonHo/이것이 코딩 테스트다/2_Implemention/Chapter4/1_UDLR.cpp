#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

//�Է� ���� ���� ����
int _size;
string plan;
//���� �˰��� ���� ���� ����
//��������
int xpos = 1, ypos = 1;
//������ ����
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
//������ ����
char moveType[4] = { 'L', 'R', 'U', 'D' };

int main()
{
	cin >> _size; 
	//���� ����
	cin.ignore();
	//string ��� �ʿ�
	getline(cin, plan);
	//���� ����
	plan.erase(remove(plan.begin(), plan.end(), ' '), plan.end());

	//plan size��ŭ �ݺ��ϸ�
	for (int i = 0; i < plan.size(); i++)
	{
		//���� ���� ��ȹ
		char currPlan = plan[i];
		//��ȹ�� ���� ���Ե� ����
		int x_next, y_next;
		for (int j = 0; j < 4; j++)
		{
			//������ ������ �˻�
			if (currPlan == moveType[j])
			{
				x_next = xpos + dx[j];
				y_next = ypos + dy[j];
			}
		}
		//���� ������ ���� ����� �������� ����
		if (x_next < 1 || x_next > _size || y_next < 1 || y_next > _size) continue;
		//���� ����� ������ ������ġ ����
		xpos = x_next;
		ypos = y_next;
	}

	cout << "Destination coordinate is : " << xpos << " ," << ypos;
}