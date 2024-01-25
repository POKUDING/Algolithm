#include <bits/stdc++.h>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> answer;
    int div = s / n;
    int mod = n - s % n;
    if (n > s)
    {
        answer.push_back(-1);
        return answer;
    }
    for (int i = 0; i < mod; ++i)
        answer.push_back(div);
    ++div;
    for (int i = mod; i < n; ++i)
        answer.push_back(div);
    // for (int i = answer.size() - 1; mod > 0; --i, --mod)
    //     answer[i] += 1;
    return answer;
}