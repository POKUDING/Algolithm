#include <bits/stdc++.h>

using namespace std;

bool possible(vector<int>& interval, int n, int size) {
    int lower = 0;
    for(int i = 0; i < interval.size(); ++i) {
        lower += interval[i];
        if(lower < size) {
            if(--n < 0)
                return false;
        } else 
            lower = 0;
    }
    return true;
}

int solution(int distance, vector<int> rocks, int n) {
    vector<int> interval;
    sort(rocks.begin(), rocks.end());
    int answer = 0;
    int max = distance;
    int min = 0;

    interval.push_back(rocks[0]);
    for(int i = 1; i < rocks.size(); ++i)
        interval.push_back(rocks[i] - rocks[i - 1]);
    interval.push_back(distance - rocks.back());
    while(min <= max) {
        int mid = (min + max) /2;
        if(possible(interval, n, mid)) {
            answer = mid;
            min = mid + 1;
        } else
            max = mid - 1;
    }
    return answer;
}