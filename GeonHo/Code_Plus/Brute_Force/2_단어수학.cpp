// #2. �ܾ����
//�� �ڸ����� �������� ���ĺ��� �������� ũ�⸦ ��
//�ڸ��� ������ �ش� ����� �������� �����Ͽ� ����ϴ°��� �� �ż���

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<string> words;
	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		words.push_back(temp);
	}
	int alpha[26] = { 0 };
	for (int i = 0; i < words.size(); i++) {
		for (int j = 0; j < words[i].length(); j++) {
			alpha[words[i][j] - 'A'] += pow(10, words[i].length() - (j + 1));
		}
	}

	sort(alpha, alpha + 26, greater<int>());

	int result = 0;
	for (int i = 0; i < 10; i++) {
		result += alpha[i] * (9 - i);
	}
	cout << result;
}