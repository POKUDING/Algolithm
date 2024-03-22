#include <bits/stdc++.h>

using namespace std;

int N;
long long M;

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> N >> M;
    unordered_map<long long, int> mp;
    int ans = 0;
    long long sum = 0;
    long long tmp;
    mp[0] = 1;
    for(int end = 0; end < N; ++end) {
        cin >> tmp;
        sum += tmp;
        ++mp[sum];
        ans += mp[sum - M];
    }
    cout << ans;
}