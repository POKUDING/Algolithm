#include <bits/stdc++.h>
#include <string>
#include <vector>

using namespace std;

long long solution(int k, int d) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long answer = 0;
    for(int y = 0; y <= d; y += k)
    {
        answer++;
        answer += (floor(sqrt(pow(d, 2) - pow(y, 2))) / k);
    }
    return answer;
}