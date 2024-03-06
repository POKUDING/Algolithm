#include <bits/stdc++.h>

using namespace std;

int N;

bool checkFastMonth(int m1, int d1, int m2, int d2) {
    if (m1 < m2 || (m1 == m2 && d1 < d2))
        return true;
    return false;
}

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> N;
    vector<vector<int>> vec(N,vector<int>(4));
    int ans = 1, m = 3, d = 1, em_tmp = 0, ed_tmp = 0;
    for(int i = 0; i < N; ++i)
        cin >> vec[i][0] >> vec[i][1] >> vec[i][2] >> vec[i][3];
    sort(vec.begin(), vec.end());
    for(int i = 0; i < vec.size(); ++i) {
        if(checkFastMonth(m, d, vec[i][0],vec[i][1])) {
            ++ans;
            m = em_tmp;
            d = ed_tmp;
        }
        if (checkFastMonth(em_tmp, ed_tmp,vec[i][2], vec[i][3])) {
            if(checkFastMonth(m ,d, vec[i][0], vec[i][1])) {
                cout << 0;
                return 0;
            }
            em_tmp = vec[i][2];
            ed_tmp = vec[i][3];
            if(checkFastMonth(11,30, em_tmp, ed_tmp)) {
                cout << ans;
                return 0;
            }
        }
    }
    cout << 0;
    return 0;
}