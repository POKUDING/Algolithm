#include <bits/stdc++.h>

using namespace std;

void move(int from, int to, vector<vector<int>>& answer)
{
    vector<int> mv;

    mv.push_back(from);
    mv.push_back(to);
    answer.push_back(mv);
}

void hanoi(int n, int from, int to, int other, vector<vector<int>>& answer)
{
    if (n == 1)
    {       
        move(from, to, answer);
        return;
    }
    hanoi(n - 1, from, other, to, answer);
    move(from, to, answer);
    hanoi(n -1, other, to, from, answer);
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    hanoi(n, 1, 3, 2, answer);
    return answer;
}
