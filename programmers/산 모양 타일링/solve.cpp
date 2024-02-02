#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<int> tops) {
    int can = 1, cannot = 0;

    for(int i = 0,j = -1, len = 2 * n; i <= len; ++i,can%=10007) {
        if(i % 2 == 1 && tops[++j] == 1)
            cannot += can;
        can += cannot;
        cannot = can - cannot;
    }
    return can;
}
