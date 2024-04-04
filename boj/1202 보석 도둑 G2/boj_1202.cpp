#include <bits/stdc++.h>

using namespace std;

int N, K;
int m, v;
int c;

multiset<pair<int,int>> jewel;
multiset<int, greater<int>> candidate;
multiset<int> backpack;

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> N >> K;
    long long ans = 0;
    while(N--) {
        cin >> m >> v;
        jewel.insert(make_pair(m,v));
    }

    while(K--) {
        cin >> c;
        backpack.insert(c);
    }

    auto jewel_it = jewel.begin();
    for(auto it = backpack.begin(); it != backpack.end(); ++it) {
        while(jewel_it != jewel.end()) {
            if((*jewel_it).first > *it)
                break;
            candidate.insert(((*jewel_it).second));
            ++jewel_it;
        }

        if(!candidate.empty()) {
            ans += *(candidate.begin());
            candidate.erase(candidate.begin());
        }
    }
    cout << ans;
}