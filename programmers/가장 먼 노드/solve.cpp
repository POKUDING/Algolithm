#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    int max_len = 1;
    vector<vector<int>> memo(n + 1, vector<int>(n + 1));
    queue<tuple<int,int>> que;
    
    for(int i = 0; i < edge.size(); ++i) {
        ++memo[edge[i][0]][edge[i][1]];
        ++memo[edge[i][1]][edge[i][0]];
        if(edge[i][0] == 1)
            que.push(make_tuple(edge[i][1], 1));
        else if (edge[i][1] == 1)
            que.push(make_tuple(edge[i][0], 1));
    }
    
    while (!que.empty()) {
        auto [cn, cl] = que.front();
        if(cl == max_len)
            ++answer;
        else if (cl > max_len) {
            max_len = cl;
            answer = 1;
        }
        for(int i = 2; i < memo[cn].size(); ++i) {
            if(memo[cn][i] == 0)
                continue;
            if(memo[1][i] == 1)
                continue;
            memo[1][i] = 1;
            que.push(make_tuple(i, cl + 1));
        }
        que.pop();
    }



    return answer;
}