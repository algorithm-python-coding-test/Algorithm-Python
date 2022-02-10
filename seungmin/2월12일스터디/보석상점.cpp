/*
- 가장 마지막에 나타난 새로운 보석의 위치가 가장 앞에서부터 쇼핑했을때, 쇼핑이 끝나는 위치이다

- 먼저 앞에서부터 for문을 돌며 가장 마지막에 나타나는 새로운 보석의 위치를 구한다 ( last_gem_index )
- 다음 for문을 돌며 가장 앞에서부터 쇼핑을 했을때, 쇼핑한 각기 다른 보석의 개수를 new_hash_table에 저장한다

- 쇼핑 시작되는 보석위치 : start_gem_index (초기값 - 0), 쇼핑 끝나는 보석위치 : last_gem_index (초기값 - 가장 마지막에 나타난 새로운 보석 위치)
- 첫 쇼핑을 기준으로, start_gem_index를 하나씩 증가시키며 그 다음 가능한 쇼핑을 구한다. ( 필요한 보석이 없다면 last_gem_index를 뒤로 하나씩 옮기며 찾는다.)
- 각각의 쇼핑의 길이를 비교하며 가장 적은 값을 구하고, 가장 적을 때의 start_gem_index와 last_gem_index 값을 저장한다.
*/

#include <bits/stdc++.h>

using namespace std;

#include <unordered_map>

vector<int> solution(vector<string> gems) {
    vector<int> answer;

    // 보석의 종류를 확인할 hash table
    unordered_map<string, int> hash_table;

    // 새로 발견된 보석
    string last_gem = gems[0];
    // 새로 발견된 보석의 위치
    int last_gem_index = 0;
    hash_table[last_gem]++;
    
    // gems를 앞에서부터 읽으며 
    for (int i = 1; i < gems.size(); i++)
    {
        string temp = gems[i];

        // 처음보는 gem이 나오면 last_gem 변경
        if (hash_table[temp] == 0)
        {
            last_gem = temp;
            // 처음보는 gem이 발견된 위치 index
            last_gem_index = i;
            hash_table[last_gem]++;
        }
    }

    // 각각의 쇼핑에 대해, 각 보석을 몇 개 사는지 저장할 배열
    unordered_map<string, int> new_hash_table;
    int start_gem_index = 0;

    // 첫번쨰 쇼핑인 0 ~ last_gem_index까지 각 보석의 개수를 저장
    for (int i = start_gem_index; i <= last_gem_index; i++)
    {
        new_hash_table[gems[i]]++;
    }

    // 첫 쇼핑 길이는 last_gen_index + 1
    int length = last_gem_index + 1;

    // answer_length에는 가장 짧은 쇼핑 길이가 저장
    int answer_length = length;
    // 가장 짧은 쇼핑길이 저장 시 쇼핑시작index, 끝index
    int answer_start = start_gem_index, answer_last = last_gem_index;
    
    // 첫 쇼핑에서, 가장 앞에서 쇼핑한 보석을 하나씩 없애가며
    // 가능한 쇼핑의 경우를 모두 계산한다
    // start_gem_index와 last_gem_index가 같은 경우는 보석의 종류가 단 하나인 경우
    while (last_gem_index < gems.size() && start_gem_index != last_gem_index)
    {
        // 현재 쇼핑 목록에서 가장 앞의 보석을 찾아서, 
        string start_gem = gems[start_gem_index];
        // 쇼핑 개수를 줄여준다
        new_hash_table[start_gem]--;
        
        // 쇼핑시작점을 하나 뒤로 옮김
        start_gem_index++;

        // 가장 앞 보석을 없앴음에도 그것과 같은 종류의 보석이 아직 쇼핑목록에 남아있다면
        if (new_hash_table[start_gem] != 0)
        {
            // 다음 쇼핑의 길이는 하나 줄어듦 ( 여전히 모든 종류의 보석을 가지는 쇼핑이므로 )
            length--;
        }
        // 가장 앞 보석을 없앰으로써 쇼핑 목록에 그 보석이 없다면 그 보석이 나올때까지 쇼핑길이를 늘려야함
        else
        {
            string new_gem;

            while (++last_gem_index < gems.size() && start_gem.compare(gems[last_gem_index]))
            {
                // 그 보석을 찾는동안 뒤로 쇼핑을 늘려가는데, 그때까지 새로 사게되는 모든 보석의 개수를 증가
                new_gem = gems[last_gem_index];
                new_hash_table[new_gem]++;
            }

            // 그 보석을 찾음으로써 위 while문을 탈출했다면
            if (last_gem_index < gems.size())
            {
                // 보석 개수 증가
                new_gem = gems[last_gem_index];
                new_hash_table[new_gem]++;

                // 새로운 쇼핑 길이 계산
                length = last_gem_index - start_gem_index + 1;
            }
        }
        // 위에서 계산된 쇼핑길이가, 현재까지 가장 짧다면
        if (length < answer_length)
        {
            answer_length = length;
            answer_start = start_gem_index;
            answer_last = last_gem_index;
        }
    }

    // answer_start, last는 index값이므로 1 증가
    answer.push_back(answer_start + 1);
    answer.push_back(answer_last + 1);

    return answer;
}
