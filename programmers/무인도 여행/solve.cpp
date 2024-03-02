#include <bits/stdc++.h>

using namespace std;

int counter(vector<string>& maps, int x, int y) {
    if(x < 0 || y < 0 || x >= maps[0].size() || y >= maps.size() || maps[y][x] == 'X')
        return 0;
    int rtn = maps[y][x] - '0';
    maps[y][x] = 'X';
    rtn += counter(maps, x - 1, y);
    rtn += counter(maps, x + 1, y);
    rtn += counter(maps, x, y - 1);
    rtn += counter(maps, x, y + 1);
    return rtn;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    for(int i = 0; i < maps.size(); ++i)
        for(int j = 0; j < maps[i].size(); ++j)
            if(maps[i][j] != 'X')
                answer.push_back(counter(maps,j,i));
    if(answer.size() == 0)
        return {-1};
    sort(answer.begin(), answer.end());
    return answer;
}