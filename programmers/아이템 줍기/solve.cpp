#include <bits/stdc++.h>

using namespace std;

int grid[160][160] = {{0}};
int dir[4] = {1,0,-1,0};
int ans = INT_MAX;

void draw(vector<vector<int>>& rectangle) {
    for(int i = 0, size = rectangle.size(); i < size; ++i) {
        for(int j = rectangle[i][1] * 2 + 1; j < rectangle[i][3] * 2; ++j) {
            for(int k = rectangle[i][0] * 2 + 1; k < rectangle[i][2] * 2; ++k) {
                grid[j][k] = 1;
            }
        }
    }
}

void findLine() {
    for(int i = 0; i <=100; ++i) {
        for(int j = 0; j <=100; ++j) {
            if(grid[i][j] == 0 && (grid[i - 1][j] == 1 || grid[i + 1][j] == 1 || \
              grid[i][j -1] == 1 || grid[i][j + 1] == 1 || \
              grid[i - 1][j - 1] == 1 || grid[i + 1][j - 1]  == 1 || \
              grid[i - 1][j + 1] == 1 || grid[i + 1][j + 1] == 1))
                grid[i][j] = 2;
        }
    }
}

int dfs(int x, int y) {
    int rtn = 1;
    if(grid[y][x] != 2)
        return 0;
    grid[y][x] = 6;
    for(int i = 0; i < 4; ++i) {
        int next_x = x + dir[i];
        int next_y = y + dir[(i + 1) % 4];
        if (next_x < 0 || next_y < 0 || next_x > 101 || next_y > 101)
            continue;
        rtn += dfs(next_x, next_y);
    }
    return rtn;
}

int check(int cx, int cy) {
    for(int i = 0; i < 4; ++i) {
        if(grid[cy + dir[(i + 1) % 4]][cx + dir[i]] == 2)
            ans = min(ans, dfs(cx + dir[i], cy + dir[(i + 1) % 4]));
    }
    return ans;
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    draw(rectangle);
    findLine();
    grid[characterY * 2][characterX * 2] = 3;
    grid[itemY * 2][itemX * 2] = 4;
    int ans = check(characterX * 2, characterY * 2);
    return ans / 2 + 1;
}
