#include <bits/stdc++.h>

using namespace std;

int solution(vector<string> spell, vector<string> dic) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string spells;
    for(int i = 0, size = spell.size(); i < size; ++i)
        spells += spell[i];
    sort(spells.begin(),spells.end());
    for(int i = 0, size = dic.size(); i < size; ++i)
        sort(dic[i].begin(), dic[i].end());
    if (find(dic.begin(),dic.end(),spells) != dic.end())
            return 1;
    return 2;
}