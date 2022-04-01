#include <string>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//첫 시도
// 처음에 가능한 한 큰 물통을 만들고, 물을 합치는 과정에서 나머지로 남는 물은 큐에 저장한다
// 가장 작은 물부터 그 다음 작은 물로 합쳐야, 최소의 물이 필요하다고 생각함!
// 큐에서 하나씩 pop하여, 두 물을 합친다
/* 13 2 예제에서 ( 물통개수 ) 라고 한다면
   1 1 1 1 1 1 1 1 1 1 1 1 1 (13)
   2 2 2 2 2 2 1 (13-6 = 7) 큐 : 1
   4 4 4 1 (7-3 = 4) 큐 : 1
   8 4 1 (4-1 = 3) 큐 : 1 4
   마지막에 8 push -> 큐 : 1 4 8
   
   큐에서 1, 4 pop
   4 - 1 = 3 만큼의 물을 가져온다면
   8 4 4 -> 8 8 (물통 개수 2) 
   그러므로 3 반환
*/

int main() {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, K;
    cin >> N >> K;

    int answer = 0;
    queue<int> q;
    int liter = 1;
    // 전체 물통 개수
    int cnt = N;
    while (cnt > K && N != 1) {
        if (N % 2) q.push(liter);
        N = N / 2;
        cnt -= N;
        liter *= 2;
    }

    if (cnt > K) {
        // 가장 큰 물통의 물 push
        q.push(liter);
        
        int cur = q.front();
        q.pop();
        while (!q.empty() && cnt > K) {
            int nxt = q.front();
            q.pop();
            answer += (nxt - cur);
            // tem과 cur이 합쳐지므로 물통개수는 -1
            cnt--;
            // 합쳐진다면, 현재 물은 2배가 된다
            cur = nxt * 2;
        }
        // 그럼에도 물통개수가 K보다 크다면 -1
        if (cnt > K) answer = -1;
    }
    cout << answer << "\n";
    return 0;
}

/*
// (힌트 : 2진수를 써라) 참고
// 현재 물의 총량을 2진수로 나타냈을때 1의 개수가 최소물병의 개수
// 1의 개수(물병의 개수)를 K보다 작도록 줄이려면, 
// 1을 없애야 하기 때문에 가장 least한 1을 찾아서 그 만큼의 물을 더해줘서 1->0으로 만든다
// 물을 더해줄 때마다 1의 개수가 K보다 같거나 작은지 체크한다.

// K가 1이상인 수이기 때문에 불가능한 경우는 없다. 어떤 경우라도 더해서 100...0 으로 만들 수 있음

// N보다 크거나 같으면서, 1이 K개이하 나타나는 가장 작은 수를 찾자!!

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, K;
    cin >> N >> K;

    int answer = 0;
    while (1) {
        //1의 개수
        int cnt = 0;
        int tem = N;
        //lesat 1을 찾기 위한 flag
        int flag = 0;
        int fst_1 = 0, idx = 0;
        // 이진수에서 1의 개수 구하는 법
        // >> 하면서(2씩 나누면서) 한자리씩 확인하는 방법뿐??
        while (tem != 0) {
            if (tem % 2) {
                // least 1의 자릿수 찾기
                if (flag == 0) {
                    fst_1 = idx;
                    flag = 1;
                }
                // 총 1의 개수 찾기
                cnt++;
            }
            // tem / 2
            tem = tem >> 1;
            idx++;
        }
        // 1개수가 K개 이하라면 탈출
        if (cnt <= K) {
            break;
        }
        // 더해줘야할 물의 양 (1 물병의 개수)
        int lst = 1 << fst_1;
        N += lst;
        answer += lst;
    }
    cout << answer << '\n';
    return 0;
}
*/