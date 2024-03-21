#include<bits/stdc++.h>

using namespace std;

int N, K;

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin>> N >> K;
    int ans = 0;
    vector<int> S(N);
    for(int i = 0; i < N; ++i)
        cin >> S[i];
    int even = 0, odd = 0;
    for(int end = 0, start = 0; end < N; ++end) {
        if(S[end] % 2 != 0)
            ++odd;
        else
            ++even;
        ans = max(ans, even);
        while(odd > K) {
            if(S[start++] % 2 != 0)
                --odd;
            else
                --even;
        }
    }
    cout << ans;

    // unordered_map<int,int> mp;
    // for(int i = 0, odd = 0;i < N; ++i) {
    //     if(S[i] % 2 != 0) {
    //         ++odd;
    //         mp[odd] = i;
    //     }
    //     if(odd > K)
    //         ans = max(ans, i - mp[odd - K] - K);
    //     else
    //         ans = i - odd + 1;
    // }
    // cout << ans;
}