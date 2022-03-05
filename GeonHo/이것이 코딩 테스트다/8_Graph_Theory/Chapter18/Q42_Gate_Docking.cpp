#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;
//���� ���꿡 �ʿ��� �Լ�
int findRoot(int num);
void unionRoot(int num1, int num2);

int G, P;
int root[100001];

int main()
{
	cin >> G;
	cin >> P;
	//��Ʈ�� �ڱ� �ڽ����� �ʱ�ȭ
	for (int i = 1; i <= G; i++)
		root[i] = i;
	//������ ������ ����Ʈ��ȣ�� ���� ����Ʈ�� ��ŷ
	//����Ʈ �׷����� ��Ʈ�� 0�̵Ǹ� �� �̻� ��ŷ�� �Ұ����ϹǷ� break
	int ret = 0;
	for (int i = 0; i < P; i++)
	{
		int p_gate;
		cin >> p_gate;
		int r_gate = findRoot(p_gate);
		if (r_gate == 0) break;
		unionRoot(r_gate, r_gate - 1);
		ret++;
	}
	cout << ret;
}

int findRoot(int num)
{
	if (num == root[num]) return num;
	return root[num] = findRoot(root[num]);
}

void unionRoot(int num1, int num2)
{
	num1 = findRoot(num1);
	num2 = findRoot(num2);
	if (num1 < num2) root[num2] = num1;
	else root[num1] = num2;
}