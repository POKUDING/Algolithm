#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    for(int i = 0, j = 0; i < B.size(); ++i) {
        if(A[j] - B[i] < 0) {
            ++answer;
            ++j;
        }
    }
    return answer;
}