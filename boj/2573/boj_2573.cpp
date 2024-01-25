#include <bits/stdc++.h>

using namespace std;

int N, M;
int mount = 0, ans = 0;
int dir[4] = {1, 0, -1, 0};

int main() {
    cin >> N >> M;
    int map[N][M];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> map[i][j];
            if(map[i][j] != 0)
                ++mount;
        }
    }

    while(mount) {
        int x =0, y = 0;
        for(; y <N; ++y){
            x = 0;
            for(; x< M; ++x){
                if (map[y][x] != 0)
                    break;
            }
            if(x != M)
                break;
        }
        int tmp_map[N][M];
        memset(tmp_map, 0, sizeof tmp_map);
        queue<pair<int,int>> que;
        que.push({x,y});
        tmp_map[y][x] = 1;
        int visit = 0;
        while (!que.empty()) {
            ++visit;
            auto [q_x, q_y] = que.front();
            tmp_map[q_y][q_x] = -1;
            for (int i = 0; i < 4; ++i) {
                int next_x = q_x + dir[i];
                int next_y = q_y + dir[(i+1) % 4];
                if (next_x < 0 || next_y < 0 || next_x >= M || next_y >= N)
                    continue;
                if (map[next_y][next_x] != 0 && tmp_map[next_y][next_x] == 0) {
                    tmp_map[next_y][next_x] = 1;
                    que.push({next_x,next_y});
                }
            }
            que.pop();
        }
        if (visit != mount)
            break;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (map[i][j] != 0){
                    for(int d = 0; d < 4; ++d) {
                        int dx = j + dir[d];
                        int dy = i + dir[(d+1) % 4];
                        if (dx < 0 || dy < 0 || dx >= M || dy >= N)
                            continue;
                        if(map[dy][dx] == 0 && tmp_map[dy][dx] == 0)
                            map[i][j] = map[i][j] == 0 ? 0 : map[i][j] - 1;
                    }
                    if(map[i][j] == 0)
                        --mount;
                }
            }
        }
        ++ans;
    }
    if(mount)
        cout << ans;
    else
        cout << 0;
    return 0;
}