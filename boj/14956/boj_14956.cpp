#include <bits/stdc++.h>

using namespace std;

int N, M;

int position[4][4] = {{0,1,2,3},{0,3,2,1},{2,1,0,3},{2,3,0,1}};
int direction[4][4] = {{1,0,0,2},{0,1,1,3},{3,2,2,0},{2,3,3,1}};
int plusx[4] = {0,0,1,1};
int plusy[4] = {0,1,1,0};

pair<int,int>    dfs(int x, int y, int num, int range, int dir) {
    if(range == 1)
        return {x, y};
    long long walks = (long long)range * range;
    for (int i = 0; i < 4; ++i) {
        if (num + (i * walks / 4) <= M && M < num + ((i + 1) * walks / 4)) {
            x += plusx[position[dir][i]] * range / 2;
            y += plusy[position[dir][i]] * range / 2;
            return dfs(x, y, num + (i * walks / 4), range / 2, direction[dir][i]);
        }
    }
    return {N, 1};
}

int main() {
    cin >> N >> M;
    pair<int,int> rtn = dfs(1,1,1, N, 0);
    cout << rtn.first << ' ' << rtn.second;
}