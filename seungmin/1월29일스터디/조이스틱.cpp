/*
******* 구현 방법 *******

-주어진 문자열 name을 앞에서부터 탐색하며, A가 아닐때, A에서 몇번을 조작해야 해당 문자가 되는지 모두 세서 더했다.
-문자열을 탐색하면서, 'A'가 아닌 문자의 name에서의 위치 index값을 저장한 배열 non_A_info을 만들었다.
-원점에서부터 시작하여 non_A_info에 저장된 위치의 문자들을 모두 방문하는 최단 경로를 완전탐색으로 구했다.
*/

#include <bits/stdc++.h>

using namespace std;

int solution(string name);
int joystick(int non_A_info_index, vector<int> non_A_info, int name_size);

int solution(string name) {
    int answer = 0;

    //A가 아닌 알파벳의 name에서의 위치index 배열
    vector<int> non_A_index_info;

    // 조이스틱이 시작하는 첫번째 자리 index값 0 는 무조건 넣어줌
    if (name[0] == 'A') non_A_index_info.push_back(0);

    for (int i = 0; i < name.size(); i++)
    {
        // 'A'가 아닌 문자들을 찾음 ( 조이스틱이 꼭 거쳐야 하는 문자 )
        if (name[i] != 'A')
        {
            int movement;

            movement = name[i] - 'A';

            // 'A'에서 몇번 움직여야 해당 문자가 되는지 계산하여 더해줌
            // 알파벳이 26글자 이므로 13미만이면 up, 13보다 크면 down으로 조작
            if (movement > 13) answer += (26 - movement);
            else answer += movement;

            // 'A'가 아닌 문자의 위치index값 배열에 저장
            non_A_index_info.push_back(i);
        }
    }

    // non_A_index의 값들을 모두 방문하는 최단경로 길이를 구함 , 0에서 시작
    answer += joystick(0, non_A_index_info, name.size());

    return answer;
}

// non_A_info_index : '현재 조이스틱의 위치index'를 저장한 non_A_info 배열에서의 index위치 값
// non_A_index_info[non_A_info_index] : 조이스틱의 위치index값
int joystick(int non_A_info_index, vector<int> non_A_index_info, int name_size)
{
    int distance = 0;

    // 조이스틱을 오른쪽으로 이동했을때의 다음 목적지 index
    int next_right_index;
    // 조이스틱의 현재위치와 오른쪽 다음위치의 거리 (1000을 넘길 수 없음)
    int right_distance = 1000;

    // 조이스틱을 왼쪽으로 이동했을때의 다음 목적지 index
    int next_left_index;
    // 조이스틱의 현재위치와 왼쪽 다음위치의 거리 (1000을 넘길 수 없음)
    int left_distance = 1000;

    // 현재 non_A_info_index와 좌우에서 가장 가까운, -1이 아닌 값들 2개를 찾는다
    int array_size = non_A_index_info.size();

    // 조이스틱을 오른쪽으로 이동시키며, -1이 아닌 곳을 찾는다 ( -1은 조이스틱이 이미 방문한 곳)
    for (int i = 1; i < array_size; i++)
    {
        // 오른쪽으로 계속 이동시키며 최대 크기를 벗어날 때를 대비해 나머지 연산을 둔다
        int temp_index = (non_A_info_index + i) % array_size;

        // 다음 위치가 -1이 아니라면
        if (non_A_index_info[temp_index] != -1)
        {
            // 다음 위치값을 저장하고
            next_right_index = temp_index;
            // 현재위치와 다음위치의 거리를 계산한다
            right_distance = abs(non_A_index_info[next_right_index] - non_A_index_info[non_A_info_index]);
            
            // 거리가 전체 name의 절반보다 큰지 작은지를 판단하여 적절한 값을 대입한다
            if (right_distance > (name_size / 2)) right_distance = (name_size - right_distance);

            // 조이스틱에서 현재 위치와 가장 가까운 위치가 가장 먼저 가야할 곳이다 (greedy)
            break;
        }
    }

    // 같은 과정을 조이스틱을 왼쪽으로 이동시킨다 가정하고 수행한다
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

    // right_distance가 초기값 1000보다 작아야 조이스틱이 다음으로 이동할 곳이 있다는 뜻
    // right_distance가 있다면 left_distance도 있다
    //  right_distacne == 1000 이라는 건 더이상 조이스틱이 움직이지 않아도 되므로 0 반환
    if (right_distance < 1000) {

        // 현재 위치는 이제 조이스틱이 방문했던 곳이 되므로 방문처리를 한다
        non_A_index_info[non_A_info_index] = -1;

        // 재귀호출을 통해 다음위치를 넘겨주고 함수를 호출한다
        int distance1 = right_distance + joystick(next_right_index, non_A_index_info, name_size);
        int distance2 = left_distance + joystick(next_left_index, non_A_index_info, name_size);

        // 좌, 우 두가지 상황에서 발생한 값을 비교하여 더 작은 값을 찾는다. (최단 경로)
        if (distance1 < distance2) distance = distance1;
        else distance = distance2;
    }
    
    return distance;
}
