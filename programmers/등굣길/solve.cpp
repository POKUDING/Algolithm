#include <bits/stdc++.h>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int map[101][101] = {0,};
    int answer = 0;
    
    for(int i = 0; i < puddles.size(); ++i)
        map[puddles[i][1]][puddles[i][0]] = -1;
    map[1][1] = 1;
    for(int y = 1; y <= n; ++y) {
        for(int x = 1; x <= m; ++x) {
            if(map[y][x] == -1) continue;
            map[y][x] += map[y - 1][x] == -1 ? 0 : map[y - 1][x];
            map[y][x] += map[y][x - 1] == -1 ? 0 : map[y][x - 1];
            map[y][x] %= (int)(1e9 + 7);
        }
    }
    
    return map[n][m];
}