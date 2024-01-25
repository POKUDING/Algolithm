#include <bits/stdc++.h>

using namespace std;

int recur(map<int,int>& dp, int n) {
    if (dp[n] != 0)
        return dp[n];
    int rtn = 0; 
    for(int i = 0; i <= n - 1; ++i) {
        rtn += recur(dp, i) * recur(dp, n - 1 - i);
    }
    dp[n] = rtn;
    return rtn;
}

int solution(int n) {
    cin.tie(0);
    ios::sync_with_stdio(0);
    map<int,int> dp;
    dp[0] = 1;
    dp[1] = 1;
    return recur(dp, n);
}