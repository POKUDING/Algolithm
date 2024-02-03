#include <bits/stdc++.h>

using namespace std;

int N;
int Map[64][64];
string rtn;

void input(){
    string tmp;
    cin >> N;
    for(int i = 0; i < N; ++i) {
        cin >> tmp;
        for(int j = 0; j < N; ++j)
            Map[i][j] = tmp[j] - '0';
    }
}

bool checkRange(int x, int y, int range) {
    int base = Map[y][x];
    for(int i = y; i < y + range; ++i) {
        for(int j = x; j < x+ range; ++j) {
            if(Map[i][j] != base)
                return false;
        }
    }
    return true;
}

void dfs(int x, int y, int range) {
    if (checkRange(x, y, range)) {
        rtn += Map[y][x] + '0';
        return ;
    }
    rtn += '(';
    for (int i = y; i < y + range; i += range / 2) {
        for(int j = x; j < x + range; j += range / 2)
            dfs(j, i, range / 2);
    }
    rtn += ')';
}


int main() {
    input();
    dfs(0, 0, N);
    cout << rtn;
}