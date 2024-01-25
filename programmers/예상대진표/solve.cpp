#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int solution(int n, int a, int b)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int answer = 0;
    while(a != b)
    {
        answer++;
        a = ceil((float)a/2);
        b = ceil((float)b/2);
    }
    return answer;
}