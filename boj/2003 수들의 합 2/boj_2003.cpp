#include <bits/stdc++.h>

using namespace std;

int N;
long long M;

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> N >> M;
    vector<long long> vec(N);
    int ans = 0;
    long long sum = 0;
    for(int start = 0, end = 0; end < N; ++end) {
        cin >> vec[end];
        sum += vec[end];
        while(sum > M)
            sum -= vec[start++];
        if(sum == M)
            ++ans;
    }
    cout << ans;
}