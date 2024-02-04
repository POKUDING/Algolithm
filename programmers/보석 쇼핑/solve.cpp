#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> gems) {
    pair<int,int> tmp = {-1, INT_MAX};
    map<string,int> Map;
    int cnt = 0;
    
    for(int i = 0; i < gems.size(); ++i)
        if(Map[gems[i]] == 0){
            ++Map[gems[i]];
            ++cnt;
        }
    for(int end = 0, start = 0; end < gems.size(); ++end) {
        if(--Map[gems[end]] >= 0)
            --cnt;
        while(cnt == 0) {
            if(tmp.second > end - start)
                tmp = {start, end - start};
            if(++Map[gems[start]] > 0)
                ++cnt;
            ++start;
        }
    }
    return {tmp.first + 1, tmp.first + tmp.second + 1};
}