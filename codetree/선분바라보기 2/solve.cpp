#include <bits/stdc++.h>

using namespace std;

int N;

map<int,vector<pair<int,int>>> lines;

vector<vector<int>> getInput() {
    cin >> N;
    vector<vector<int>> rtn;
    for(int i = 0; i < N; ++i) {
        int y , x1, x2;
        cin >> y >> x1 >> x2;
        rtn.push_back({y, x1 ,x2});
    }
    return rtn;
}

bool sortFunc(vector<int> vec1, vector<int> vec2) {
    if(vec1[0] != vec2[0])
        return vec1[0] < vec2[0];
    return vec1[1] < vec2[1];
}

int main() {
    vector<vector<int>> input = getInput();
    sort(input.begin(), input.end(), sortFunc);
    int ans = 0;
    int cur_y = 0;
    // cout << "\n==================\n";
    
    for(int i = 0; i < N; ++i) {
        cur_y = input[i][0] - 1;
        for(int y = 1; y <= cur_y; ++y) {
            for(auto it = lines[y].begin(); it != lines[y].end(); ++it) {
                // cout << "===========start ====" << it->first << " "<<it->second << "\n";
                // cout <<input[i][0] << " " << input[i][1] << " " <<input [i][2] << "\n";
                if (input[i][1] >= it->first && input[i][1] <= it->second)
                    input[i][1] = it->second;
                // cout <<input[i][0] << " " << input[i][1] << " " <<input [i][2] << "\n";
                if (input[1][2] >= it->first && input[1][2] <it->second)
                    input[1][2] = it->first;
                // cout <<input[i][0] << " " << input[i][1] << " " <<input [i][2] << "\n";
                if (input[i][1] < it->first)
                    break;
            }
        }
        if (input[i][1] < input[i][2])
            lines[cur_y + 1].push_back({input[i][1], input[i][2]});
    }
    for(auto it = lines.begin(); it != lines.end(); ++it) {
        // cout << it->first << ": ";
        // for(auto vit = it->second.begin(); vit != it->second.end(); ++vit)
        //     cout << vit->first << " " <<vit->second <<", ";
        // cout <<"\n";
        ans+=it->second.size();
    }
    cout << ans;
}