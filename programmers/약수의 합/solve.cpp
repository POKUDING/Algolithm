#include <bits/stdc++.h>

using namespace std;

int solution(int n) {
    int answer = 0;
    for (int i = 1; i <= n / 2; ++i)
    {
        if (!(n % i))
            answer += i;
    }
    answer += n;
    return answer;
}