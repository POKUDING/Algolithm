#include <bits/stdc++.h>

using namespace std;

int T, K, tmp;

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> T;
    while(T--) {
        cin >> K;
        vector<vector<int>> dp(K + 1,vector<int>(K + 1));
        vector<int> sum(K+1);
        for(int i = 1; i <= K; ++i) {
            cin >> sum[i];
            sum[i] += sum[i - 1];
        }
        for(int i = 1; i <= K; ++i) {
            for(int j = 1; j + i <= K; ++j) {
                dp[j][j + i] = INT_MAX;
                for(int mid = j; mid < j + i; ++mid) {
                    dp[j][j + i] = min(dp[j][j + i], dp[j][mid] + dp[mid + 1][j + i] + sum[j + i] - sum[j - 1]);
                }
            }
        }
        cout << dp[1][K] <<"\n"; 
    }
}