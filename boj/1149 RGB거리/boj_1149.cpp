#include <bits/stdc++.h>

using namespace std;

int N;

int cost[3];
int dp[2][3];

int main() {
    cin >> N;
    cin >> dp[0][0] >> dp[0][1] >> dp[0][2];
    for(int i = 1; i < N; ++i) {
        cin >> cost[0] >> cost[1] >> cost[2];
        dp[i % 2][0] = min(dp[(i - 1) % 2][1], dp[(i - 1) % 2][2]) + cost[0];
        dp[i % 2][1] = min(dp[(i - 1) % 2][0], dp[(i - 1) % 2][2]) + cost[1];
        dp[i % 2][2] = min(dp[(i - 1) % 2][0], dp[(i - 1) % 2][1]) + cost[2];
    }
    cout <<  min({dp[(N - 1) % 2][0],dp[(N - 1) % 2][1],dp[(N - 1) % 2][2]});
}