#include <bits/stdc++.h>

using namespace std;

int N, P, M, L;
set<pair<int,int>> st; // 난이도, 문제번호
unordered_map<int,int> mp; // 문제번호, 난이도

void add() {
    int p, l;
    cin >> p >> l;
    st.insert({l,p});
    mp[p] = l;
}

void recommend() {
    int x;
    cin >> x;
    if (x == 1) {
        cout << (st.rbegin())->second;
    } else
        cout << (st.begin())->second;
    cout << "\n";
}

void solved() {
    int p;
    cin >> p;
    st.erase({mp[p], p});
    mp.erase(p);
}

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> N;
    for(int i = 0; i < N; ++i) {
        cin >> P >> L;
        st.insert({L, P});
        mp[P] = L;
    }
    cin >> M;
    string command;
    while(M-- > 0) {
        cin >> command;
        if(command == "recommend")
            recommend();
        else if (command == "add")
            add();
        else if (command == "solved")
            solved();
    }
}