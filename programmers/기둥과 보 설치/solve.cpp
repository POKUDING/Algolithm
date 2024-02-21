#include <bits/stdc++.h>

using namespace std;

bool gridCol[101][101];
bool gridRow[101][101];
int N;

bool buildRow(int x, int y) {
    if (x - 1 >= 0 && gridRow[y][x - 1] == true && x + 1 <= N && gridRow[y][x + 1] == true)
        return true;
    if (gridCol[y - 1][x] == true || (x + 1 <= N && gridCol[y - 1][x + 1] == true))
        return true;
    return false;
}

bool buildCol(int x, int y) {
    if (y == 0 || gridCol[y - 1][x] == true || (x - 1 >= 0 && gridRow[y][x - 1] == true) || (gridRow[y][x] == true))
        return true;
    return false;
}
        
bool demolitionRow(int x, int y) {
    gridRow[y][x] = false;
    bool res = true;
    if(res && gridCol[y][x] == true)
        res = buildCol(x , y);
    if(res && x + 1 <= N && gridCol[y][x + 1])
        res = buildCol(x + 1, y);
    if(res && x - 1 >= 0 && gridRow[y][x - 1])
        res = buildRow(x - 1, y);
    if(res && x + 1 <= N && gridRow[y][x + 1])
        res = buildRow(x + 1, y);
    gridRow[y][x] = true;
    if(res)
        return true;
    return false;
}
        
bool demolitionCol(int x, int y) {
    gridCol[y][x] = false;
    bool res = true;
    if (res && x - 1 >= 0 && y + 1 <= N && gridRow[y + 1][x - 1])
        res = buildRow(x - 1, y + 1);
    if (res && y + 1 <= N && gridRow[y + 1][x])
        res = buildRow(x, y + 1);
    if (res && y + 1 <= N && gridCol[y + 1][x])
        res = buildCol(x, y + 1);
    gridCol[y][x] = true;
    if(res)
        return true;
    return false;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    memset(gridCol, false, sizeof gridCol);
    memset(gridRow, false, sizeof gridRow);
    N = n;
    for(int i = 0, len = build_frame.size(); i < len; ++i) {
        int x = build_frame[i][0];
        int y = build_frame[i][1];
        int rowcol = build_frame[i][2];
        if(build_frame[i][3] == 1) {
            if(rowcol == 0 && buildCol(x, y))
                gridCol[y][x] = true;
            else if (rowcol == 1 && buildRow(x, y))
                gridRow[y][x] = true;
        } else {
            if(rowcol == 0 && demolitionCol(x,y))
                gridCol[y][x] = false;
            else if (rowcol == 1 && demolitionRow(x, y))
                gridRow[y][x] = false;
        }
    }
    for(int i = 0; i <= N; ++i) {
        for(int j = 0; j <= N; ++j) {
            if(gridCol[j][i])
                answer.push_back({i, j, 0});
            if(gridRow[j][i])
                answer.push_back({i, j, 1});
        }
    }
    return answer;
}