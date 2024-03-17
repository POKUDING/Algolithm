#include <bits/stdc++.h>

using namespace std;

int N, C;

bool isPossible(vector<long long>& house, long long len) {
    long long pre_house = house[0];
    int cnt = 1;
    for(int i = 1; i < N && N - i >= C - cnt; ++i) {
        if(house[i] - pre_house >= len) {
            ++cnt;
            pre_house = house[i];
        }
        if(cnt >= C)
            return true;
    }
    return false;
}

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> N >> C;
    vector<long long> house(N);
    for(int i = 0; i < N; ++i)
        cin >> house[i];
    sort(house.begin(), house.end());
    long long low = 0, high = 1000000000, mid;
    while(low < high) {
        mid = (low + high) / 2 + 1;
        if(isPossible(house,mid))
            low = mid;
        else
            high = mid - 1;
    }
    cout << low;
}