#include <bits/stdc++.h>

using namespace std;

int solution(std::vector<int> a) {
    int len = a.size();
    vector<int> last_idx(len, -1);
    vector<int> cnt(len, 0);
    for(int i = 0 ; i < len; ++i) {
        ++cnt[a[i]];
        if(last_idx[a[i]] < i - 1)
            last_idx[a[i]] = i;
        else if (i + 1 < len && a[i + 1] != a[i])
            last_idx[a[i]] = i + 1;
        else {
            --cnt[a[i]];
            last_idx[a[i]] = i;
        }
    }
    // for(int i = 0; i < len; ++i) {
    //     cout << "i : " << i << "\n";
    //     cout << "last_idx: " << last_idx[i] << "\n";
    //     cout << "cnt : " << cnt[i] << "\n\n";
    // }
    sort(cnt.begin(), cnt.end());
    return cnt.back() * 2;
}