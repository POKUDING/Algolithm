#include <bits/stdc++.h>

using namespace std;

int N, M;

int dfs(int s, int e, vector<vector<int>>& dp, vector<int>& arr) {
    if(s >= e)
        return 1;
    if(arr[s] != arr[e])
        dp[s][e] = -1;
    else if(dp[s][e] == 0)
        dp[s][e] = dfs(s + 1, e - 1, dp, arr);
    return dp[s][e];
}

int main() {
    cin.tie(0); cout.tie(0);ios::sync_with_stdio(0);

    cin >> N;
    vector<int> arr(N + 1);
    vector<vector<int>> dp(N + 1, vector<int>(N + 1));

    for(int i = 1; i <= N; ++i)
        cin >> arr[i];

    cin >> M;
    for(int i = 0,s ,e; i < M; ++i) {
        cin >> s >> e;
        cout << (dfs(s,e,dp,arr) > 0 ? 1 : 0) << "\n";
    }
}