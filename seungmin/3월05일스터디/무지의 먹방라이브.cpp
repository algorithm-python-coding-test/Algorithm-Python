// 2�ð� -> ����
// �Դ½ð��� ���� ª�� ���ĺ��� ó��
// ������ �Դ� �ð��� 1+ (��ü �������� ����) * (���ĸԴ½ð� - 1)
// �������ĺ��� ó�� �� ������ k���� ���ֱ�
// k�� �۰ų� ���ԵǸ�...���� ���� ���� ������ ����
// k�� -1�϶��� ��� ���� �ð� �պ��� k�� Ŭ��
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long ll;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.first < b.first;
}

int solution(vector<int> food_times, long long k) {
    int answer = 0;

    ll sum = 0;

    for (int i = 0; i < food_times.size(); i++)
        sum += food_times[i];

    if (sum <= k) return -1;

    vector<pair<int, int>> foods;
    for (int i = 0; i < food_times.size(); i++) foods.push_back({ food_times[i], i + 1 });
    sort(foods.begin(), foods.end(),cmp);

    queue<pair<int, int>> food_time;
    for (int i = 0; i < food_times.size(); i++) food_time.push(foods[i]);

    int size = food_time.size();
    // ��ü ������ ��ȸ�� Ƚ��
    ll cycle = 0;
    while (1) {
        ll cur_food = food_time.front().first;
        
        if (cur_food - cycle <= 0) {
            food_time.pop();
            size--;
            continue;
        }
        ll eat_time = 1 + (cur_food - 1 - cycle) * size;
        cycle += (cur_food - 1 - cycle);

        if (k - eat_time > 0) {
            k -= eat_time;
            food_time.pop();
            size--;
        }
        else {
            break;
        }
    }
    // ���� ������ ���� �ִ� ��ġ��� �����ϱ� ���� �۾�
    vector<int> remains;
    for (int i = 0; i < food_time.size(); i++) {
        remains.push_back(food_time.front().second);
        food_time.pop();
    }
    
    sort(remains.begin(), remains.end());

    answer = remains[k % size];
    
    return answer;
}

int main() {
    
    int sol = solution({ 3, 1, 2 , 3, 5 }, 5);
    

    return 0;
}