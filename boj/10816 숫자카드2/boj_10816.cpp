#include <bits/stdc++.h>

using namespace std;

int N, M;

int binary_search(vector<int>& ncard, int card) {
    int low = 0, high = ncard.size() - 1;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(ncard[mid] < card)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> N;
    vector<int> ncard(N);
    for(int i = 0; i < N; ++i)
        cin >> ncard[i];
    sort(ncard.begin(), ncard.end());
    cin >> M;
    vector<int> mcard(M);
    for(int i = 0; i < M; ++i) {
        int tmp_num;
        cin >> tmp_num;
        cout << binary_search(ncard, tmp_num +1) - binary_search(ncard, tmp_num) << " ";
    }

}