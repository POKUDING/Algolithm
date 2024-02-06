#include <bits/stdc++.h>

using namespace std;

int arr[10];
bool used[10] = {false};

int N, M;

void input() {
    cin >> N >> M;
}

void print() {
    for(int i = 0; i < M; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

void dfs(int n) {
    if (n == 0)
        print();
    for(int i = 1; i <= N; ++i){
        if(used[i] == 1)
            continue;
        used[i] = true;
        arr[M - n] = i;
        dfs(n - 1);
        used[i] = false;
    }
}

int main() {
    input();
    dfs(M);
}