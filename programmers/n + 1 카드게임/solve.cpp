#include <bits/stdc++.h>

using namespace std;

bool check(vector<int>& card1, vector<int>& card2, int n) {
    for(int i = 0; i < card1.size(); ++i) {
        for (int j = 0; j < card2.size(); ++j) {
            if (card1[i] + card2[j] == n) {
                card1[i] = -1;
                card2[j] = -1;
                return true;
            }
        }
    }
    return false;
}

int solution(int coin, vector<int> cards) {
    int answer = 1;
    int n = cards.size();
    int idx = n / 3;
    vector<int> hands;
    vector<int> pending;
    
    for (int i = 0; i < idx; ++i)
        hands.push_back(cards[i]);
    while(idx <= n - 2) {
        pending.push_back(cards[idx++]);
        pending.push_back(cards[idx++]);
        if (check(hands, hands, n + 1))
            ;
        else if (check(hands, pending, n + 1) && coin > 0)
            coin -= 1;
        else if (check(pending, pending, n + 1) && coin > 1)
            coin -= 2;
        else break;
        ++answer;
    }
    return answer;
}