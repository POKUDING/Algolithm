#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int> pq;
    for (int i = 0; i < scoville.size(); i++)
        pq.push(-scoville[i]);
    while (pq.size() > 1) {
        int first = -pq.top();
        if (first >= K)
            return answer;
        pq.pop();
        ++answer;
        int second = -pq.top() * 2;
        pq.pop();
        int ret = first+second;
        pq.push(-ret);
    }
    return -1;
}