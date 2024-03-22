#include <bits/stdc++.h>

using namespace std;

int N;
long long S;

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> N >> S;
    vector<long long> vec(N + 1);
    int sum = 0, ans = INT_MAX;
    for(int i = 0, j =1; j <= N; ++j) {
        cin >> vec[j];
        vec[j] += vec[j - 1];
        while(vec[j] - vec[i + 1] >= S)
            i++;
        if(vec[j] - vec[i] >= S)
            ans = min(ans, j - i);
    }
    if (ans == INT_MAX) ans = 0;
    cout << ans;
}