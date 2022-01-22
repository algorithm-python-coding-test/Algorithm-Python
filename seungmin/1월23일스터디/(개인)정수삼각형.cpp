/*
- 삼각형 맨 윗줄부터 아래로 내려간다
- 삼각형 다음줄의 요소 중 대각선으로 이웃한 현재줄의 요소 두 개를 찾아내어
- 현재줄의 두 요소와 다음줄의 요소를 각각 더했을때, 더 큰 값을 따로 저장한다.
 (이 때 맨 끝의 두 요소들은 이웃하는 이전 요소가 하나뿐이므로 무조건 더하여 값을 저장한다.)
- 값들은 따로 배열에 저장하는데, 삼각형을 한줄 한줄 거듭할수록 배열의 크기는 하나씩 늘어난다
- 삼각형의 모든 줄을 탐색 후 완성되는 배열 중, 가장 큰값이 answer 이다.
*/


#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;


int solution(vector<vector<int>> triangle) {
    int answer = 0;

    int size = triangle.size();

    // 각 줄의 합을 저장할 배열, 이전 줄들의 합을 참고하기 위해 이용된다.
    vector<int> answer_array(size);

    answer_array[0] = triangle[0][0];

    // 현재 줄과 다음 줄의 합 결과를 저장하는 배열, 끝난후 answer_array로 값을 옮겨준다
    vector<int> temp_array;

    for (int i = 1; i < size; i++)
    {
        // 다음줄과의 새로운 합을 저장해야 하므로 초기화 한다.
        temp_array.clear();

        // 삼각형에서 작업할 다음 줄
        vector<int> sub_triangle = triangle[i];

        // 첫째 요소는 무조건 이전요소와 합해 저장한다
        temp_array.push_back(answer_array[0] + sub_triangle[0]);

        // 둘째~ 끝에서 둘째 요소는 이웃한 이전의 두 요소와 각각 합해보고 큰 값을 저장한다.
        for (int j = 1; j < sub_triangle.size() - 1; j++)
        {
            int sub1, sub2;

            // 여기서 answer_array가 이전의 두 요소를 불러온다.
            sub1 = sub_triangle[j] + answer_array[j - 1];
            sub2 = sub_triangle[j] + answer_array[j];

            int new_element;

            if (sub1 > sub2) new_element = sub1;
            else new_element = sub2;

            temp_array.push_back(new_element);
        }

        // 끝 요소는 무조건 이전요소와 합해 저장한다.
        temp_array.push_back(answer_array[sub_triangle.size() - 2]
            + sub_triangle[sub_triangle.size() - 1]);

        // 다음 줄 합 작업이 끝났으므로 answer_array로 옮겨준다.
        for (int i = 0; i < temp_array.size(); i++) answer_array[i] = temp_array[i];

    }

    // 합한 값들 중 가장 큰 값을 찾는다.
    int max = answer_array[0];

    for (int i = 1; i < answer_array.size(); i++)
    {
        if (max < answer_array[i]) max = answer_array[i];
    }

    answer = max;

    return answer;
}
