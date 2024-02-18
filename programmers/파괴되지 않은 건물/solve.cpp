#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int r_size = board.size();
    int l_size = board[0].size();
    int answer = 0;

    vector<vector<int>> memo(r_size + 1, vector<int>(l_size + 1, 0));
    for(int i = 0; i < skill.size(); ++i) {
        int degree = skill[i][5];
        if(skill[i][0] == 1)
            degree *= -1;
        memo[skill[i][1]][skill[i][2]] += degree;
        memo[skill[i][1]][skill[i][4] + 1] -= degree;
        memo[skill[i][3] + 1][skill[i][2]] -= degree;
        memo[skill[i][3] + 1][skill[i][4] + 1] += degree;
    }
    for(int i = 0; i < r_size; ++i) {
        int change = 0;
        for(int j = 0; j < l_size; ++j) {
            change += memo[i][j];
            memo[i][j] = change;
            memo[i][j] += i - 1 < 0 ? 0 : memo[i - 1][j];
            board[i][j] += memo[i][j];
            if (board[i][j] > 0)
                ++answer;
        }
    }
    return answer;
}