#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    map<int,vector<int> > road_map;
    vector<int> dist(n + 2, -1);
    queue<pair<int,int> > que;
    for(int i = 0; i < roads.size(); ++i){
        road_map[roads[i][0]].push_back(roads[i][1]);
        road_map[roads[i][1]].push_back(roads[i][0]);
    }
    que.push({destination, 0});
    while(!que.empty()){
        auto [ pos, cnt ] = que.front();
        if (dist[pos] == -1) {
            dist[pos] = cnt;
            for(int i = 0; i < road_map[pos].size(); ++i) {
                if (dist[road_map[pos][i]] == -1)
                    que.push({road_map[pos][i], cnt + 1});
            }
        }
        que.pop();
    }    
    for(int i = 0; i< sources.size(); ++i){
        answer.push_back(dist[sources[i]]);
    }
    return answer;
}