#include <bits/stdc++.h>
using namespace std;
int N, M;

int main() {
    cin >> N >> M;
    int ans = 0;
    int map[N][M];
    int dp[2][N][M];
    int dir[4] = {1,0,-1,0};
    cout << " here";
    queue<pair<int,int>> que;

    memset(dp,0,sizeof dp);
    for(int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> map[i][j];
            cout << map[i][j] << " ";
        }
    }
    dp[0][0][0] = 1;
    que.push({0,0});
    while(!que.empty()) {
        cout << ":here\n";
        auto [x, y] = que.front();
        for(int i = 0; i < 4; ++i) {
            int next_x = x + dir[i];
            int next_y = y + dir[(i + 1) % 2];
            if(next_x < 0 || next_y < 0 || next_x >= M || next_y >= N)
                continue;
            if(map[next_y][next_x] == 0 && dp[0][next_y][next_x] == 0) {
                if(dp[0][y][x] != 0)
                    dp[0][next_y][next_x] = dp[0][y][x] + 1;
                if(dp[1][y][x] != 0)
                    dp[1][next_y][next_x] = dp[0][y][x] + 1;
                dp[1][next_y][next_x] = dp[1][y][x] + 1;
                que.push({next_x, next_y});
            } else if (map[next_y][next_x] == 1 && dp[1][next_y][next_x] == 0) {
                dp[1][next_y][next_x] = dp[0][y][x] + 1;
                que.push({next_x, next_y});
            } else if (map[next_y][next_x] == 0 && dp[0][next_y][next_x] > dp[0][y][x] + 1) {
                dp[0][next_y][next_x] = dp[0][y][x] + 1;
                que.push({next_x, next_y});
            } else if (map[next_y][next_x] == 0 && dp[1][next_y][next_x] > dp[1][y][x] + 1) {
                dp[1][next_y][next_x] = dp[1][y][x] + 1;
                que.push({next_x, next_y});
            }
        }
        que.pop();
    }
    if (dp[0][N -1][M - 1] || dp[1][N -1][M - 1]) {
        ans = max(dp[0][N -1][M - 1], dp[1][N -1][M - 1]);
        if (ans == 0)
            ans = -1;
    } else
        ans = min(dp[0][N -1][M - 1], dp[1][N -1][M - 1]);
    cout << ans;

    return 0;
}