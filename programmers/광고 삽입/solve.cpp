#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int stot(string tm){
    int hr = stoi(tm.substr(0, 2));
    int mn = stoi(tm.substr(3, 2));
    int sc = stoi(tm.substr(6, 2));
    return hr * 3600 + mn * 60 + sc;
}

string ttos(int tm){
    string hr = to_string(tm / 3600);
    if(hr.length() == 1) hr = "0" + hr;
    tm %= 3600;
    string mn = to_string(tm / 60);
    if(mn.length() == 1) mn = "0" + mn;
    tm %= 60;
    string sc = to_string(tm);
    if(sc.length() == 1) sc = "0" + sc;
    return hr + ':' + mn + ':' + sc;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    int mx = stot(play_time);
    vector<ll> v(mx+1);
    for(auto& log: logs){
        int st = stot(log.substr(0, 8));
        int en = stot(log.substr(9, 8));
        v[st]++; v[en]--;
    }
    for(int i=1; i<=mx; i++) v[i] += v[i-1];
    for(int i=1; i<=mx; i++) v[i] += v[i-1];
    int at = stot(adv_time);
    ll res = -1;
    int j = -1;
    for(int i=0; i+at-1<=mx; i++){
        ll cnt = v[i+at-1] - (i ? v[i-1] : 0);
        if(cnt <= res) continue;
        res = cnt;
        j = i;
    }
    assert(res > 0 && j >= 0);
    return ttos(j);
}