#include <bits/stdc++.h>

using namespace std;

int N;
vector<pair<int,int>> ans;

void hanoi(int n,int from, int to, int other) {

    if(n == 1) {
        ans.push_back({from, to});
        return;
    }
    hanoi(n - 1, from, other, to);
    ans.push_back({from, to});
    hanoi(n - 1, other, to, from);
}

int main() {
    cin >> N;
    hanoi(N,1,3,2);
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i].first << " " << ans[i].second << "\n";
    }
}