#include <bits/stdc++.h>

using namespace std;

int targetalp;
int targetcop;
int mincost;
int memo[151][151];

void dp(int alp, int cop, vector<vector<int>>& problems) {
    for (int i = 0; i < problems.size(); ++i) {
        if(!(problems[i][0] <= alp && problems[i][1] <= cop && (problems[i][2] > 0 || problems[i][3] > 0)))
            continue;
        int na = min(alp + problems[i][2], targetalp);
        int nc = min(cop + problems[i][3], targetcop);
        int ncost = memo[alp][cop] + problems[i][4];
        if((memo[na][nc] != -1 && memo[na][nc] < ncost))
            continue;
        memo[na][nc] = ncost;
    }
}

int solution(int alp, int cop, vector<vector<int>> problems) {
    int answer = 0;
    int len = problems.size();
    
    problems.push_back({0,0,0,1,1});
    problems.push_back({0,0,1,0,1});
    targetalp = alp;
    targetcop = cop;
    for(int i = 0; i < len; ++i) {
        targetalp = max(targetalp, problems[i][0]);
        targetcop = max(targetcop, problems[i][1]);
    }
    if(targetalp <= alp && targetcop <= cop)
        return 0;
    memset(memo, -1, sizeof memo);
    memo[alp][cop] = 0;
    for(int i = alp; i <= targetalp; ++i)
        for(int j = cop; j <= targetcop; ++j)
            dp(i,j, problems);
    return memo[targetalp][targetcop];
}