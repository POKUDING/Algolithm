#include <bits/stdc++.h>

using namespace std;

int N, S;

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> N >> S;
    vector<int> vec(N);
    int sum = 0, ans = INT_MAX;
    for(int i = 0, j = 0; j < N; ++j) {
        cin >> vec[j];
        sum += vec[j];
        while(sum - vec[i] >= S)
            sum-=vec[i++];
        if(sum >= S)
            ans = min(ans, j - i + 1);
    }
    if (ans == INT_MAX) ans = 0;
    cout << ans;
}