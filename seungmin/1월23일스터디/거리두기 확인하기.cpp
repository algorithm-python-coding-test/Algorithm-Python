// 각 교실을 탐색한다.
// 먼저 사람이 앉아있는 곳 'P'를 찾고 거기서 탐색을 시작한다.
// 탐색을 시작하는 곳인 'P'는 'X'로 바꾸고 탐색을 시작한다. (그래야 두 칸 떨어진 거리두기 확인 때 오류가 나지 않는다.)
// 상하좌우를 확인하여, 사람 'P'가 나오면 false (한 칸 떨어진 거리두기 확인)
// 파티션 'X'가 나오면 그대로 넘어간다.
// 빈공강 'O'가 나오면 그 빈공간에서 상하좌우를 확인하여 사람 'P'가 있는지 확인한다. (두 칸 떨어진 거리두기 확인)
// 탐색중 false가 한번이라도 나오면 즉시 반복문을 빠져나온다.


#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <vector>

using namespace std;

// 상, 하, 좌, 우 확인을 위한 값
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

bool SocialDistance2(vector<string> ap_place, int a_row, int a_col);

// 교실 안 현재 위치(a_row, a_col)에서 1칸 떨어진 상하좌우 확인
bool SocialDistance(vector<string> ap_place, int a_row, int a_col)
{
    // 거리두기가 잘 되었는지 저장하는 변수
    bool is_success = true;

    // (방문처리) 나중에 방문하지 않기위해 현재 위치의 상태를 파티션 'X'로 바꾸기
    ap_place[a_row][a_col] = 'X';

    // 현재 위치에서 1칸 떨어진 상하좌우 탐색
    for (int i = 0; i < 4; i++)
    {
        // 탐색할 위치의 row, col 값
        int other_row = a_row + dy[i];
        int other_col = a_col + dx[i];

        // 탐색할 위치의 row, col이 유효한 값이 아니라면 다음 위치로 넘어감
        if (other_row < 0 || other_row > 4) continue;
        if (other_col < 0 || other_col > 4) continue;

        // 탐색할 위치의 상태값을 저장하는 변수
        char other_condition = ap_place[other_row][other_col];

        // 탐색할 위치의 상태값이 'P' 라면 거리두기가 안 된것이므로
        // false 대입후 for문을 즉시 빠져 나온다
        if (other_condition == 'P')
        {
            is_success = false;
            break;
        }
        // 탐색할 위치의 상태값이 'X' 라면 거리두기가  된것이므로
        // 바로 다음 위치로 넘어간다
        else if (other_condition == 'X') continue;

        // 탐색할 위치의 상태값이 'O' 라면 거기에서 다시 상하좌우를 확인해야한다. (현재 위치에서 2칸 떨어진 곳)
        else
        {
            // 탐색할 위치에서 상하좌우를 확인하는 함수 : 거리두기가 되었다면 true, 아니면 false 반환
            is_success = SocialDistance2(ap_place, other_row, other_col);

            // 만약 위에서 확인한 결과 거리두기가 안되었다면 즉시 for문 탈출
            if (is_success == false) break;
        }
    }
    // 현재 위치의 거리두기 결과값 반환
    return is_success;
}

// 두 칸 떨어진 거리두기를 확인하는 함수
// 상하좌우를 확인하여 'P'가 있다면 거리두기가 안 된거고, 'O'나 'X'가 있다면 거리두기가 된 것
bool SocialDistance2(vector<string> ap_place, int a_row, int a_col)
{
    bool is_success = true;

    for (int i = 0; i < 4; i++)
    {
        int other_row = a_row + dy[i];
        int other_col = a_col + dx[i];

        if (other_row < 0 || other_row > 4) continue;
        if (other_col < 0 || other_col > 4) continue;

        // 탐색할 위치의 상태값
        char other_condition = ap_place[other_row][other_col];

        // 'P'가 있으면 거리두기를 못 지킨것
        if (other_condition == 'P')
        {
            is_success = false;
            break;
        }
        // 'X'나 'O'가 있으면 거리두기를 지킨것
        else continue;
    }
    return is_success;
}


vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;

    // 각 대기실이 거리두기를 지키는지 체크하고
    // 그 여부에 따라 0, 1 을 answer 배열에 저장
    for (int place_index = 0; place_index < 5; place_index++)
    {
        // 거리두기가 지켜지는지 나타내는 변수
        bool temp = true;

        // place_index번째 교실에서 각 요소가 거리두기를 지키는지 하나씩 체크
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                // 사람이 있을 때 ('P')만 거리두기 확인
                // SocialDistance함수 return 값이 false라면 거리두기가 안 지켜진 것이므로 바로 for문 탈출
                if (places[place_index][i][j] == 'P' && !SocialDistance(places[place_index], i, j))
                {
                    temp = false;
                    break;
                }
            }
            // 거리두기가 안 지켜지면 for문 탈출
            if (temp == false) break;
        }
        // place_index번째 교실의 거리두기의 결과값을 answer 배열에 저장
        answer.push_back(temp);
    }
    return answer;
}
