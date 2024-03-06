#include <bits/stdc++.h>

using namespace std;

int arr[1000000];

long long solve(int n) {
    int high = arr[n - 1];
    long long res = 0;
    for(int e = n - 1; e >= 0; --e) {
        if(arr[e] < high)
            res += high - arr[e];
        else
            high = arr[e];
    }
    return res;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int T;
    cin >> T;
    for(int i = 0; i < T; ++i) {
        int n;
        cin >> n;
        for(int j = 0; j < n; ++j) {
            cin >> arr[j];
        }
        cout << solve(n) << "\n";
    }
}