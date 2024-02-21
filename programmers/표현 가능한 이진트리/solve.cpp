#include <bits/stdc++.h>

using namespace std;

int find_size(string& s) {
    auto it = find(s.begin(),s.end(),'1');
    for(int i = 0, rtn = 0; i < 64; ++i) {
        rtn += pow(2,i);
        if(rtn >= s.end() - it)
            return rtn;
    }
    return 0;
}

int dfs(string& s, int size, int sidx) {
    if (size == 1)
        return s[sidx] - '0';
    size /= 2;
    int node1 = dfs(s, size, sidx);
    int node2 = dfs(s, size, sidx + size + 1);
    if (node1 < 0 || node2 < 0)
        return -1;
    if ((node1 > 0 || node2 > 0) && s[sidx + size] != '1')
        return -1;
    return s[sidx + size] - '0';
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    vector<string> bin;
    for(int i = 0; i < numbers.size(); ++i)
        bin.push_back(bitset<64>(numbers[i]).to_string());
    for(int i = 0; i < bin.size(); ++i) {
        int size = find_size(bin[i]);
        answer.push_back(1);
        if(dfs(bin[i], size, 64 - size) < 0)
            answer[i] -= 1;
    }
    return answer;
}