#include <bits/stdc++.h>

using namespace std;

int N;
long long M;

bool isPossible(vector<int>& vec, long long max) {
    long long total = 0;
    for(int i = 0, e = vec.size(); i < e; ++i) {
        if(vec[i] < max)
            total += vec[i];
        else {
            total += max * (e - i);
            break;
        }
    }
    return total <= M;
}

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> N;
    vector<int> vec(N);
    for(int i = 0; i < N; ++i)
        cin >> vec[i];
    cin >> M;
    sort(vec.begin(),vec.end());
    long long low = 0, high = 1000000000, mid;
    while(low < high) {
        mid = (low + high) / 2 + 1;
        if(isPossible(vec,mid))
            low = mid;
        else
            high = mid - 1;
    }
    if(low > vec.back())
        low = vec.back();
    cout << low;
}