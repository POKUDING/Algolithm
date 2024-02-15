#include<bits/stdc++.h>

using namespace std;

long long K,N;
long long lans[10002] = {0};

void input() {
    cin >> K >> N;
    for(long long i = 0; i < K; ++i)
        cin >> lans[i];
}

bool canMake(long long n) {
    long long total = 0;
    if(n <= 0)
        return false;
    for(long long i = 0; i < K; ++i){
     total += (lans[i] / n);
    }
    return total >= N;
}

int main() {
    memset(lans, 0, sizeof lans);
    input();
    
    long long ans = 1;
    long long min = 1;
    long long max = INT_MAX;
    while(min < max) {
        long long mid = (max + min) / 2 + 1;
        if(canMake(mid)) {
            ans = mid;
            min = mid;
        } else
            max = mid - 1;
    }
    cout << ans;
    return 0;
}