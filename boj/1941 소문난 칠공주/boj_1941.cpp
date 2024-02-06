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
}

bool check_cross(int n) {
    int x = n % 5;
    int y = n / 5;
    if((x > 0 && check[y][x - 1] == true) || (y > 0 && check[y - 1][x] == true) || \
        (y < 4 && check[y + 1][x] == true) || (x < 4 && check[y][x+1] == true))
        return true;
    return false;
}

void dfs(int n, int dep) {
    int x = n % 5;
    int y = n /5;
    cout << "dep: " << dep << " n: " << n << " x: " << x << " y: " << y << "\n";
    print();
    if ((dep >= 1 && check[y][x]) || (dep > 1 && !check_cross(n))) {
        cout << "cross fail\n";
        return ;
    }
    if(dep == 7) {
        ++ans;
        cout << " ans++\n";
        return ;
    }
    if(dep >= 1)
        check[y][x] = true;
    for(int i = 0; i < 25; ++i)  {
        if (Map[i / 5][i % 5] == 'Y') {
            if(un_s == 3) {
                cout << "un_s == 3 \n";
                continue;
            }
            ++un_s;
        }
        dfs(i, dep + 1);
        if (Map[i/5][i%5] == 'Y')
            --un_s;
    }
    if(dep >= 1)
        check[y][x] = false;
}

int main() {
    memset(check, false, sizeof check);
    input();
    print();
    dfs(-1,0);
    cout << ans;
}