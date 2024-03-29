#include <bits/stdc++.h>

using namespace std;

int N, M;
int p, l, g, x;

set<tuple<int,int,int>> st;
unordered_map<int,pair<int,int>> mp;

void recommend() {
    cin >> g >> x;
    if(x == 1) {
        for(auto it = st.rbegin(); it != st.rend(); ++it) {
            if (get<2>(*it) == g) {
                cout << get<1>(*it);
                break ;
            }
        }
    } else {
        for(auto it = st.begin(); it != st.end(); ++it) {
            if(get<2>(*it) == g) {
                cout << get<1>(*it);
                break;
            }
        }
    }
    cout << "\n";
}

void recommend2() {
    cin >> x;
    if(x == 1) {
        cout << get<1>(*st.rbegin());
    } else
        cout << get<1>(*st.begin());
    cout << "\n";
}

void recommend3() {
    cin >> x >> l;
    if(st.empty())
        cout << -1;
    else if(x == 1) {
        auto it = st.lower_bound(make_tuple(l, 0, 0));
        if(it == st.end())
            cout << -1;
        else 
            cout << get<1>(*it);
    } else {
        auto it = st.lower_bound(make_tuple(l, 0 ,0));
        if(it == st.begin())
            cout << -1;
        else
            cout << get<1>(*(--it));
    }
    cout <<"\n";
}

void add() {
    cin >> p >> l >> g;
    st.insert(make_tuple(l, p ,g));
    mp[p] = make_pair(l, g);
}

void solved() {
    cin >> p;
    st.erase(make_tuple(mp[p].first, p, mp[p].second));
}

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> N;
    for(int i = 0; i < N; ++i) {
        cin >> p >> l >> g;
        st.insert(make_tuple(l,p,g));
        mp[p] = make_pair(l, g);
    }
    cin >> M;
    string command;
    while(M-- > 0) {
        cin >> command;
        if(command == "recommend")
            recommend();
        else if (command == "recommend2")
            recommend2();
        else if (command == "recommend3")
            recommend3();
        else if (command == "add")
            add();
        else if (command == "solved")
            solved();
    }
}