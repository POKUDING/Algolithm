#include <bits/stdc++.h>

using namespace std;

int N;

char Map[3500][7000];

void printStar(int x, int y) {
    Map[y][x] = '*';
    Map[y + 1][x - 1] = '*';
    Map[y + 1][x + 1] = '*';
    for(int i = 0; i < 5; ++i)
        Map[y + 2][x - 2 + i] = '*';
}

void checkStar(int x, int y, int n) {
    if (n == 3) {
        printStar(x, y);
        return;
    }
    n /= 2;
    checkStar(x, y, n);
    checkStar(x - n, y + n, n);
    checkStar(x + n, y + n, n);
}

int main() {
    memset(Map, ' ', sizeof Map);
    cin >> N;
    checkStar(N, 0, N);
    for(int i = 0; i < N; ++i) {
        for(int j = 1; j < 2 * N; ++j)
            cout <<Map[i][j];
        cout <<"\n";
    }
}