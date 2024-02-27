#include <bits/stdc++.h>

int N, K;

int dfs(int i,int d, vector<vector<int>>& dp) {
    if (d == K) {
        return dp[1][i];
    }
    
}

int main() {
    cin >> N >> K;
    vector<vector<int>> dp(2,vector<int>(N));
    dp[0] = 1;
    dp[1] = 1;
    if(N / 2 < K)
        cout << 0;
    else {
        for(int i = 0; )
    }
}