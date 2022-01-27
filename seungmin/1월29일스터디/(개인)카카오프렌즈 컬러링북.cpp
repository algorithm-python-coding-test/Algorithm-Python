#include <bits/stdc++.h>

using namespace std;



// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    int dx[] = { 0,0,-1,1 };
    int dy[] = { -1,1,0,0 };

    vector<vector<int>> is_visited;

    for (int i = 0; i < m; i++)
    {
        vector<int> temp(n);

        is_visited.push_back(temp);
    }


    for (int row = 0; row < m; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (is_visited[row][col] == 0 && picture[row][col]!= 0)
            {
                number_of_area++;

                int area_size = 0;

                queue<pair<int, int>> temp_array;
                pair<int, int> temp;
                temp.first = row;
                temp.second = col;

                temp_array.push(temp);
                int area_value = picture[row][col];

                while (temp_array.size())
                {
                    temp = temp_array.front();
                    temp_array.pop();

                    if (is_visited[temp.first][temp.second]) continue;
                    else
                    {
                        area_size++;
                        is_visited[temp.first][temp.second] = 1;

                        pair<int, int> next;
                        for (int i = 0; i < 4; i++)
                        {
                            if ((temp.first + dy[i]) < 0 || (temp.first + dy[i]) >= m) continue;
                            if ((temp.second + dx[i]) < 0 || (temp.second + dx[i]) >= n) continue;

                            next.first = temp.first + dy[i];
                            next.second = temp.second + dx[i];

                            if (is_visited[next.first][next.second] == 0 &&
                                picture[next.first][next.second] == area_value)
                                temp_array.push(next);
                        }
                    }
                }

                if (max_size_of_one_area < area_size)
                    max_size_of_one_area = area_size;
            }
        }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}



int main()
{
    vector<int> sol = solution(6, 4, { {1, 1, 1, 0}, {1, 2, 2, 0}, {1, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 0, 3}, {0, 0, 0, 3} });


    cout << sol[0] << " " << sol[1] << endl;
   
    return 0;
}
