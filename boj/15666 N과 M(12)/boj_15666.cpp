#include <bits/stdc++.h>

using namespace std;

int N,M;

set<int> arr;

vector<vector<int>> rtn;
vector<int> tmp_arr;

void input() {
    cin >> N >> M;
    for(int i = 0; i < N; ++i){
        int tmp;
        cin >> tmp;
        arr.insert(tmp);
    }
}

void print() {
    for(int i = 0; i < rtn.size(); ++i) {
        for(int j = 0; j < rtn[i].size(); ++j)
            cout << rtn[i][j] <<" ";
        cout << "\n";
    }
}

void dfs(int n) {
    if(n == 0) {
        rtn.push_back(tmp_arr);
        return;
    }
    for(auto it = arr.begin(); it != arr.end(); ++it) {
        if(tmp_arr.empty() || *it >= tmp_arr.back()) {
            tmp_arr.push_back(*it);
            dfs(n - 1);
            tmp_arr.pop_back();
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    input();
    dfs(M);
    print();
}