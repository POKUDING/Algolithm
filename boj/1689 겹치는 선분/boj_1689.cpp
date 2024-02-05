#include <bits/stdc++.h>

using namespace std;

map<int,int> memo;
int N;

void input() {
    int start;
    int end;
    cin >> N;
    for(int i = 0; i < N; ++i) {
        cin >> start >> end;
        ++memo[start];
        --memo[end];
    }
}

int count() {
    int rtn = 0;
    int tmp = 0;

    for(auto it = memo.begin(); it != memo.end(); ++it){
        tmp += it->second;
        rtn = max(rtn, tmp);
    }
    return rtn;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    input();
    cout << count();
}