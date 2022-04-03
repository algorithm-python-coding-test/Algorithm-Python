//#1. �ܼ� ������ ���� ����
//�翬�ϰԵ� �ð��ʰ� O(N^4) ��

#include <iostream>
#include <vector>

using namespace std;

struct quest {
	int STR;
	int INT;
	int PNT;
}quests[51];

bool isPossible[1001][1001];

int ret = 0;

void makePossible(int st, int in, int pt) {
	for (int i = 0; i <= pt; i++) {
		for (int j = 0; j <= pt - i; j++) {
			if (st + i > 1000 || in + j > 1000) continue;
			isPossible[st + i][in + j] = true;
		}
	}
}

int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int st, in, pt;
		cin >> st >> in >> pt;
		quests[i].STR = st; quests[i].INT = in; quests[i].PNT = pt;
	}

	isPossible[1][1] = true;

	for (int st = 1; st <= 1000; st++) {
		for (int in = 1; in <= 1000; in++) {
			if (isPossible[st][in]) {
				int pt = (1 - st) + (1 - in), cnt = 0;
				for (int i = 1; i <= N; i++) {
					if (quests[i].STR <= st || quests[i].INT <= in) {
						pt += quests[i].PNT;
						cnt++;
					}
				}
				if (ret < cnt) ret = cnt;
				makePossible(st, in, pt);
			}
		}
	}

	cout << ret;
}

//#2. DP...?
//68ms

#include <iostream>

using namespace std;

struct quest {
	int STR;
	int INT;
	int PNT;
}quests[51];

bool isPossible[1001][1001];
int pnt[1001][1001];

int ret = 0;

int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int st, in, pt;
		cin >> st >> in >> pt;
		quests[i].STR = st; quests[i].INT = in; quests[i].PNT = pt;
	}

	isPossible[1][1] = true;
	for (int i = 1; i <= N; i++) {
		if (quests[i].STR == 1 || quests[i].INT == 1) {
			ret++;
			pnt[1][1] += quests[i].PNT;
		}
	}

	for (int st = 1; st <= 1000; st++) {
		for (int in = 1; in <= 1000; in++) {
			if ((isPossible[st - 1][in] && pnt[st - 1][in] >= 1) || (isPossible[st][in - 1] && pnt[st][in - 1] >= 1)) {
				int cnt = 0;
				for (int i = 1; i <= N; i++) {
					if (quests[i].STR <= st || quests[i].INT <= in) {
						cnt++;
						pnt[st][in] += quests[i].PNT;
					}
				}
				pnt[st][in] += (1 - st) + (1 - in);
				isPossible[st][in] = true;
				if (cnt > ret) ret = cnt;
			}
		}
	}

	cout << ret;
}

//#3. quests�� linkedlist�� ����, solved[][]�� ���� ��, st-in���� �Ϸ��� �� �ִ� ����Ʈ ���� ����
//->solved[st][in] = max(solved[st - 1][in], solved[st][in - 1]) + solvable
//->pnt[st][in] = solved == solved[st - 1][in] ? pnt[st - 1][in] : pnt[st][in - 1] + solvable_pnt
//quests list���� solved�� ���� ����
//=> quests�׸��� ��� ��ȸ�ϴ� �ݺ����� ���� ���� ����
//=> quests�� �ִ� ũ�Ⱑ 50�̶� ����...?