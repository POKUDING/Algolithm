#include <bits/stdc++.h>

using namespace std;

int N, M, K;

vector<vector<int>> balls[2][51][51];
int times = 0;
int dirX[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dirY[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

void input() {
    memset(balls, 0, sizeof balls);
    cin >> N >> M >> K;
    int inputs[5];
    for(int i = 0; i < M; ++i) {
        for(int j = 0; j < 5; ++j) {
            cin >> inputs[j];
        }
        balls[0][inputs[0]][inputs[1]].push_back({inputs[2], inputs[3], inputs[4]});
    }
}

int changeNum(int num) {
    while (num > N)
        num -= N;
    while (num < 1)
        num += N;
    return num;
}

void moveBalls() {
    memset(balls[times % 2], 0, sizeof(balls[times % 2]));
    for(int i = 1; i  <= N; ++i) {
        for(int j = 1; j  <= N; ++j) {
            for(int k = 0; k < balls[(times - 1) % 2][i][j].size(); ++k) {
                int mass = balls[(times - 1) % 2][i][j][k][0];
                int spd = balls[(times - 1) % 2][i][j][k][1];
                int dir = balls[(times - 1) % 2][i][j][k][2];
                balls[times % 2][changeNum(i + (spd * dirY[dir]))][changeNum(j + (spd * dirX[dir]))].push_back({mass,spd, dir});
            }
        }
    }
}

void sumBalls() {
    for(int i = 1; i  <= N; ++i) {
        for(int j = 1; j  <= N; ++j) {
            if(balls[times % 2][i][j].size() < 2)
                continue ;
            int dirdiff = 0;
            int mass = 0;
            int spd = 0;
            for(int k = 0; k < balls[times % 2][i][j].size(); ++k) {
                if (!dirdiff && k >= 1 && ((balls[times % 2][i][j][k][2] % 2) != (balls[times % 2][i][j][k - 1][2] % 2))) {
                    dirdiff = 1;
                }
                mass += balls[times % 2][i][j][k][0];
                spd += balls[times % 2][i][j][k][1];
            }
            mass /= 5;
            spd /= balls[times % 2][i][j].size();
            balls[times % 2][i][j].clear();
            if(!mass)
                continue;
            for(int k = 0; k < 4; ++k) {
                balls[times % 2][i][j].push_back({mass, spd, 2 * k + dirdiff});
            }
        }
    }
}

int cntMass() {
    int rtn = 0;
    for(int i = 1; i  <= N; ++i) {
        for(int j =1; j <= N; ++j) {
            for(int k = 0; k < balls[(times - 1) % 2][i][j].size(); ++k)
                rtn+= balls[(times - 1) % 2][i][j][k][0];
        }
    }
    return rtn;
}

int process() {
    input();
    while(++times <= K) {
        moveBalls();
        sumBalls();
    }
    return cntMass();
}

int main() {
    cout << process();
}