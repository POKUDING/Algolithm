#include <bits/stdc++.h>

using namespace std;

int N, Q, pos, tmp;

set<int> st;

void query1() {
    cin >> tmp;
    if(st.end() ==st.find(tmp))
        st.insert(tmp);
    else
        st.erase(tmp);
}

void query2() {
    cin >> tmp;
    pos = (pos + tmp) % N;
}

void query3(){
    if(st.empty())
        cout << -1;
    else {
        auto it = st.lower_bound(pos + 1);
        if(it != st.end())
            cout << *it - (pos + 1);
        else {
            cout << *(st.begin()) + (N - (pos + 1));
        }
    }
    cout << "\n";
}

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> N >> Q;
    for(int i = 1; i <= N; ++i) {
        cin >> tmp;
        if(tmp == 1)
            st.insert(i);
    }
    while(Q-- > 0) {
        cin >> tmp;
        switch(tmp) {
            case 1: query1(); break;
            case 2: query2(); break;
            case 3: query3(); break;
            default: break;
        }
    }
}