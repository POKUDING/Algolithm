#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int> > land)
{
    vector<vector<int> > dp(land.size(),vector<int>(land[0].size(), 0));
    int answer = 0;

    dp[0] = land[0];
    for(int i = 1, size = land.size(); i < size; ++i)
    {
        for(int j = 0; j < 4; ++j)
        {
            dp[i][j] = max({dp[i - 1][(j + 1) % 4], dp[i - 1][(j + 2) % 4], dp[i - 1][(j + 3) % 4]}) + land[i][j];
        }
    }
    answer = max({dp.back()[0], dp.back()[1], dp.back()[2], dp.back()[3]});
    
    
    cout << "Hello Cpp" << endl;

    return answer;
}