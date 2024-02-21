#include <bits/stdc++.h>

using namespace std;

int grid[51][51];
int turns = 0;
int N, M, P, C, D, Y, X;
//0:y 1:x 2:상태 3:점수
vector<vector<int>> santas(31, vector<int>(4));
priority_queue<vector<int>> pq;

bool check_distance() {
    pq = priority_queue<vector<int>>();
    for(int i = 1; i <= P; ++i) {
        if (santas[i][2] == -1) continue;
        ++santas[i][3];
        pq.push({-((int)pow(Y - santas[i][0], 2) + (int)pow(X - santas[i][1], 2)), santas[i][0], santas[i][1], i});
    }
    return pq.empty();
}

void ting_santa(int x, int y, int dirx, int diry){
    int num = grid[y][x];
    grid[y][x] = 0;
    if (x + dirx > N || x + dirx <= 0 || y + diry > N || y + diry <=0) {
        santas[num][2] = -1;
        return ;
    } else if (grid[y + diry][x + dirx] != 0)
        ting_santa(x + dirx, y + diry, dirx, diry);
    grid[y + diry][x + dirx] = num;
    santas[num][0] = y + diry;
    santas[num][1] = x + dirx;
}

void crush(int diry, int dirx, int score, int num) {
    santas[num][3] += score;
    int y = Y;
    int x = X;
    grid[y][x] = 0;
    y += diry * score;
    x += dirx * score;
    if(y > 0 && x > 0 && y <= N && x <= N && grid[y][x] != 0)
        ting_santa(x, y, dirx, diry);
    if (!(y > 0 && x > 0 && y <= N && x <= N)) {
        santas[num][2] = -1;
        return ;
    }
    grid[y][x] = num;
    santas[num][2] = turns + 1;
    santas[num][0] = y;
    santas[num][1] = x;
}

void move_rudolf() {
    int santa_y = pq.top()[1];
    int santa_x = pq.top()[2];
    int snata_n = pq.top()[3];
    int diry = 0, dirx = 0;
    if (santa_y != Y) {
        diry = santa_y > Y ? 1: -1;
        Y += diry;
    }
    if (santa_x != X) {
        dirx = santa_x > X ? 1: -1;
        X += dirx;
    }
    if(santa_y == Y && santa_x == X)
        crush(diry, dirx,C, snata_n);
}

void move_santa() {
    int dirX[4] = {0, 1, 0, -1};
    int dirY[4] = {-1, 0, 1, 0};
    for(int i = 1; i <= P; ++i) {
        if (santas[i][2] < 0 || santas[i][2] >= turns) continue ;
        vector<pair<int,int>> moves;
        int santa_y = santas[i][0];
        int santa_x = santas[i][1];
        int cur_distance = (int)pow(santa_y - Y, 2) + (int)pow(santa_x - X, 2);
        for(int j = 0; j < 4; ++j) {
            if(santa_y + dirY[j] <= 0 || santa_y + dirY[j] > N || santa_x + dirX[j] <= 0 || santa_x + dirX[j] > N) continue;
            int move_distance = (int)pow(santa_y + dirY[j] - Y, 2) + (int)pow(santa_x + dirX[j] - X, 2);
            if(move_distance < cur_distance)
                moves.push_back({move_distance, j});
        }
        sort(moves.begin(),moves.end());
        for(int j = 0; j < moves.size(); ++j) {
            if(grid[santa_y + dirY[moves[j].second]][santa_x + dirX[moves[j].second]] == 0) {
                grid[santa_y][santa_x] = 0;
                grid[santa_y + dirY[moves[j].second]][santa_x + dirX[moves[j].second]] = i;
                santas[i][0] = santa_y + dirY[moves[j].second];
                santas[i][1] = santa_x + dirX[moves[j].second];
                if(Y == santas[i][0] && X == santas[i][1])
                    crush(-dirY[moves[j].second], -dirX[moves[j].second], D, i);
                break;
            }
        }
    }
}

void init() {
    cin >> N >> M >> P >> C >> D;
    cin >> Y >> X;
    for(int i = 0; i < P; ++i) {
        int num;
        cin >> num;
        cin >> santas[num][0] >> santas[num][1];
        grid[santas[num][0]][santas[num][1]] = num;
    }
}

int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    init();
    check_distance();
    while(++turns <= M) {
        move_rudolf();
        move_santa();
        if(check_distance())
            break;
    }
    for (int i = 1; i <= P; ++i)
        cout << santas[i][3] - 1 << " ";
    return 0;
}