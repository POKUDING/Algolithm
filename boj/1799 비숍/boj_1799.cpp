#include <bits/stdc++.h>

using namespace std;

int N;
int Map[10][10] = {0};
int cnt = 0, ans_tmp = 0, ans = 0;
int start = 0;

unordered_map<int,int> pls_map;
unordered_map<int,int> mns_map;

void input(){
     cin >> N;
     for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j)
            cin >> Map[i][j];
     }
}

void    dfs(int x, int y) {
    if (x > N){
        ++y;
        x = y % 2 != start ? 1 : 0;
    }
    ans_tmp = max(ans_tmp, cnt);
    for(int i = y, j = x; i < N; ++i) {
        for(; j < N; j += 2) {
            if (Map[i][j] == 0 || pls_map[i + j] == 1 || mns_map[i - j] == 1)
                continue ;
            Map[i][j] = 0;
            pls_map[i + j] = 1;
            mns_map[i - j] = 1;
            ++cnt;
            dfs(j + 2, i);
            Map[i][j] = 1;
            pls_map[i + j] = 0;
            mns_map[i - j] = 0;
            --cnt;
        }
        j = (i + 1) % 2 != start ? 1 : 0;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    input();
    dfs(0, 0);
    start = 1;
    ans = ans_tmp;
    // cout << ans << "\n";
    cnt = 0;
    ans_tmp = 0;
    dfs(1, 0);
    // cout << ans_tmp << "\n";
    ans += ans_tmp;
    cout << ans;
}