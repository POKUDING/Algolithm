#include <bits/stdc++.h>

using namespace std;

vector<string> Map;
int ans = 0;
int un_s = 0;
bool check[5][5] = {false};

void input() {
    string tmp;
    for(int i = 0; i < 5; ++i) {
        cin >> tmp;
        Map.push_back(tmp);
    }
}

void print () {
    for(int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j)
            cout << check[i][j] << " ";
        cout << "\n";
    }
    cout << "=================\n";
}

bool check_cross(int x, int y) {
    if((x > 0 && check[y][x - 1] == true) || (y > 0 && check[y - 1][x] == true) || \
        (y < 4 && check[y + 1][x] == true) || (x < 4 && check[y][x+1] == true))
        return true;
    return false;
}

bool check_map(int x, int y) {
    int cnt_visit = 0;
    int cnt_s = 0;
    bool visit[5][5] = {false};
    int dir[4] = {1,0,-1,0};
    queue<pair<int,int>> que;

    que.push({x, y});
    visit[y][x] = true;
    while(!que.empty()) {
        auto [x , y] = que.front();
        ++cnt_visit;
        if(Map[y][x] == 'S')
            ++cnt_s;
        for (int i = 0; i < 4; ++i) {
            int next_x = x + dir[i];
            int next_y = y + dir[(i + 1) % 4];
            if(next_x < 0 || next_y < 0 || next_x >= 5 || next_y >=5 || check[next_y][next_x] == false || visit[next_y][next_x] == true)
                continue;
            visit[next_y][next_x] = true;
            que.push({next_x, next_y});
        }
        que.pop();
    }
    if (cnt_visit == 7 && cnt_s >= 4)
        return true;
    return false;
}

void dfs(int n, int dep) {
    int x = n % 5;
    int y = n /5;
    if(dep == 7) {
            // cout << "dep: " << dep << " n: " << n << " x: " << x << " y: " << y << "\n";
        if(check_map(x, y)) {
            // print();
            ++ans;
        }
        return ;
    }
    for(int i = n + 1; i < 25; ++i)  {
        check[i /5][i % 5] = true;
        dfs(i , dep + 1);
        check[i /5][i % 5] = false;
    }
}

int main() {
    memset(check, false, sizeof check);
    input();
    // print();
    dfs(-1,0);
    cout << ans;
}