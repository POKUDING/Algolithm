#include <bits/stdc++.h>

using namespace std;

int max_time = 23 * 60 + 59;

int gettime(string& s) {
    return ((s[0] - '0') * 10 + s[1] - '0') * 60 + (s[3] -'0') * 10 + s[4] - '0';
}

int getcarnum(string& s) {
    return (s[6] - '0') * 1000 + (s[7] - '0') * 100 + (s[8] -'0') * 10 + s[9] - '0';
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    vector<pair<int,int>> car_fees;
    unordered_map<int,int> cars;
    for(int i = 0; i < records.size(); ++i) {
        int tmp_time = (max_time - gettime(records[i])) * (records[i][11] == 'I' ? 1 : -1);
        int tmp_carnum = getcarnum(records[i]);
        cars[tmp_carnum] += tmp_time;
    }
    for(auto it : cars) {
        int fee = fees[1];
        if(it.second > fees[0]) {
            fee += ((it.second - fees[0]) / fees[2]) * fees[3];
            fee += ((it.second - fees[0]) % fees[2] != 0 ? 1 : 0) * fees[3];
        }
        car_fees.push_back(make_pair(it.first, fee));
    }
    sort(car_fees.begin(), car_fees.end());
    for(int i = 0; i < car_fees.size(); ++i)
        answer.push_back(car_fees[i].second);
    return answer;
}