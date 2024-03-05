#include <bits/stdc++.h>

using namespace std;

vector<long long> box;
int N,M;

bool checkWall(int dir) {
    if(dir == 0 && box[0] == 0)
        return true;
    if(dir == 1 && box[2] == M - 1)
        return true;
    if(dir == 2 && box[1] == 0)
        return true;
    if(dir == 3 && box[3] == N - 1)
        return true;
    return false;
}

void moveBack(int dir, long long dx) {
    if (dir == 0) {
      box[2] = box[2] + dx >= M ? M - 1 : box[2] + dx;
    } else if (dir == 1) {
        box[0] = box[0] - dx < 0 ? 0 : box[0] - dx;
    } else if (dir == 2) {
        box[3] = box[3] + dx >= N ? N - 1: box[3] + dx;
    } else if (dir == 3) {
        box[1] = box[1] - dx < 0 ? 0 : box[1] - dx;
    }
}

void moveFront(int dir, long long dx) {
    if (dir == 0) {
        box[0] = box[0] + dx >= M ? -1 : box[0] + dx;
    } else if (dir == 1) {
        box[2] = box[2] - dx < 0 ? -1 : box[2] - dx;
    } else if (dir == 2) {
        box[1] = box[1] + dx >= N ? -1: box[1] + dx;
    } else if (dir == 3) {
        box[3] = box[3] - dx < 0 ? -1 : box[3] - dx;
    }
}

long long solution(int n, int m, int x, int y, vector<vector<int>> queries) {
    N = n;
    M = m;
    box = {y,x,y,x};
    for(int i = queries.size() - 1; i >= 0; --i) {
        if(!checkWall(queries[i][0]))
            moveFront(queries[i][0],queries[i][1]);
        moveBack(queries[i][0],queries[i][1]);
        if(box[0] == -1 || box[1] == -1 || box[2] == -1 || box[3] == -1 || \
           box[0] > box[2] || box[1] > box[3])
            return 0;
    }
    return (box[2] - box[0] + 1) * (box[3] - box[1] + 1);
}