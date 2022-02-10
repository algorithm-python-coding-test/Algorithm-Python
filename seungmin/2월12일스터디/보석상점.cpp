/*
- ���� �������� ��Ÿ�� ���ο� ������ ��ġ�� ���� �տ������� ����������, ������ ������ ��ġ�̴�

- ���� �տ������� for���� ���� ���� �������� ��Ÿ���� ���ο� ������ ��ġ�� ���Ѵ� ( last_gem_index )
- ���� for���� ���� ���� �տ������� ������ ������, ������ ���� �ٸ� ������ ������ new_hash_table�� �����Ѵ�

- ���� ���۵Ǵ� ������ġ : start_gem_index (�ʱⰪ - 0), ���� ������ ������ġ : last_gem_index (�ʱⰪ - ���� �������� ��Ÿ�� ���ο� ���� ��ġ)
- ù ������ ��������, start_gem_index�� �ϳ��� ������Ű�� �� ���� ������ ������ ���Ѵ�. ( �ʿ��� ������ ���ٸ� last_gem_index�� �ڷ� �ϳ��� �ű�� ã�´�.)
- ������ ������ ���̸� ���ϸ� ���� ���� ���� ���ϰ�, ���� ���� ���� start_gem_index�� last_gem_index ���� �����Ѵ�.
*/

#include <bits/stdc++.h>

using namespace std;

#include <unordered_map>

vector<int> solution(vector<string> gems) {
    vector<int> answer;

    // ������ ������ Ȯ���� hash table
    unordered_map<string, int> hash_table;

    // ���� �߰ߵ� ����
    string last_gem = gems[0];
    // ���� �߰ߵ� ������ ��ġ
    int last_gem_index = 0;
    hash_table[last_gem]++;
    
    // gems�� �տ������� ������ 
    for (int i = 1; i < gems.size(); i++)
    {
        string temp = gems[i];

        // ó������ gem�� ������ last_gem ����
        if (hash_table[temp] == 0)
        {
            last_gem = temp;
            // ó������ gem�� �߰ߵ� ��ġ index
            last_gem_index = i;
            hash_table[last_gem]++;
        }
    }

    // ������ ���ο� ����, �� ������ �� �� ����� ������ �迭
    unordered_map<string, int> new_hash_table;
    int start_gem_index = 0;

    // ù���� ������ 0 ~ last_gem_index���� �� ������ ������ ����
    for (int i = start_gem_index; i <= last_gem_index; i++)
    {
        new_hash_table[gems[i]]++;
    }

    // ù ���� ���̴� last_gen_index + 1
    int length = last_gem_index + 1;

    // answer_length���� ���� ª�� ���� ���̰� ����
    int answer_length = length;
    // ���� ª�� ���α��� ���� �� ���ν���index, ��index
    int answer_start = start_gem_index, answer_last = last_gem_index;
    
    // ù ���ο���, ���� �տ��� ������ ������ �ϳ��� ���ְ���
    // ������ ������ ��츦 ��� ����Ѵ�
    // start_gem_index�� last_gem_index�� ���� ���� ������ ������ �� �ϳ��� ���
    while (last_gem_index < gems.size() && start_gem_index != last_gem_index)
    {
        // ���� ���� ��Ͽ��� ���� ���� ������ ã�Ƽ�, 
        string start_gem = gems[start_gem_index];
        // ���� ������ �ٿ��ش�
        new_hash_table[start_gem]--;
        
        // ���ν������� �ϳ� �ڷ� �ű�
        start_gem_index++;

        // ���� �� ������ ���������� �װͰ� ���� ������ ������ ���� ���θ�Ͽ� �����ִٸ�
        if (new_hash_table[start_gem] != 0)
        {
            // ���� ������ ���̴� �ϳ� �پ�� ( ������ ��� ������ ������ ������ �����̹Ƿ� )
            length--;
        }
        // ���� �� ������ �������ν� ���� ��Ͽ� �� ������ ���ٸ� �� ������ ���ö����� ���α��̸� �÷�����
        else
        {
            string new_gem;

            while (++last_gem_index < gems.size() && start_gem.compare(gems[last_gem_index]))
            {
                // �� ������ ã�µ��� �ڷ� ������ �÷����µ�, �׶����� ���� ��ԵǴ� ��� ������ ������ ����
                new_gem = gems[last_gem_index];
                new_hash_table[new_gem]++;
            }

            // �� ������ ã�����ν� �� while���� Ż���ߴٸ�
            if (last_gem_index < gems.size())
            {
                // ���� ���� ����
                new_gem = gems[last_gem_index];
                new_hash_table[new_gem]++;

                // ���ο� ���� ���� ���
                length = last_gem_index - start_gem_index + 1;
            }
        }
        // ������ ���� ���α��̰�, ������� ���� ª�ٸ�
        if (length < answer_length)
        {
            answer_length = length;
            answer_start = start_gem_index;
            answer_last = last_gem_index;
        }
    }

    // answer_start, last�� index���̹Ƿ� 1 ����
    answer.push_back(answer_start + 1);
    answer.push_back(answer_last + 1);

    return answer;
}
