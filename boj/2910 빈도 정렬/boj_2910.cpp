#include <bits/stdc++.h>

using namespace std;

int N, C;

bool sortFunc(vector<int>& vec1, vector<int>& vec2) {
    if (vec1[0] != vec2[0])
        return vec1[0] > vec2[0];
    return vec1[1] < vec2[1];
}

int main() {
    cin >> N >> C;
    unordered_map<int,pair<int,int>> Map;
    vector<vector<int>> vec;
    for(int i = 0, num; i < N; ++i) {
        cin >> num;
        if(Map[num].first == 0)
            Map[num].second = i;
        ++Map[num].first;
    }
    for(auto it : Map)
        vec.push_back({it.second.first, it.second.second, it.first});
    sort(vec.begin(), vec.end(), sortFunc);
    for(int i = 0; i < vec.size(); ++i) {
        for(int j = 0; j < vec[i][0]; ++j)
            cout << vec[i][2] << " ";
    }
}