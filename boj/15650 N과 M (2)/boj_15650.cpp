#include <bits/stdc++.h>

using namespace std;

int tmp [8];

int N,M;

void print() {
    for(int i = 0; i < M; ++i) {
        cout << tmp[i] << " ";
    }
    cout <<"\n";
}

void rec(int n, int d) {
    if (d == M) {
        print();
        return ;
    }
    for(int i = n; i <= N - (M - 1 - d); ++i) {
        tmp[d] = i;
        rec(i + 1, d + 1);
    }
}

int main () {
    cin >> N >> M;
    rec(1,0);
}