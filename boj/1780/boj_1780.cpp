#include <bits/stdc++.h>

using namespace std;

int N;
map<int,int> rtn;
int paper[2200][2200];

void    input() {
    cin >> N;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j)
            cin>> paper[i][j];
    }
}

bool   check_num(int x,int y, int range) {
    for(int i = y; i < y + range; ++i) {
        for(int j = x; j < x + range; ++j) {
            if(paper[y][x] != paper[i][j])
                return false;
        }
    }
    ++rtn[paper[y][x]];
    return true;
}

void count_paper(int x, int y, int range) {
    if(check_num(x,y,range))
        return ;
    for(int i = y; i < y + range; i+= (range / 3)) {
        for(int j = x; j < x + range; j+= (range/ 3)) {
                count_paper(j,i,range/3);
        }
    }
}

int main () {
    input();
    count_paper(0,0,N);
    cout<<rtn[-1] <<"\n" << rtn[0] << "\n" <<rtn[1];
}