// gggggg

#include <bits/stdc++.h>

using namespace std;

struct node {
    int STR, INT;
    char cnt = 0;
    int rewards = 0;
};

struct quest {
    int STR, INT, PNT;
} qst[50];

bool cmp(node a, node b)
{
    return a.rewards < b.rewards;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> qst[i].STR >> qst[i].INT >> qst[i].PNT;

    vector<node> dp;

    for (int i = 0; i < n; i++) {
        node tem;
        tem.STR = qst[i].STR;
        tem.INT = qst[i].INT;

        for (int l = 0; l < n; l++) {
            if (qst[l].STR <= tem.STR || qst[l].INT <= tem.INT) {
                tem.cnt++;
                tem.rewards += qst[l].PNT;
            }
        }
        dp.push_back(tem);
    }
    sort(dp.begin(), dp.end(), cmp);

    int STR = 1;
    int INT = 1;
    int rw = 0;
    int cnt = 0;

    for (int i = 0; i < dp.size(); i++) {
        if (dp[i].STR - STR <= rw || dp[i].INT - INT <= rw) {

            STR = dp[i].STR;
            INT = dp[i].INT;
            rw = dp[i].rewards - (dp[i].STR - 1) - (dp[i].INT - 1);
            cnt = dp[i].cnt;
        }
        else {
            break;
        }
    }

    cout << cnt << '\n';

    return 0;
}