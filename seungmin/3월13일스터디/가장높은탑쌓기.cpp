// 건호님 코드에서 살짝 변경
// 역추적을 이용한 탑번호 출력.. 가장 위 탑부터 출력해야해서 거꾸로 출력해야함


#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int dp[101];
int max_idx = 1;
vector<int> blocklist[101];

struct block {
    int num;
    int area;
    int height;
    int weight;
} blocks[101];

struct pre_info {
    int cnt = 1;
    int pre = 0;
} pre[101];

int blockCnt;

bool comp(block a, block b) {
    return a.area < b.area;
}

int main() {
    
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> blockCnt;
    int area, height, weight;
    for (int i = 1; i <= blockCnt; i++) {
        cin >> area >> height >> weight;
        blocks[i].num = i;
        blocks[i].area = area;
        blocks[i].height = height;
        blocks[i].weight = weight;
    }

    sort(blocks + 1, blocks + blockCnt + 1, comp);
    for (int i = 1; i <= blockCnt; i++) {
        dp[i] = blocks[i].height;
        blocklist[i].push_back(i);
    }

    for (int i = 1; i <= blockCnt; i++) {
        for (int j = 1; j < i; j++) {
            if (blocks[i].weight > blocks[j].weight) {
                if (dp[i] < dp[j] + blocks[i].height) {
                    dp[i] = dp[j] + blocks[i].height;
                    pre[i].pre = j;
                    pre[i].cnt = pre[j].cnt + 1;
                }
            }
        }
        if (dp[i] > dp[max_idx]) max_idx = i;
    }

    cout << pre[max_idx].cnt << '\n';
    int idx = max_idx;

    vector<int> nums;
    nums.push_back(blocks[idx].num);

    while (pre[idx].pre != 0) {
        nums.push_back(blocks[pre[idx].pre].num);
        idx = pre[idx].pre;
    }

    for (int i = nums.size() - 1; i >= 0; i--)
        cout << nums[i] << '\n';

    return 0;
}

/*
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[101];
int max_idx = 1;
vector<int> blocklist[101];

struct block {
    int num;
    int area;
    int height;
    int weight;
}blocks[101];

int blockCnt;

bool comp(block a, block b) {
    return a.area < b.area;
}

int main() {
    cin >> blockCnt;
    int area, height, weight;
    for (int i = 1; i <= blockCnt; i++) {
        cin >> area >> height >> weight;
        blocks[i].num = i;
        blocks[i].area = area;
        blocks[i].height = height;
        blocks[i].weight = weight;
    }

    sort(blocks + 1, blocks + blockCnt + 1, comp);
    for (int i = 1; i <= blockCnt; i++) {
        dp[i] = blocks[i].height;
        blocklist[i].push_back(i);
    }
    for (int i = 1; i <= blockCnt; i++) {
        for (int j = 1; j < i; j++) {
            if (blocks[i].weight > blocks[j].weight) {
                if (dp[i] < dp[j] + blocks[i].height) {
                    dp[i] = dp[j] + blocks[i].height;
                    blocklist[i] = blocklist[j];
                    blocklist[i].push_back(i);
                }
            }
        }
        if (dp[i] > dp[max_idx]) max_idx = i;
    }
    cout << blocklist[max_idx].size() << '\n';
    for (int i = 0; i < blocklist[max_idx].size(); i++) {
        cout << blocks[blocklist[max_idx][i]].num << '\n';
    }
}

*/