#include <bits/stdc++.h>

using namespace std;

string makestring(int n, int num) {
    string tmp = "0123456789ABCDEF";
    string rtn;
    rtn += tmp[num%n];
    while(num / n != 0) {
        num /= n;
        rtn += tmp[num%n];
    }
    reverse(rtn.begin(),rtn.end());
    return rtn;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    for(int i = 0,turn = 0; turn < t * m; ++i) {
        string tmp = makestring(n,i);
        for(int j = 0; j < tmp.size() && turn < t * m; ++j, ++turn) {
            if((turn) % m == p - 1)
                answer += tmp[j];
        }
    }
    return answer;
}