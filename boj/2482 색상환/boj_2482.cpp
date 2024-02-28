#include <bits/stdc++.h>

using namespace std;

int N, K;
int dp[1001][1001];
int mod = 1000000003;

int main() {
    cin >> N >> K;
    for(int i = 0; i <= N; ++i) {
        dp[i][1] = i;
        dp[i][0] = 1;
    }

    for(int i = 2; i <=N; ++i) {
        for(int j = 2; j <=K; ++j)
            dp[i][j] = (dp[i - 1][j] + dp[i - 2][j - 1]) % mod;
    }

    // for(int i = 0; i <=N; ++i) {
    //     for(int j = 0; j <=K; ++j)
    //         cout <<dp[i][j] << " ";
    //     cout << "\n";
    // }
    cout << (dp[N - 1][K] + dp[N - 3][K - 1]) % mod;
}