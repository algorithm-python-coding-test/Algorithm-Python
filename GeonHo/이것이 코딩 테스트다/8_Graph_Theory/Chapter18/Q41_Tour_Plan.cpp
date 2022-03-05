#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;
//���� ���꿡 �ʿ��� �Լ�
int findRoot(int num);
void unionRoot(int num1, int num2);
//�Էµ� ������
int N, M;
int root[501];

int main()
{
	cin >> N >> M;
	//��Ʈ�� �ڱ� �ڽ����� �ʱ�ȭ
	for (int i = 1; i <= N; i++)
		root[i] = i;
	//�Է¹����� ��Ʈ�� �ֽ�ȭ
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int temp;
			cin >> temp;
			if (temp == 1)
				unionRoot(i + 1, j + 1);
		}
	}
	//���� ��ȹ �Է�
	vector<int> plan;
	for (int i = 0; i < M; i++)
	{
		int temp;
		cin >> temp;
		plan.push_back(temp);
	}
	//���� ��ȹ �� ���õ��� ��Ʈ�� �������� �ʴٸ� ���� �Ǿ���������
	bool ret = true;
	for (int i = 1; i < M; i++)
	{
		if (findRoot(plan[0]) != findRoot(plan[i]))
			ret = false;
	}

	if (ret) cout << "YES";
	else cout << "NO";
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