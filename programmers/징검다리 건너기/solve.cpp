#include <bits/stdc++.h>

using namespace std;

bool canGo(vector<int>& stones,int size, int k, int n) {
    for(int i = 0; i < size; ++i) {
        int cnt = 1;
        while (i < size && stones[i] < n) {
            ++cnt;
            ++i;
        }
        if (cnt > k)
            return false;
    }
    return true;
}

int solution(vector<int> stones, int k) {
    int answer = 0;
    int size = stones.size();
    int min = 0, max = 200000000;
    int mid;
    while(min < max) {
        int mid = (min + max) / 2 + 1;
        if(canGo(stones,size,k,mid)) {
            answer = mid;
            min = mid;
        } else
            max = mid - 1;
    }
    return answer;
}