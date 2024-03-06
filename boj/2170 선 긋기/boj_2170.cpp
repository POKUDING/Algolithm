#include <bits/stdc++.h>

using namespace std;

long long N;

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    long long end;
    long long ans = 0;
    cin >> N;
    vector<pair<long long,long long>> vec(N);

    for(int i = 0; i < N; ++i)
        cin >> vec[i].first >> vec[i].second;
    sort(vec.begin(), vec.end());
    ans = vec[0].second - vec[0].first;
    end = vec[0].second;
    for(int i = 1; i < N; ++i) {
        if (vec[i].second <= end) // 길이가 더 짧은 선을 그을 경우를 고려하지 않아서 틀렸었음..
            continue;
        if (vec[i].first > end)
            ans += vec[i].second - vec[i].first;
        else
            ans += vec[i].second - end;
        end = vec[i].second;
    }
    cout << ans;
}