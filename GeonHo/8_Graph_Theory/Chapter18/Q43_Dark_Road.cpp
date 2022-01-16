#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//���� ���꿡 �ʿ��� �Լ�
int findRoot(int num);
void unionRoot(int num1, int num2);

int N, M;
vector<pair<int, pair<int, int>>> road_info;
int root[200001];

int main()
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		root[i] = i;
	//��� �濡���� ���� �Է�
	for (int i = 0; i < M; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		//�������� �����ϱ� ���� cost�� ù��° ���ҷ� ��ġ
		road_info.push_back({ cost, {from, to} });
	}
	//ũ�罺Į �˰����� ����ϱ� ���� sorting
	sort(road_info.begin(), road_info.end());

	int reduction = 0;
	int total = 0;
	//ũ�罺Į �˰��� ����
	for (int i = 0; i < road_info.size(); i++)
	{
		int cost = road_info[i].first;
		int a = road_info[i].second.first;
		int b = road_info[i].second.second;
		total += cost;

		if (findRoot(a) != findRoot(b))
		{
			unionRoot(a, b);
			reduction += cost;
		}
	}

	cout << total - reduction;
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