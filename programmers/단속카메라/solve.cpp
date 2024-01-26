#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1;
    map<int,int> car;
    int minend = INT_MAX;
    for(int i = 0; i < routes.size(); ++i) {
        car[routes[i][0]] = routes[i][1];
    }
    for(auto i = car.begin(); i != car.end(); ++i) {
        if(i->first > minend) {
            ++answer;
            minend = INT_MAX;
        }
        minend = min(minend, i->second);
    }
    return answer;
}