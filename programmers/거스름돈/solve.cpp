#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<int> money) {
    vector<int> dp(n+1);
    for(int i = 0; i < money.size(); ++i) {
        dp[money[i]] += 1;
        for(int j = money[i]; j <= n; ++j)
            dp[j] += dp[j - money[i]];
    }
    return dp[n];
}