#include <bits/stdc++.h>

using namespace std;

int N, S;
int ans = 0, add =0;
int arr[20];

void    input() {
    cin >> N >> S;
    for(int i = 0; i < N; ++i)
        cin >> arr[i];
}

void    dfs(int n) {
    for(int i = n; i < N; ++i) {
        add += arr[i];
        if(add == S)
            ++ans;
        dfs(i + 1);
        add -= arr[i];
    }
}

int main() {
    input();
    dfs(0);
    cout << ans;
}