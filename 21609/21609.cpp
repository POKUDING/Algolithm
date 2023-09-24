#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

// 프로그램 실행시 인풋값으로 배열 초기화
void	init(vector<vector<int> >& ground, int n)
{
	int tmp;
	for(int y = 0; y < n; ++y)
	{
		for(int x = 0; x < n; ++x)
		{
			cin >> tmp;
			ground[y][x] = tmp;
		}
	}	
}

// 중력을 적용 시켜 블록을 내림
void	gravity(vector<vector<int> >& ground, int n)
{
	int wall;
	for(int i = 0; i < n; ++i)
	{
		wall = n - 1;
		for(int j = n - 1; j >= 0; --j)
		{
			if (ground[j][i] >= 0)
			{
				if (wall != j)
				{
					ground[wall][i] = ground[j][i];
					ground[j][i] = -2;
				}
				--wall;
			} else if (ground[j][i] == -1)
				wall = j - 1;
		}
	}
}

//반시계방향으로 블록 회전
void	rotate(vector<vector<int> >& ground, int n)
{
	vector<vector<int> > tmp(ground);
	for(int y = 0; y < n; ++y) {
		for (int x = 0; x < n; ++x) {
			ground[y][x] = tmp[x][n - y - 1];
		}
	}
}

//위아래 좌우 4방을 전염시켜 블록크기 구하기, 0 은 다른 블록에서도 이용가능하기에 visit_rainbow에 추가함으로 중복 방문 방지 나머지는 bloack 값에 + m 하여 추가방문 방지.
void make_empty(vector<vector<int> >&ground, int n,int m, int x, int y, int block, int& rainbow, int& size, map<int, vector<int> >& visit_rainbow)
{
	if (!(x >= 0 && y >= 0 && x < n && y < n))
		return ;
	if (ground[y][x] == block || ground[y][x] == 0)
	{
		if (m < 0)
			ground[y][x] = -2;
		else if (ground[y][x] == 0 && m > 0) {
			if (find(visit_rainbow[y].begin(), visit_rainbow[y].end(), x) != visit_rainbow[y].end())
				return ;
			visit_rainbow[y].push_back(x);
			++rainbow;
		} else
			ground[y][x] = block + m;
		++size;
		make_empty(ground, n, m, x + 1, y, block, rainbow, size, visit_rainbow);
		make_empty(ground, n, m, x - 1, y, block, rainbow, size, visit_rainbow);
		make_empty(ground, n, m, x, y + 1, block, rainbow, size, visit_rainbow);
		make_empty(ground, n, m, x, y - 1, block, rainbow, size, visit_rainbow);
	}
}

//해당 x,y 좌표에서 연결할 수 있는 블록 사이즈를 계산하여 반환.
int check_size(vector<vector<int> >&ground, int n,int m, int x, int y, int& rainbow)
{
	int ret = 0;
	map<int, vector<int> > visit_rainbow;

	make_empty(ground, n, m, x, y, ground[y][x], rainbow, ret, visit_rainbow);
	return ret;
}

// 블록의 기준블록이 될 수 있는지 검사.
bool is_block(vector<vector<int> >&ground, int n, int m, int x, int y)
{
	if (!(ground[y][x] > 0 && ground[y][x] <= m ))
		return false;
	if (x + 1 < n && (ground[y][x] == ground[y][x + 1] || ground[y][x + 1] == 0))
		return true;
	if (y + 1 < n && (ground[y][x] == ground[y + 1][x] || ground[y + 1][x] == 0))
		return true;
	if (x - 1 >= 0 && ground[y][x - 1] == 0)
		return true;
	if (y - 1 >= 0 && ground[y - 1][x] == 0)
		return true;
	return false;
}

//ground의 모든 좌표를 돌며 만약 기준블록이면 좌표와 사이즈를 저장. 이후 가장 큰 블록을 -2로 세팅 -2는 빈칸.
int delete_big_groop(vector<vector<int> >&ground, int n, int m)
{
	int groop_size = 0;
	int cnt_rainbow = 0;
	int rainbow_tmp = 0;
	int size_tmp;
	vector<vector<int> > tmp(ground);
	pair<int, int> position;

	for(int y = 0; y < n; ++y) {
		for(int x = 0; x < n; ++x) {
			//is_block 함수로 기준블록이 될 수 있는지 확인
			if (is_block(tmp, n, m, x, y))
			{
				rainbow_tmp = 0;
				//check_size 함수로 기준블록으로 연결된 블록들의 사이즈를 계산
				size_tmp = check_size(tmp,n,m,x,y, rainbow_tmp);
				//사이즈가 제일 크거나, 사이즈가 같은데 rainbow의 갯수가 크거나 같으면 가장큰 기준블록 변경 
				if (size_tmp > 1&& (size_tmp > groop_size || (size_tmp == groop_size && rainbow_tmp >= cnt_rainbow)))
				{
					groop_size = size_tmp;
					cnt_rainbow = rainbow_tmp;
					position.first = x;
					position.second = y;
				}
			}
		}
	}
	//지울 수 있는 블록을 발견했을 경우
	if (groop_size > 0)
	{
		groop_size = 0;
		map<int, vector<int> > visit_rainbow;
		make_empty(ground, n, -1, position.first, \
			position.second, ground[position.second][position.first],cnt_rainbow, groop_size, visit_rainbow);
	}
	// cout << groop_size << " \n";
	return groop_size * groop_size;
}


// 재귀를 통해 블록사이즈가 0일때까지 게임진행.
int game(vector<vector<int> >&ground,int n,int m){
	int tmp = 0;

	tmp = delete_big_groop(ground, n, m);
	if (!tmp)
		return (0);
	gravity(ground, n);
	rotate(ground, n);
	gravity(ground, n);
	return (tmp + game(ground, n, m));
}

int main()
{
	int n, m;
	int ret = 0;

	cin >> n >> m;
	vector<vector<int> > ground(n, vector<int>(n , -1));
	init(ground, n);
	ret = game(ground, n, m);
	cout << ret << endl;
}