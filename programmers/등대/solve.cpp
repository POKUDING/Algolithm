#include <bits/stdc++.h>

using namespace std;

int ans;

bool lighton(int curr, int prev, vector<vector<int>>& roads) {
    bool rtn = false;
    if(curr != 1 && roads[curr].size() == 1)
        return false;
    for(int i = 0; i < roads[curr].size(); ++i) {
        if(roads[curr][i] == prev)
            continue;
        if(!lighton(roads[curr][i], curr, roads))
            rtn = true;
    }
    if(rtn)
        ++ans;
    return rtn;
}

int solution(int n, vector<vector<int>> lighthouse) {
    vector<vector<int>> roads(n + 1);
    for(int i = 0; i < lighthouse.size(); ++i) {
        roads[lighthouse[i][0]].push_back(lighthouse[i][1]);
        roads[lighthouse[i][1]].push_back(lighthouse[i][0]);
    }
    lighton(1,0,roads);
    return ans;
}