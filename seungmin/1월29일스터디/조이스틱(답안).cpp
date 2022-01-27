#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// A ->       A,B,C,D,E,F,G,H,I,J,K ,L ,M ,N ,O ,P ,Q ,R,S,T,U,V,W,X,Y,Z
int LUT[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,12,11,10,9,8,7,6,5,4,3,2,1 };

int solution(string name) {
    int answer = 0;
    //A->'A가 아닌 문자열'이 되기 위한 조이스틱 움직임 횟수 더해주기
    for (auto ch : name)
        answer += LUT[ch - 'A'];
    int len = name.length();

    // left_right : 원점에서 시작하여 'A'가 아닌 문자들을 모두 방문하기 위한 최단 경로
    // 문자열 전체 길이만큼 움직인다면 모든 문자열을 방문하므로, 최대값은 len-1 이다
    int left_right = len - 1;

    // 최단경로를 구하는 방법 : 최단 경로는 'A'를 최대한 적게 방문해야 한다.
    // 'A'가 아닌 두 문자 중에, 두 문자 사이에 'A'밖에 없는 두 문자를 골라서,
    // 원점에서 시작해 두 문자 사이에 있는 연속적인 'A'는 지나지 않고, 원점 좌우로 움직여서
    // 방문할 수 있는 경로를 구한다. 이 경로는 'A'가 아닌 모든 문자열도 방문하게 된다.

    // ex) ABAAAACA :  여기서 두 문자를 'B', 'C'라고 했을 때
    // A(원점)->B->A(원점)->A->C가 B,C 사이(B->C 방향)에 있는 'A'를 지나지 않는 최단경로이다.

    // 원점에서부터 하나씩 두 문자쌍을 잡아서, 위에서 언급한 경로 중 최단 경로를 구한다.
    // 원점부터 시작해서 두 문자쌍 중 'A'가 포함된다 해도, 
    // 그 경로는 'A'를 최대한 피하고자 하는 최단경로가 될 수 없다.  

    // 원점부터 시작한다 : i
    for (int i = 0; i < len; ++i) {
        // i와 오른쪽 사이에 'A'만을 두고 떨어져있는 'A'가 아닌 문자열 인덱스 next_i를 찾는다.
        int next_i = i + 1;
        while (next_i < len && name[next_i] == 'A')
            next_i++;
        
        // i와 next_i를 방문하는 최단경로가, 이전의 최단경로보다 작다면 갱신한다
        // 원점을 중심으로 하는 i와 next_i 방문 경로는,
        // (1) 원점->i->원점->next_i 또는 (2) 원점->next_i->원점->i 둘 중 하나이다.
        // (1)이 더 짧은 경우는 min(i, len - next_i) = i
        // (2)가 더 짧은 경우는 min(i, len - next_i) = len - next_i 이다
        left_right = min(left_right, i + (len - next_i) + min(i, len - next_i));

        // 만약 i가 마지막으로 'A'가 아닌 문자열이 된다면, next_i 는 len이 된다
        // 그런 경우, len - next_i = 0, 즉 next_i는 원점이 된다.
        // i가 원점인 경우와 헷갈리지만, i를 기준으로 i의 오른쪽이 모두 'A'라는 걸 생각하면 된다
        // ex) ABAACAAAA 에서 i가 가리키는게 C 라면 next_i는 계속 증가하여 len이 된다
        // 이때 경로는 A (원점 : next_i) -> B -> A -> A -> C (i) 가 된다
    }
    answer += left_right;
    return answer;
}


int main()
{
    int sol = solution("AABABAAAAAA");
    
    cout << sol << endl;

    return 0;
}
