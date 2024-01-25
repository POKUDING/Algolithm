#include<bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> answer;
    int l_i = INT_MAX, l_j =0;
    int r_i = 0, r_j = wallpaper.size();
    
    while (find(wallpaper[l_j].begin(), wallpaper[l_j].end(), '#') == wallpaper[l_j].end())
        ++l_j;
    for (int i = 0, index = string::npos; i < r_j; ++i)
    {
        index = wallpaper[i].find('#');
       if (index != string::npos)
            l_i = min(l_i, index);
    }
    while (find(wallpaper[r_j - 1].rbegin(), wallpaper[r_j - 1].rend(), '#') == wallpaper[r_j - 1].rend())
        --r_j;
    for (int i = r_j - 1, index = string::npos; i >= 0; --i)
    {
       index = wallpaper[i].rfind('#');
       if (index != string::npos)
            r_i = max(r_i, index + 1);
    }
    answer.push_back(l_j);
    answer.push_back(l_i);
    answer.push_back(r_j);
    answer.push_back(r_i);
    return answer;
}