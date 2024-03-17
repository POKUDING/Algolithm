#include <bits/stdc++.h>

using namespace std;

int N;
long long M;

bool isPossible(vector<long long>& trees, long long height) {
    int e = trees.size() - 1;
    long long total = 0;
    while(e >= 0) {
        if(trees[e] <= height)
            return false;
        total += trees[e] - height;
        if(total >= M)
            return true;
        e--;
    }
    return false;
}

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> N >> M;
    vector<long long> trees(N);
    for(int i = 0; i < N; ++i)
        cin >> trees[i];
    sort(trees.begin(), trees.end());
    long long low = 0, high = 2000000000, mid;
    while(low < high) {
        mid = (low + high) / 2 + 1;
        if (isPossible(trees, mid))
            low = mid;
        else
            high = mid - 1;
    }
    cout << low;
}