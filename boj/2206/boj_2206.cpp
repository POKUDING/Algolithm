#include <bits/stdc++.h>
using namespace std;
int N, M;

int main() {
    cin >> N >> M;
    int ans = 0;
    int map[N][M];
    int dp[2][N][M];
    int dir[4] = {1,0,-1,0};
    queue<tuple<int,int, int>> que;

    memset(dp,0,sizeof dp);
 	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < M; j++) {
			map[i][j] = temp[j] - 48;
		}
	}
    dp[0][0][0] = 1;
    que.push({0,0,0});
    while(!que.empty()) {
        auto [x, y, wall] = que.front();
        if(x == M - 1 && y == N -1) {
            cout << dp[wall][y][x];
            return 0;
        }
        for(int i = 0; i < 4; ++i) {
            int next_x = x + dir[i];
            int next_y = y + dir[(i + 1) % 4];
            if(next_x < 0 || next_y < 0 || next_x >= M || next_y >= N) continue;
            if (map[next_y][next_x] == 1 && wall == 0 && dp[1][next_y][next_x] == 0) {
                dp[1][next_y][next_x] = dp[0][y][x] + 1;
                que.push(make_tuple(next_x, next_y, 1));
            } else if (map[next_y][next_x] == 0 && dp[wall][next_y][next_x] == 0){
                dp[wall][next_y][next_x] = dp[wall][y][x] + 1;
                que.push(make_tuple(next_x, next_y, wall));
            }
        }
        que.pop();
    }
    cout << -1;
    return 0;
}