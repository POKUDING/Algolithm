#include <bits/stdc++.h>

using namespace std;

int n, k;
long long ans;

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> n >> k;
    vector<pair<int,int>> jewel(n);
    vector<int> backpack(k);
    priority_queue<int> pq;

    while(--n >= 0)
        cin >> jewel[n].first >> jewel[n].second;
    while(--k >= 0)
        cin >> backpack[k];

    sort(jewel.begin(), jewel.end());
    sort(backpack.begin(), backpack.end());

    for(int i = 0, j = 0; i < backpack.size(); ++i) {
        while(j < jewel.size()) {
            if(jewel[j].first > backpack[i]) break;
            pq.push(jewel[j++].second);
        }
        if(!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
    }
    cout << ans;
}