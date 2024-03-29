#include <bits/stdc++.h>
using namespace std;
int N, M;
int grid[50][50] {{0}};
int clouds [2][50][50] {{{0}}};
int dirX[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dirY[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int diagX[4] = {-1, 1, 1, -1};
int diagY[4] = {-1, -1, 1, 1};
int times = 0;
queue<pair<int,int>> moves;

int changeNum(int num) {
    while (num >= N)
        num -= N;
    while (num < 0)
        num += N;
    return num;
}

void cloudMover(int dir, int cnt) {
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            if(clouds[0][i][j] == times)
                clouds[1][changeNum(i + (cnt * dirY[dir - 1]))][changeNum(j + (cnt * dirX[dir - 1]))] = times;
        }
    }
}

void rain() {
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j)
        if(clouds[1][i][j] == times)
            ++grid[i][j];
    }
}

void checkDiag() {
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j) {
            if(clouds[1][i][j] != times)
                continue;
            for(int k = 0; k < 4; ++k) {
                int x = j + diagX[k];
                int y = i + diagY[k];
                if(x < 0 || y < 0 || x>= N || y >= N)
                    continue;
                if(grid[y][x] > 0)
                    ++grid[i][j];
            }
        }
    }
}

void makeCloud() {
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            if(grid[i][j] >= 2 && clouds[1][i][j] != times) {
                grid[i][j] -= 2;
                clouds[0][i][j] = times + 1;
            }
        }
    }
}

int countWater() {
    int rtn = 0;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            rtn += grid[i][j];
        }
    }
    return rtn;
}

int process() {
    while(++times <= M) {
        auto[dir, cnt] = moves.front();
        moves.pop();
        cloudMover(dir, cnt);
        rain();
        checkDiag();
        makeCloud();
    }
    return countWater();
}

void input() {
    cin >> N >> M;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j)
            cin >> grid[i][j];
    }
    int tmp1, tmp2;
    for(int i = 0; i < M; ++i) {
        cin >> tmp1 >> tmp2;
        moves.push({tmp1, tmp2});
    }
    clouds[0][N - 1][0] = 1;
    clouds[0][N - 1][1] = 1;
    clouds[0][N - 2][0] = 1;
    clouds[0][N - 2][1] = 1;
}

int main() {
    memset(grid, 0, sizeof grid);
    memset(clouds, 0, sizeof clouds);
    input();
    cout << process();
    return 0;
}