//#1. Time interval�� �̿��� ����
//>>�޸𸮳��� �ʹ� ���ϸ� �������� iteration�� ����
//0.02ms ~ 19.62ms

#include <string>
#include <vector>

using namespace std;

short time_step[86400000];		//time[i] : ims ~ ims + 1 sec time interval

int solution(vector<string> lines) {
	int ret = 0;
	for (int i = 0; i < lines.size(); i++) {
		int h, m, s, ms;
		string temp; int step;
		h = stoi(lines[i].substr(11, 2)) * 60 * 60 * 1000;
		m = stoi(lines[i].substr(14, 2)) * 60 * 1000;
		s = stoi(lines[i].substr(17, 2)) * 1000;
		ms = stoi(lines[i].substr(20, 3));
		int t = h + m + s + ms;

		temp = lines[i].substr(24); temp.pop_back();
		step = (int)(stof(temp) * 1000);

		if (t <= 1000 || t == step || t <= step + 998) {
			for (int k = 0; k <= t; k++) {
				time_step[k]++;
				if (time_step[k] > ret) ret = time_step[k];
			}
		}
		else {
			for (int k = t - step - 998; k <= t; k++) {
				time_step[k]++;
				if (time_step[k] > ret) ret = time_step[k];
			}
		}
	}
	return ret;
}

//#2. pq�� �̿��� ����
//1���� ����ϴ� ���ڿ� ó���� �״�� ����ϰ�, interval�� ������ִ� �˰��� ����
//lines�� �ڿ������� ��ȸ�ϸ�, ���۽ð��� �������� �������� �����Ͽ� ����
//pq.top()�� ���۽ð��� ���� ����ϴ� Ʈ������ ����ð����� ũ�ٸ� �ش� Ʈ������ ���� interval���� ����
//0.01ms ~ 0.67ms

#include <string>
#include <queue>
#include <vector>

using namespace std;

priority_queue<pair<int, int>> pq;

int solution(vector<string> lines) {
	int ret = 0;
	for (int i = lines.size() - 1; i >= 0; i--) {
		int h, m, s, ms;
		string temp; int step;
		h = stoi(lines[i].substr(11, 2)) * 60 * 60 * 1000;
		m = stoi(lines[i].substr(14, 2)) * 60 * 1000;
		s = stoi(lines[i].substr(17, 2)) * 1000;
		ms = stoi(lines[i].substr(20, 3));
		int t = h + m + s + ms;

		temp = lines[i].substr(24); temp.pop_back();
		step = (int)(stof(temp) * 1000);

		pq.push({ t - step + 1, t });

		while (!pq.empty() && pq.top().first - 999 > t) {
			pq.pop();
		}

		if (ret < pq.size()) ret = pq.size();
	}
	return ret;
}