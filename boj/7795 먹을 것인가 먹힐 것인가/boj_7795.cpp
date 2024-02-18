#include <bits/stdc++.h>

using namespace std;

int T, N ,M;

int counter(vector<int>& vec1, vector<int>& vec2) {
    int rtn = 0;
    sort(vec1.begin(), vec1.end());
    sort(vec2.begin(), vec2.end());
    auto it = vec1.begin();
    for(int i = 0; i < M; ++i) {
        it = upper_bound(it, vec1.end(), vec2[i]);
        rtn += vec1.end() - it;
    }
    return rtn;
}

int main() {
    cin >> T;
    for(int i = 0; i < T; ++i) {
        cin >> N >> M;
        vector<int> vec1(N);
        vector<int> vec2(M);
        for(int j = 0; j < N; ++j)
            cin >> vec1[j];
        for(int j = 0; j < M; ++j)
            cin >> vec2[j];
        cout << counter(vec1, vec2) << "\n";
    }
}