/* (���۽ð�-ó���ð�)
- ���� �ð��� ���� �ͺ��� ó���ϵ�, ���� ó������ �� �����ϴ� �͵��� �ִٸ� �� �� ó���ð��� ���� ª�� ���� ó���Ѵ�
- ������ �߿��ѵ�, 'ó���ð�'���� ���� ������, ó���ð��� ���� �� '���۽ð�'���� �����Ѵ�
- ���� �ð��� ���ϸ�, �迭 ��ü�� �Ź� ��ȸ�ϸ� ���۽ð��� ����ð� �̳��̸鼭 ó���ð��� ���� ª�� ���� ã�´�
- ( �̶� ��ȸ�� �տ������� ���ʷ� �ϸ�ȴ�. ó���ð��� ª�� �ͺ��� �տ� ������ �迭�߱� �����̴�.)
- ó���Ҷ�, answer���� (����ð� - ���۽ð�) + (ó���ð�)�� �����ְ�, ����ð��� (ó���ð�)�� �����ش�
- �׸��� ó���� ��Ҵ� �����Ѵ�. vector.erase Ȱ��

- ���� �迭 ��ü��� �߿� ���۽ð��� ����ð� �̳��� ���� ���ٸ�, ����ð��� +1 ���ְ� �ٽ� �迭��ü�� ��ȸ�Ѵ�.
- �̷��� �迭�� �����ִ� ��Ұ� ���������� �����Ѵ�.
*/

#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

// ���� �Լ�
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
    // ���� �ð� ����
    int cur_time = 0;

    while (!disk.empty())
    {
        for (int i = 0; i < disk.size(); i++)
        {
            // ����ð��̳� �����ϴ� ��Ұ� �ִ��� Ȯ��
            if (disk[i][0] <= cur_time)
            {
                answer += ( disk[i][1] + cur_time - disk[i][0]);
                cur_time += disk[i][1];
                disk.erase(disk.begin() + i);
                
                break;
            }
            // ����ð��̳� �����ϴ� ��Ұ� ���ٸ� ����ð� +1
            if (i == disk.size() - 1) cur_time++;
        }
    }
    return (answer / size);
}
