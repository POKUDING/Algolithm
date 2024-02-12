#include <bits/stdc++.h>

using namespace std;

int maxscore = INT_MIN;
int peachscore = 0;
vector<int> answer;

void dfs(int left, int target, vector<int>&info,vector<int>& ans, int score) {
    if(target  < 0) {
        if(score - peachscore > maxscore) {
            maxscore = score - peachscore;
            answer = ans;
            reverse(answer.begin(),answer.end());
            answer.push_back(left);
        }
        return ;
    }
    if(left > info[target]) {
        ans.push_back(info[target] + 1);
        if(info[target] != 0)
            peachscore -= (10 - target);
        dfs(left - (info[target] + 1), target - 1, info, ans, score + (10 - target));
        ans.pop_back();
        if(info[target] != 0)
           peachscore += (10 - target);
    }
    ans.push_back(0);
    dfs(left, target - 1, info, ans, score);
    ans.pop_back();
}

vector<int> solution(int n, vector<int> info) {
    vector<int> ans;
    for(int i = 0; i < info.size(); ++i) {
        if(info[i] != 0)
            peachscore += 10 - i;
    }
    dfs(n, 9, info, ans, 0);
    if(maxscore <= 0)
        return {-1};
    return answer;
}