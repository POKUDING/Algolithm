#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> primes;

void makePrimes() {
    vector<bool> is_prime(N + 1, true);
    for(int i = 2; i * i <= N; ++i) {
        if(!is_prime[i]) continue;
        for(int j = i * i; j <= N; j += i)
            is_prime[j] = false;
    }
    for(int i = 2; i <= N; ++i)
        if(is_prime[i])
            primes.push_back(i);
}

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int sum = 0, ans = 0;
    cin >> N;
    makePrimes();
    for(int s = 0, e = 0; e < primes.size(); ++e) {
        sum += primes[e];
        while(sum > N)
            sum -= primes[s++];
        if(sum == N)
            ++ans;
    }
    cout << ans;
}