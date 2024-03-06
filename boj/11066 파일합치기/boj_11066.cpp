#include <bits/stdc++.h>

using namespace std;

int T, K, tmp;

int main() {
    priority_queue<int> pq;
    cin >> T;
    while(T--) {
        cin >> K;
        for(int i = 0; i < K; ++i) {
            cin >> tmp;
            pq.push(-tmp);
        }
        while(pq.size() > 1) {
            tmp = pq.top();
            pq.pop();
            tmp += pq.top();
            pq.pop();
            pq.push(tmp);
        }
        cout << -pq.top() << "\n";
        pq.pop();
    }
}