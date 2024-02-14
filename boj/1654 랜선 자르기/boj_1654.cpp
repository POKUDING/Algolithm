#include<bits/stdc++.h>

using namespace std;

int K,N;
int lans[10001] = {0};

void input() {
    cin >> K >> N;
    for(int i = 0; i < K; ++i)
        cin >> lans[i];
}

bool canMake(int n) {
    int total = 0;
    for(int i = 0; i < K; ++i)
     total += (lans[i] / n);
    return total >= N;
}

int main() {
    input();
    int ans = 0;
    int min = 0;
    int max = INT_MAX - 1;
    while(min <= max) {
        int mid = (max + min) / 2;
        if(canMake(mid)) {
            ans = mid;
            cout << ans << "\n";
            min = mid + 1;
        } else
            max = mid - 1;
    }
    cout << ans;
    return 0;
}