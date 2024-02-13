#include <bits/stdc++.h>

using namespace std;

int N;
int dir[4] = {1, 0, -1 ,0};
int Map[20][20];
vector<int> student_input;
unordered_map<int,vector<int>> inputs;

void input() {
    cin >> N;
    for(int i = 0; i < N * N; ++i) {
        int student, friends;
        cin >> student;
        student_input.push_back(student);
        for(int j = 0; j < 4; ++j) {
            cin >> friends;
            inputs[student].push_back(friends);
        }
    }
}

int checkCross(int x, int y, vector<int> friends) {
    int next_x, next_y;
    int rtn  = 0;
    for(int i = 0; i < 4; ++i){
        next_x = x + dir[i];
        next_y = y + dir[(i + 1) % 4];
        if(next_x < 0 || next_y < 0 || next_x >= N || next_y >= N)
            continue ;
        if(find(friends.begin(), friends.end(), Map[next_y][next_x]) != friends.end())
            ++rtn;
    }
    return rtn;
}

void sitStudent(int student, vector<int>& friends) {
    int max_frineds = -1;
    int max_empty = -1;
    pair<int,int> pos;
    for(int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            if (Map[y][x] != 0)
                continue ;
            int tmp_frineds = checkCross(x, y, friends);
            int tmp_empty = checkCross(x, y , {0});
            if ((tmp_frineds > max_frineds) || \
                (tmp_frineds == max_frineds && tmp_empty > max_empty)) {
                max_frineds = tmp_frineds;
                max_empty = tmp_empty;
                pos = {x, y};
            }
        }
    }
    Map[pos.second][pos.first] = student;
}

void sitStudents() {
    for(auto it = student_input.begin(); it != student_input.end(); ++it) {
        sitStudent(*it, inputs[*it]);
    }
}

int checkSatisfaction() {
    int satisfacion = 0;
    for(int y = 0; y < N; ++y){
        for(int x = 0; x < N; ++x) {
            int cnt_friends = checkCross(x, y, inputs[Map[y][x]]);
            if(cnt_friends)
                satisfacion += pow(10, cnt_friends - 1);
        }
    }
    return satisfacion;
}

int main() {
    memset(Map, 0, sizeof Map);
    input();
    sitStudents();
    cout << checkSatisfaction();
}