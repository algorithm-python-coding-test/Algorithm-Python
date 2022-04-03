//#1. ������ ���� ��� ���� ������ ���������� ó��
//�ǿ����ڸ� �����ϴ� �κп��� ����� ������� �ʾ� ��� x
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> operand;
vector<char> op;

int main() {
	string form; cin >> form;
	string temp = "";
	for (int i = 0; i < form.length(); i++) {
		if (form[i] == '+' || form[i] == '-') {
			int cur = stoi(temp);
			operand.push_back(cur);
			op.push_back(form[i]);
			temp = "";
		}
		else if (i == form.length() - 1) {
			temp += form[i];
			int cur = stoi(temp);
			operand.push_back(cur);
		}
		else {
			temp += form[i];
		}
	}

	vector<int> n_operand;

	for (int i = 0; i < op.size(); i++) {
		if (op[i] == '-') {
			n_operand.push_back(operand[i]);
			if (i == op.size() - 1) n_operand.push_back(operand[i + 1]);
		}
		else if (op[i] == '+') {
			n_operand.push_back(operand[i] + operand[i + 1]);
			i++;
		}
	}


	int ret = n_operand[0];
	for (int i = 1; i < n_operand.size(); i++) {
		ret -= n_operand[i];
	}

	cout << ret;

	return 0;
}

//#2. �ǿ����� ������ list�� �Ѵٸ� �ذ� �����Ұ�
//�ٵ� linkedlist������ ������ ���� �����ϸ� Ǯ �� �����Ͱ���.

//#3. ���� ������ �׸����� �˻��ϸ� ����
//�ǿ����ڸ� ó������ �ʿ� ���� ���� ������ ���� ������ ��� ���Ͽ� �������� ����
//���� ���Ŀ� ������ �ٽ� ���´ٸ� �������ִ� ���� ret���� ���� �� �ٽ� ������ ����
//�������� ������ ������ �� ���� neg�� ���ִ� ������ ó���ؾ���
//0ms
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> operand;
vector<char> op;

int main() {
	string form; cin >> form;
	string temp = "";
	for (int i = 0; i < form.length(); i++) {
		if (form[i] == '+' || form[i] == '-') {
			int cur = stoi(temp);
			operand.push_back(cur);
			op.push_back(form[i]);
			temp = "";
		}
		else if (i == form.length() - 1) {
			temp += form[i];
			int cur = stoi(temp);
			operand.push_back(cur);
		}
		else {
			temp += form[i];
		}
	}

	int ret = operand[0];
	int neg = 0;
	bool isNeg = false;
	for (int i = 0; i < op.size(); i++) {
		if (op[i] == '+' && !isNeg) {
			ret += operand[i + 1];
		}
		else if (op[i] == '+' && isNeg) {
			neg += operand[i + 1];
		}
		else if (op[i] == '-' && !isNeg) {
			isNeg = true;
			neg += operand[i + 1];
		}
		else if (op[i] == '-' && isNeg) {
			ret -= neg;
			neg = operand[i + 1];
		}
	}
	ret -= neg;

	cout << ret;

	return 0;
}