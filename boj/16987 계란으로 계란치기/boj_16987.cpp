#include <bits/stdc++.h>

using namespace std;

int N;
int cnt;
int ans = 0;
int egg[8][2];

void    input() {
    cin >> N;
    for(int i =0; i < N; ++i)
        cin >> egg[i][1] >> egg[i][0];
    cnt = N;
}

void    crush_egg(int n, int i) {
        egg[n][1] -= egg[i][0];
        egg[i][1] -= egg[n][0];
        if(egg[n][1] <= 0)
            --cnt;
        if(egg[i][1] <= 0)
            --cnt;
}

void revert_egg(int n, int i) {
        if(egg[n][1] <= 0)
            ++cnt;
        if(egg[i][1] <= 0)
            ++cnt;
        egg[n][1] += egg[i][0];
        egg[i][1] += egg[n][0];
}

void    dfs(int n) {
    if(n == N || cnt <= 1) {
        ans = max(ans, N - cnt);
        return ;
    } else if (egg[n][1] <= 0)
        return dfs(n + 1);

    for(int i = 0; i < N; ++i) {
        if (n == i || egg[i][1] <= 0)
            continue;
        crush_egg(n, i);
        dfs(n + 1);
        revert_egg(n,i);
    }
}

int main() {
    input();
    dfs(0);
    cout << ans;
}