#include <bits/stdc++.h>

using namespace std;

map<int,int> Y;
map<int,int> D1;
map<int,int> D2;

int N;

int dfs(int n) {
    int rtn = 0;
    if(n == 0)
        return 1;
    for(int i = 1; i <= N; ++i) {
        if(Y[i] == 0 && D1[n - i] == 0 && D2[n + i] == 0) {
            Y[i] = 1;
            D1[n - i] = 1;
            D2[n + i] = 1;
            rtn += dfs(n - 1);
            Y[i] = 0;
            D1[n - i] = 0;
            D2[n + i] = 0;
        }
    }
    return rtn;
}

int main() {
    cin >> N;
    map<int,int> tmp1;
    map<int,int> tmp2;
    

    cout << dfs(N);
}