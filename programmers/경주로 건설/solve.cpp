#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> board) {
    int H = board.size();
    int W = board[0].size();
    int dx[4] = {0,1,0,-1};
    int dist[2][H][W];
    queue<tuple<int,int,int>> que;
    
    memset(dist, 0, sizeof dist);
    que.push(make_tuple(0,0, 0));
    que.push(make_tuple(0,0, 1));
    while(!que.empty()) {
        auto [x,y, dir] = que.front();
        for(int i = 0; i < 4; ++i) {
            int next_x = x + dx[i];
            int next_y = y + dx[(i + 1) % 4];
            int next_cost = dir == i ? 100 : 600;
            if (next_x < 0 || next_y < 0 || next_x >= W || next_y >= H || board[next_y][next_x] == 1)
                continue;
            if (dist[i%2][next_y][next_x] != 0 && dist[i%2][next_y][next_x] <= dist[dir % 2][y][x] + next_cost)
                continue;
            dist[i%2][next_y][next_x] = dist[dir % 2][y][x] + next_cost;
            que.push(make_tuple(next_x,next_y,i));
        }
        que.pop();
    }
    if(dist[0][H - 1][W - 1] == 0 || dist[1][H -1][W - 1] == 0)
        return max(dist[1][H - 1][W - 1], dist[0][H - 1][W - 1]);
    return min(dist[0][H - 1][W - 1], dist[1][H - 1][W - 1]);
}
