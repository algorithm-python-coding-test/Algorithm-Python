/* (시작시간-처리시간)
- 시작 시간이 빠른 것부터 처리하되, 무언가 처리중일 때 시작하는 것들이 있다면 그 중 처리시간이 가장 짧은 것을 처리한다
- 정렬이 중요한데, '처리시간'으로 먼저 정렬후, 처리시간이 같은 시 '시작시간'으로 정렬한다
- 현재 시간을 셈하며, 배열 전체를 매번 순회하며 시작시간이 현재시간 이내이면서 처리시간이 가장 짧은 것을 찾는다
- ( 이때 순회는 앞에서부터 차례로 하면된다. 처리시간이 짧은 것부터 앞에 오도록 배열했기 때문이다.)
- 처리할때, answer에는 (현재시간 - 시작시간) + (처리시간)을 더해주고, 현재시간은 (처리시간)을 더해준다
- 그리고 처리한 요소는 제거한다. vector.erase 활용

- 만약 배열 전체요소 중에 시작시간이 현재시간 이내인 것이 없다면, 현재시간을 +1 해주고 다시 배열전체를 순회한다.
- 이렇게 배열에 남아있는 요소가 없을때까지 진행한다.
*/

#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

// 정렬 함수
bool cmp(vector<int> a, vector<int> b)
{
    if (a[1] == b[1]) return a[0] < b[0];
    return a[1] < b[1];
}


int solution(vector<vector<int>> jobs) {
    
    int answer = 0;

    int size = jobs.size();

    vector<vector<int>> disk = jobs;

    sort(disk.begin(), disk.end(), cmp);
    // 현재 시간 변수
    int cur_time = 0;

    while (!disk.empty())
    {
        for (int i = 0; i < disk.size(); i++)
        {
            // 현재시간이내 시작하는 요소가 있는지 확인
            if (disk[i][0] <= cur_time)
            {
                answer += ( disk[i][1] + cur_time - disk[i][0]);
                cur_time += disk[i][1];
                disk.erase(disk.begin() + i);
                
                break;
            }
            // 현재시간이내 시작하는 요소가 없다면 현재시간 +1
            if (i == disk.size() - 1) cur_time++;
        }
    }
    return (answer / size);
}
