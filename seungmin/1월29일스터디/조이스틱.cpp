/*
******* ���� ��� *******

-�־��� ���ڿ� name�� �տ������� Ž���ϸ�, A�� �ƴҶ�, A���� ����� �����ؾ� �ش� ���ڰ� �Ǵ��� ��� ���� ���ߴ�.
-���ڿ��� Ž���ϸ鼭, 'A'�� �ƴ� ������ name������ ��ġ index���� ������ �迭 non_A_info�� �������.
-������������ �����Ͽ� non_A_info�� ����� ��ġ�� ���ڵ��� ��� �湮�ϴ� �ִ� ��θ� ����Ž������ ���ߴ�.
*/

#include <bits/stdc++.h>

using namespace std;

int solution(string name);
int joystick(int non_A_info_index, vector<int> non_A_info, int name_size);

int solution(string name) {
    int answer = 0;

    //A�� �ƴ� ���ĺ��� name������ ��ġindex �迭
    vector<int> non_A_index_info;

    // ���̽�ƽ�� �����ϴ� ù��° �ڸ� index�� 0 �� ������ �־���
    if (name[0] == 'A') non_A_index_info.push_back(0);

    for (int i = 0; i < name.size(); i++)
    {
        // 'A'�� �ƴ� ���ڵ��� ã�� ( ���̽�ƽ�� �� ���ľ� �ϴ� ���� )
        if (name[i] != 'A')
        {
            int movement;

            movement = name[i] - 'A';

            // 'A'���� ��� �������� �ش� ���ڰ� �Ǵ��� ����Ͽ� ������
            // ���ĺ��� 26���� �̹Ƿ� 13�̸��̸� up, 13���� ũ�� down���� ����
            if (movement > 13) answer += (26 - movement);
            else answer += movement;

            // 'A'�� �ƴ� ������ ��ġindex�� �迭�� ����
            non_A_index_info.push_back(i);
        }
    }

    // non_A_index�� ������ ��� �湮�ϴ� �ִܰ�� ���̸� ���� , 0���� ����
    answer += joystick(0, non_A_index_info, name.size());

    return answer;
}

// non_A_info_index : '���� ���̽�ƽ�� ��ġindex'�� ������ non_A_info �迭������ index��ġ ��
// non_A_index_info[non_A_info_index] : ���̽�ƽ�� ��ġindex��
int joystick(int non_A_info_index, vector<int> non_A_index_info, int name_size)
{
    int distance = 0;

    // ���̽�ƽ�� ���������� �̵��������� ���� ������ index
    int next_right_index;
    // ���̽�ƽ�� ������ġ�� ������ ������ġ�� �Ÿ� (1000�� �ѱ� �� ����)
    int right_distance = 1000;

    // ���̽�ƽ�� �������� �̵��������� ���� ������ index
    int next_left_index;
    // ���̽�ƽ�� ������ġ�� ���� ������ġ�� �Ÿ� (1000�� �ѱ� �� ����)
    int left_distance = 1000;

    // ���� non_A_info_index�� �¿쿡�� ���� �����, -1�� �ƴ� ���� 2���� ã�´�
    int array_size = non_A_index_info.size();

    // ���̽�ƽ�� ���������� �̵���Ű��, -1�� �ƴ� ���� ã�´� ( -1�� ���̽�ƽ�� �̹� �湮�� ��)
    for (int i = 1; i < array_size; i++)
    {
        // ���������� ��� �̵���Ű�� �ִ� ũ�⸦ ��� ���� ����� ������ ������ �д�
        int temp_index = (non_A_info_index + i) % array_size;

        // ���� ��ġ�� -1�� �ƴ϶��
        if (non_A_index_info[temp_index] != -1)
        {
            // ���� ��ġ���� �����ϰ�
            next_right_index = temp_index;
            // ������ġ�� ������ġ�� �Ÿ��� ����Ѵ�
            right_distance = abs(non_A_index_info[next_right_index] - non_A_index_info[non_A_info_index]);
            
            // �Ÿ��� ��ü name�� ���ݺ��� ū�� �������� �Ǵ��Ͽ� ������ ���� �����Ѵ�
            if (right_distance > (name_size / 2)) right_distance = (name_size - right_distance);

            // ���̽�ƽ���� ���� ��ġ�� ���� ����� ��ġ�� ���� ���� ������ ���̴� (greedy)
            break;
        }
    }

    // ���� ������ ���̽�ƽ�� �������� �̵���Ų�� �����ϰ� �����Ѵ�
    for (int i = 1; i < array_size; i++)
    {
        int temp_index = (non_A_info_index - i) % array_size;
        if (temp_index < 0) temp_index += array_size;

        if (non_A_index_info[temp_index] != -1)
        {
            next_left_index = temp_index;
            left_distance = abs(non_A_index_info[next_left_index] - non_A_index_info[non_A_info_index]);
            if (left_distance > (name_size / 2)) left_distance = (name_size - left_distance);
            break;
        }
    }

    // right_distance�� �ʱⰪ 1000���� �۾ƾ� ���̽�ƽ�� �������� �̵��� ���� �ִٴ� ��
    // right_distance�� �ִٸ� left_distance�� �ִ�
    //  right_distacne == 1000 �̶�� �� ���̻� ���̽�ƽ�� �������� �ʾƵ� �ǹǷ� 0 ��ȯ
    if (right_distance < 1000) {

        // ���� ��ġ�� ���� ���̽�ƽ�� �湮�ߴ� ���� �ǹǷ� �湮ó���� �Ѵ�
        non_A_index_info[non_A_info_index] = -1;

        // ���ȣ���� ���� ������ġ�� �Ѱ��ְ� �Լ��� ȣ���Ѵ�
        int distance1 = right_distance + joystick(next_right_index, non_A_index_info, name_size);
        int distance2 = left_distance + joystick(next_left_index, non_A_index_info, name_size);

        // ��, �� �ΰ��� ��Ȳ���� �߻��� ���� ���Ͽ� �� ���� ���� ã�´�. (�ִ� ���)
        if (distance1 < distance2) distance = distance1;
        else distance = distance2;
    }
    
    return distance;
}
