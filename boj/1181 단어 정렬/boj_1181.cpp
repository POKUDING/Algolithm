#include <bits/stdc++.h>

using namespace std;

int N;

int sortFunc(string& s1, string& s2) {
    if (s1.size() != s2.size())
        return s1.size() < s2.size();
    return strcmp(s1.c_str(),s2.c_str()) < 0;
}

int main() {
    cin >> N;
    vector<string> vec(N);
    for(int i = 0; i < N; ++i)
        cin >> vec[i];
    sort(vec.begin(), vec.end(), sortFunc);
    for(int i = 0; i < N; ++i) {
        if(vec[i] == vec[i + 1]) continue ;
        cout << vec[i] << "\n";
    }
    return 0;
}