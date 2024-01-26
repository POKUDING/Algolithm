#include <bits/stdc++.h>

using namespace std;

bool check(int n, vector<int>& times, long long limit) {
    long long total = 0;
    for(int i = 0; i < times.size(); ++i) {
        total += limit / times[i];
        if (total >= n)
            return true;
    }
    return false;
}

long long solution(int n, vector<int> times) {
    long long answer = 0;
    sort(times.begin(), times.end());
    long long min = 1;
    long long max = n * (long long)times.front();
    
    while(min <= max) {
        long long mid = (min + max) / 2;
        if(check(n, times, mid)){
            answer = mid;
            max = mid - 1;            
        } else
            min = mid + 1;
    }
    return answer;
}