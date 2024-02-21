#include <bits/stdc++.h>

using namespace std;

int N;

int main() {
    cin >> N;
    vector<pair<int,int>> vec(N);
    for(int i = 0; i < N; ++i)
        cin >> vec[i].first >> vec[i].second;
    sort(vec.begin(), vec.end());
    for(int i = 0; i < N; ++i)
        cout << vec[i].first << " " << vec[i].second << "\n";    
}