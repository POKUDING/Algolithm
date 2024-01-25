#include <bits/stdc++.h>

using namespace std;

queue<tuple<int,int,int,int>> que;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int M, N, H;
    cin >> M >> N >> H;
    int boxs[H][N][M];
    int dir[6] = {1,-1,0,0,0,0};
    int ans = 0;
    int tomato = 0;

    for(int h = 0; h < H; ++h) {
        for(int n = 0; n < N; ++n) {
            for (int m = 0; m < M; ++m) {
                cin >> boxs[h][n][m];
                if (boxs[h][n][m] == 1) {
                    que.push(make_tuple(h,n,m,0));
                } else if (boxs[h][n][m] == 0)
                    ++tomato;
            }
        }
    }
    while(!que.empty() && tomato != 0) {
        auto [h,n,m, d] = que.front();
        for(int i = 0; i < 6; ++i) {
            int next_h = h + dir[i];
            int next_n = n + dir[(i + 2) % 6];
            int next_m = m + dir[(i + 4) % 6];
            if (next_h < 0 || next_h >= H || next_n < 0 || next_n >= N || next_m < 0 || next_m >= M)
                continue;
            if(boxs[next_h][next_n][next_m] == 0) {
                boxs[next_h][next_n][next_m] = 1;
                ans = ans > d + 1 ? ans : d + 1;
                --tomato;
                que.push(make_tuple(next_h,next_n,next_m, d + 1));
            }
        }
        que.pop();
    }
    if (tomato != 0)
        cout << -1;
    else
        cout << ans;
}