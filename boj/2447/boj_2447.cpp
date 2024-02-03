#include <bits/stdc++.h>

using namespace std;

int N;
char Map[6561][6561];

void dfs(int x, int y, int range) {
    if (range == 1) {
        Map[y][x] = '*';
        return;
    }
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j)
            if(!(i == 1 && j == 1)) dfs(x + j * range / 3, y + i * range / 3, range /3); 
    }
}

int main() {
    memset(Map, ' ', sizeof Map);
    cin >> N;
    dfs(0,0, N);
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j <N; ++j)
            cout << Map[i][j];
        cout << "\n";
    }
}