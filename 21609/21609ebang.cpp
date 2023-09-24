#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <algorithm>
#include <map>
#include <stack>
#include <cstring>
#include <sstream>
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);
#define all(v) v.begin(), v.end()
#define NONE -1
#define EMPTY ' '
#define INF 2147483647
long long ans = 0;

using namespace std;
int N, M;
long long board[30][30];
long long visited[30][30] = {0,};
long long rainbowvisit[30][30] = {0,};
/*

검은색 : -1 무지개: 0, 일반 
일반: M가지 색상. (1~M)

블록그룹: 연결된 블록의 집합 - 
    일반 볼록 하나 이상 , 같은 색깔들
    무지개 블록 == 조커
    검은색블록 == 벽
    2이상의 블록들로 구성

    -> 블록 2개 이상의 같은 색집합.
    -> 검은색은 벽이나 다름없고 무지개는 아무거나 가능.

    -> 기준 블록 : 행 -> 열 순으로 작은 블록. 
    
블록 그룹 선정 기준
    1. 크기가 가장 큰. 
    2. 무지개 블록 수가 많은.
    3. 행과 열 기준으로 업데이트 계속. 

    -> 모두 제거한다. 그리고 개수의 제곱만큼의 점수를 획득.
    -> 중력 작용 : 하나씩 그 다음 아래로 내려갈 수 있을 때까지 내려간다.
    -> 반시계 회전
    -> 그리고 중력. 


- 반시계 회전 구현방안 (N^2)
    [1, N] -> [1,0]
    [1, 1] -> [1, N]
    [N, 1] -> [N, N]
    [N, N] -> [1, N]


*/

struct blockInfo{
    int size;
    int rainbow;
};

void initVisited(){
    for(int i = 1; i <= N; i++){
        for(int j = 1 ;j <= N; j++){
            visited[i][j] = 0;
        }
    }
}

bool Cango(int r, int c){
    return (1 <= r && r <= N && 1 <= c && c <= N && (board[r][c] != -1));
}

void check(){
    cout << "check \n";
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(board[i][j] == EMPTY )
                cout << ".  " ;
            else if (board[i][j] >= 0)
                cout << board[i][j] << "  ";
			else
                cout << board[i][j] << " ";

    }
    cout << "\n";
    }
}

blockInfo BFS(int r, int c, bool remove){
    int dir[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    for(int i = 1; i <= N; i++){
        for(int j =1; j <= N; j++){
            rainbowvisit[i][j] = 0;
        }
    }
    queue<pair<int, int> > Q;
    int blockSize = 0, rainbow = 0;
    int color = board[r][c];
    Q.push(make_pair(r,c));
    
    while(!Q.empty()){
        int curR = Q.front().first;
        int curC = Q.front().second;
        blockSize++;
        
        Q.pop();
        // cout << "visit " << curR << " " </< curC << "\n";
        for(int i = 0; i < 4; i++){
            int nextR = curR + dir[i][0];
            int nextC = curC + dir[i][1];

            //색깔이 같고 벽이 아니고 방문전일때.
            if (Cango(nextR, nextC) && (visited[nextR][nextC] == 0 && board[nextR][nextC] == color || board[nextR][nextC] == 0 && rainbowvisit[nextR][nextC] == 0)) {
                visited[nextR][nextC] = 1;
                if (board[nextR][nextC] == 0){
                    rainbow++;
                    rainbowvisit[nextR][nextC] = 1;
                }
                Q.push(make_pair(nextR,nextC));
            }
        }
        if(remove)
            board[curR][curC] = EMPTY;
    }
    blockInfo ret = {blockSize, rainbow};
    // cout << ret.size << " " << rainbow << "\n";
    return ret;
}

bool findBiggestBlockGroupAndGetScore(){
    initVisited();
    // cout << "function called\n";
    blockInfo block;
    int maxBlock = -1, maxRainbow = -1, maxR, maxC;
    for(int i = 1; i <= N; i++){
        for(int j = 1 ;j <= N; j++){
            if(visited[i][j] ==  0 && board[i][j] != EMPTY && board[i][j] > 0){
                block = BFS(i,j, false);
                int blocksize = block.size;
                int blockrainbow = block.rainbow;
                if(blocksize > maxBlock || (blocksize == maxBlock && blockrainbow >= maxRainbow)){
                    maxBlock = blocksize;
                    maxRainbow = blockrainbow;
                    maxR = i;
                    maxC = j;
                }
            }
        }
    }

// cout << "finally, the biggest block is here: " << maxR << ", " << maxC << "\n";
    //기준에 맞는 블록 그룹 찾음.
     initVisited();
    if(maxBlock >= 2){
        block = BFS(maxR, maxC, true);
        ans += block.size * block.size;
        return true;
    }
    return false;
    
}

void gravity(){
    int hasgraavitiezed[21] = {0,};

    //각 열별로 중력이 작용할 행을 찾는다.
    //열을 순회하면서
    //가장 높은 빈칸 중, 그 위의 블록이 떨어질 수 있는 물체로 이루어진 블록을 찾는다.
    for(int j = 1; j <= N; j++){
        int i = N;
        bool find = false;
        int dropIdx = 1;
        //떨어질 물체
        while(true){
            if(board[i][j] == EMPTY && find == false){
                dropIdx = i;
                find = true;
            }
            if(board[i][j] == -1 && find == true){
                find = false;
            }
            if(board[i][j] != EMPTY && board[i][j] != -1 && find == true){
                board[dropIdx][j] = board[i][j];
                board[i][j] = EMPTY;
                dropIdx -=1;
            }
            i--;
            if(i == 0)
                break;
        }
    }

}

void rotate(){
    
    // cout << "rotate\n" ;
    int newboard[21][21] ={{0}};
    for(int j = 1; j <= N; j++){
        for(int i = 1; i <= N; i++){
            newboard[N - j + 1][i] = board[i][j];
        }
    }
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            board[i][j] = newboard[i][j];
        }
    }
}

void print_ground()
{
	cout << "============\n";
	for(int y = 1; y <= N; ++y) {
		for (int x = 1; x <= N; ++x) {
			if (board[y][x] < 0 && board[y][x] != -2)
				cout << board[y][x] << " ";
			else if (board[y][x] == EMPTY)
				cout << "   ";
			else
				cout << " " << board[y][x] << " ";
		}
		cout << "\n";
	}
	cout << "============\n";
}

void solve(){
    //find biggest block -> return size, rainbow
    //remove biggest block , add score
    //gravity
    //rotate
    //gravity

    // print_ground();
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(board[i][j] != EMPTY && board[i][j] != 0 && board[i][j] != -1){
                // check();
                if(!findBiggestBlockGroupAndGetScore()){
                    break;
                }
                // print_ground();
                    // findBiggestBlockGroupAndGetScore();
                // check();
                gravity();
                // check();
                rotate();
                // check();
                gravity();
                // check();
                // break;
                // print_ground();
				i = 1;
				j = 1;
            }
        }

    }

}


int main(){
    FAST
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> board[i][j];
        }
    }

    solve();

    cout << ans << "\n";
}