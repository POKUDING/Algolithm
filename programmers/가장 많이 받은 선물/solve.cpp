#include <bits/stdc++.h>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    map<string,int> friend_num;
    int g[51][51] = {0};
    int point[51] = {0};
    vector<int> res(51,0);
    
    for(int i = 0; i < friends.size(); ++i)
        friend_num[friends[i]] = i;
    for(int i = 0; i < gifts.size(); ++i) {
        size_t pos = gifts[i].find(' ');
        int from_num = friend_num[gifts[i].substr(0, pos)];
        int to_num = friend_num[gifts[i].substr(pos + 1)];
        g[from_num][to_num]++;
        point[from_num]++;
        point[to_num]--;
    }
    for(int i = 0; i < friends.size() - 1; ++i) {
        for(int j = i + 1; j < friends.size(); ++j) {
            if(g[i][j] == g[j][i]) {
                if(point[i] == point[j])
                    continue ;
                else if(point[i] > point[j])
                    ++res[i];
                else
                    ++res[j];
            } else if(g[i][j] > g[j][i]) {
                ++res[i];
            } else
                ++res[j];
        }
    }
    return *max_element(res.begin(), res.end());
}