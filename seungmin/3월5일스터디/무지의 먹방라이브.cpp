// 2시간 -> 실패
// 먹는시간이 가장 짧은 음식부터 처리
// 음식을 먹는 시간은 1+ (전체 남은음식 개수) * (음식먹는시간 - 1)
// 작은음식부터 처리 할 때마다 k에서 빼주기
// k가 작거나 같게되면...남은 음식 개수 나머지 연산
// k가 -1일때는 모든 음식 시간 합보다 k가 클때
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
    // 전체 음식을 순회한 횟수
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
    // 남은 음식을 원래 있던 위치대로 저장하기 위한 작업
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