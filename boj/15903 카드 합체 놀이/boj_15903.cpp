#include <bits/stdc++.h>

using namespace std;

int n, m;
long long ans;

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> n >> m;
    priority_queue<long long> pq;
    long long tmp1, tmp2;
    for(int i = 0; i < n; ++i) {
        cin >> tmp1;
        pq.push(-tmp1);
    }
    for(int i = 0; i < m; ++i) {
        tmp1 = -pq.top();
        pq.pop();
        tmp2 = -pq.top();
        pq.pop();
        tmp1 += tmp2;
        pq.push(-tmp1);
        pq.push(-tmp1);
    }
    while(!pq.empty()) {
        ans -= pq.top();
        pq.pop();
    }
    cout << ans;
}