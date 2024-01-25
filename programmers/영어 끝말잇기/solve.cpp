#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    vector<string>  saw;
    vector<string>  dup;
    vector<string> tmp(words);
    vector<int> answer;
    
    sort(tmp.begin(), tmp.end());
    for(int i = 0, size = tmp.size() - 1; i < size; ++i)
    {
        if (tmp[i] == tmp[i + 1])
            dup.push_back(tmp[i]);
    }
    answer.push_back(0);
    answer.push_back(0);
    for(int i = 0, size = words.size(); i < size; ++i)
    {
        if (find(dup.begin(),dup.end(),words[i]) != dup.end()) {
            if (find(saw.begin(), saw.end(), words[i]) != saw.end())
            {
                answer[0] = i + 1;
                break;
            }
            saw.push_back(words[i]);
        }
        if (i + 1 < size && *(words[i].end() - 1) != words[i + 1][0])
        {
            answer[0] = i + 2;
            break;
        }
    }
    if (answer[0])
    {
        answer[1] = ((answer[0] - 1) / n + 1);
        answer[0] %= n;
        if (!answer[0])
            answer[0] = n;
    }
    return answer;
}