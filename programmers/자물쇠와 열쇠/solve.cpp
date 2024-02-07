#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> turn_key(vector<vector<int>>& key) {
    vector<vector<int>> rtn = vector<vector<int>>(key.size(),vector<int>(key.size(),0));
    for(int i = 0, len = key.size(); i < len; ++i)
        for(int j = 0; j < len; ++j)
            rtn[j][i] = key[i][len - 1 - j];
    return rtn;
}

bool check_key_lock_pos(int x, int y, vector<vector<int>>& cur_key, vector<vector<int>>& lock) {
    for(int i = 0, len = lock.size(), key_len = cur_key.size(); i < len; ++i) {
        for(int j = 0; j < len; ++j) {
            if(i >= y && j >= x && i - y < key_len && j - x < key_len) {
                if(lock[i][j] + cur_key[i - y][j - x] != 1)
                    return false;
            } else if (lock[i][j] != 1)
                return false;
        }
    }
    return true;
}

bool check_key_lock(vector<vector<int>>& cur_key, vector<vector<int>>& lock) {
    for(int len = lock.size(), i = -len; i < len; ++i) {
        for(int j = -len; j < len; ++j) {
            if(check_key_lock_pos(j,i,cur_key, lock))
                return true;
        }
    }
    return false;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    for(int i = 0; i < 4; ++i) {
        if(check_key_lock(key, lock))
            return true;
        key = turn_key(key);
    }
    return false;
}