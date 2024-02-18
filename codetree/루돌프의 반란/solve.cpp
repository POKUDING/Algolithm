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

void crush(int diry, int dirx, int score, int num) {
    santas[num][3] += score;
    int y = Y;
    int x = X;
    grid[y][x] = 0;
    y += diry * score;
    x += dirx * score;
    while(y > 0 && x > 0 && y <= N && x <= N && grid[y][x] != 0) {
        ++y;
        ++x;
    }
    if (!(y > 0 && x > 0 && y <= N && x <= N))
        santas[num][2] = -1;
    else {
        grid[y][x] = 1;
        santas[num][2] = turns + 1;
    }
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
    for(int i = 1; i <= P; ++i) {
        if (santas[i][2] < 0 || santas[i][2] == turns) continue ;
        int santa_y = santas[i][0];
        int santa_x = santas[i][1];
        if(Y < santa_y && grid[santa_y - 1][santa_x] == 0) {
            grid[santa_y][santa_x] = 0;
            grid[santa_y - 1][santa_x] = 1;
            santas[i][0] = santa_y - 1;
            if(Y == santa_y - 1 && X == santa_x)
                crush(1, 0, D, i);
        } else if (X > santa_x && grid[santa_y][santa_x + 1] == 0) {
            grid[santa_y][santa_x] = 0;
            grid[santa_y ][santa_x + 1] = 1;
            santas[i][1] = santa_x + 1;
            if(Y == santa_y && X == santa_x + 1)
                crush(0, -1, D, i);
        } else if (Y > santa_y && grid[santa_y + 1][santa_x] == 0) {
            grid[santa_y][santa_x] = 0;
            grid[santa_y + 1][santa_x] = 1;
            santas[i][0] = santa_y + 1;
            if(Y == santa_y + 1 && X == santa_x)
                crush(-1, 0, D, i);
        } else if (X < santa_x && grid[santa_y][santa_x - 1] == 0) {
            grid[santa_y][santa_x] = 0;
            grid[santa_y][santa_x - 1] = 1;
            santas[i][1] = santa_x - 1;
            if(Y == santa_y && X == santa_x - 1)
                crush(0, 1, D, i);
        }
    }
}

void init() {
    cin >> N >> M >> P >> C >> D;
    cout << N << " " << M << " " << P << " " << C << " " << D;
    cin >> Y >> X;
    for(int i = 0; i < P; ++i) {
        int num;
        cin >> num;
        cin >> santas[num][0] >> santas[num][1];
        grid[santas[num][0]][santas[num][1]] = 1;
    }
}

void print_santas() {
    cout << "\n print santas ===============\n";
    for(int i = 1; i <= P; ++i) {
        cout << santas[i][0] << santas[i][1] << santas[i][2] << santas[i][3] << "\n";
    }
    cout << "===\n";
}

void print_rudolf() { 
    cout << "roudolf Y: " << Y << " rodolf X: " << X <<"\n";
}

void print_grid() {
    cout << "print grid ======\n";
    for(int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j)
            cout <<grid[i][j] << " ";
        cout << "\n";
    }
    cout << "====\n";
}

int main() {
    init();
    check_distance();
    while(++turns <= M) {
        cout << turns << "===================\n";
        print_grid();
        print_santas();
        print_rudolf();
        move_rudolf();
        move_santa();
        if(check_distance())
            break;
    }
    for (int i = 1; i <= P; ++i)
        cout << santas[i][3] << " ";
    return 0;
}