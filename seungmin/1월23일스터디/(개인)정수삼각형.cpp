/*
- �ﰢ�� �� ���ٺ��� �Ʒ��� ��������
- �ﰢ�� �������� ��� �� �밢������ �̿��� �������� ��� �� ���� ã�Ƴ���
- �������� �� ��ҿ� �������� ��Ҹ� ���� ��������, �� ū ���� ���� �����Ѵ�.
 (�� �� �� ���� �� ��ҵ��� �̿��ϴ� ���� ��Ұ� �ϳ����̹Ƿ� ������ ���Ͽ� ���� �����Ѵ�.)
- ������ ���� �迭�� �����ϴµ�, �ﰢ���� ���� ���� �ŵ��Ҽ��� �迭�� ũ��� �ϳ��� �þ��
- �ﰢ���� ��� ���� Ž�� �� �ϼ��Ǵ� �迭 ��, ���� ū���� answer �̴�.
*/


#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;


int solution(vector<vector<int>> triangle) {
    int answer = 0;

    int size = triangle.size();

    // �� ���� ���� ������ �迭, ���� �ٵ��� ���� �����ϱ� ���� �̿�ȴ�.
    vector<int> answer_array(size);

    answer_array[0] = triangle[0][0];

    // ���� �ٰ� ���� ���� �� ����� �����ϴ� �迭, ������ answer_array�� ���� �Ű��ش�
    vector<int> temp_array;

    for (int i = 1; i < size; i++)
    {
        // �����ٰ��� ���ο� ���� �����ؾ� �ϹǷ� �ʱ�ȭ �Ѵ�.
        temp_array.clear();

        // �ﰢ������ �۾��� ���� ��
        vector<int> sub_triangle = triangle[i];

        // ù° ��Ҵ� ������ ������ҿ� ���� �����Ѵ�
        temp_array.push_back(answer_array[0] + sub_triangle[0]);

        // ��°~ ������ ��° ��Ҵ� �̿��� ������ �� ��ҿ� ���� ���غ��� ū ���� �����Ѵ�.
        for (int j = 1; j < sub_triangle.size() - 1; j++)
        {
            int sub1, sub2;

            // ���⼭ answer_array�� ������ �� ��Ҹ� �ҷ��´�.
            sub1 = sub_triangle[j] + answer_array[j - 1];
            sub2 = sub_triangle[j] + answer_array[j];

            int new_element;

            if (sub1 > sub2) new_element = sub1;
            else new_element = sub2;

            temp_array.push_back(new_element);
        }

        // �� ��Ҵ� ������ ������ҿ� ���� �����Ѵ�.
        temp_array.push_back(answer_array[sub_triangle.size() - 2]
            + sub_triangle[sub_triangle.size() - 1]);

        // ���� �� �� �۾��� �������Ƿ� answer_array�� �Ű��ش�.
        for (int i = 0; i < temp_array.size(); i++) answer_array[i] = temp_array[i];

    }

    // ���� ���� �� ���� ū ���� ã�´�.
    int max = answer_array[0];

    for (int i = 1; i < answer_array.size(); i++)
    {
        if (max < answer_array[i]) max = answer_array[i];
    }

    answer = max;

    return answer;
}
