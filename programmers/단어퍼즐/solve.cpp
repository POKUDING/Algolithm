#include <bits/stdc++.h>
using namespace std;
const static auto _ = []() {cin.tie(0); cout.tie(0); ios::sync_with_stdio(0); return nullptr;}();

bool strncmp(string& s, string& t, int idx) {
    for(int i = 0; i < s.size(); ++i) {
        if(s[i] != t[idx + i])
            return false;
    }
    return true;
}

int solution(vector<string> strs, string t)
{
    vector<int> dp(t.size() + 1, INT_MAX);
    dp[t.size()] = 0;
    for(int i = t.size() - 1; i >= 0; --i) {
        for(int j = 0; j < strs.size(); ++j) {
            if(i + strs[j].size() <= t.size() && dp[i + strs[j].size()] != INT_MAX && \
              strncmp(strs[j],t,i))
                dp[i] = min(dp[i],dp[i + strs[j].size()] + 1);
        }
    }

    return dp[0] == INT_MAX ? -1 : dp[0];
}