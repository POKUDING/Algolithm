#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void	init(vector<vector<int> >& map, int n)
{
	int tmp;
	for(int y = 0; y < n; ++y)
	{
		for(int x = 0; x < n; ++x)
		{
			cin >> tmp;
			map[y].push_back(tmp);
		}
	}	
}

void	gravity(vector<vector<int> >& map, int n)
{
	int wall;
	for(int i = 0; i < n; ++i)
	{
		wall = n - 1;
		for(int j = n - 1; j >= 0; --j)
		{
			if (map[j][i] >= 0)
			{
				if (wall != j)
				{
					map[wall][i] = map[j][i];
					map[j][i] = -2;
				}
				--wall;
			} else if (map[j][i] == -1)
				wall = j - 1;
		}
	}
}

void	rotate(vector<vector<int> >& map, int n)
{
	vector<vector<int> > tmp(map);
	for(int y = 0; y < n; ++y) {
		for (int x = 0; x < n; ++x) {
			map[y][x] = tmp[x][n - y - 1];
		}
	}
}

void print_map(vector<vector<int> >& map, int n)
{
	cout << "============\n";
	for(int y = 0; y < n; ++y) {
		for (int x = 0; x < n; ++x) {
			if (map[y][x] < 0)
				cout << map[y][x] << " ";
			else
				cout << " " << map[y][x] << " ";
		}
		cout << "\n";
	}
	cout << "============\n";
}

void make_empty(vector<vector<int> >&map, int n,int m, int x, int y, int block, int& rainbow, int& size, vector<pair<int, int> >& visit_rainbow)
{
	if (!(x >= 0 && y >= 0 && x < n && y < n))
		return ;
	if (map[y][x] == block || map[y][x] == 0)
	{
		if (map[y][x] == 0 && m > 0)
		{
			if (find(visit_rainbow.begin(), visit_rainbow.end(), pair<int,int>{x , y}) != visit_rainbow.end())
				return ;
			visit_rainbow.push_back({x, y});
		}
		else
			map[y][x] = block + m;
		++size;
		make_empty(map, n, m, x + 1, y, block, rainbow, size, visit_rainbow);
		make_empty(map, n, m, x - 1, y, block, rainbow, size, visit_rainbow);
		make_empty(map, n, m, x, y + 1, block, rainbow, size, visit_rainbow);
		make_empty(map, n, m, x, y - 1, block, rainbow, size, visit_rainbow);
	}
}

int check_size(vector<vector<int> >&map, int n,int m, int x, int y, int& rainbow)
{
	int ret = 0;
	vector<pair<int,int> > visit_rainbow;

	make_empty(map, n, m, x, y, map[y][x], rainbow, ret, visit_rainbow);
	return ret;
}

int delete_big_groop(vector<vector<int> >&map, int n, int m)
{
	int groop_size = 0;
	int cnt_rainbow = 0;
	int rainbow_tmp = 0;
	int size_tmp;
	vector<vector<int> > tmp(map);
	pair<int, int> position;

	for(int y = 0; y < n; ++y) {
		for(int x = 0; x < n - 1; ++x) {
			if ((map[y][x] > 0 && map[y][x] <= m ) && \
				(map[y][x] == map[y][x + 1] || (y + 1 < n && map[y][x] == map[y + 1][x])))
			{
				size_tmp = check_size(tmp,n,m,x,y, rainbow_tmp);
				if (size_tmp && (size_tmp > groop_size || (size_tmp == groop_size && rainbow_tmp >= cnt_rainbow)))
				{
					groop_size = size_tmp;
					cnt_rainbow = rainbow_tmp;
					position.first = x;
					position.second = y;
				}
			}
		}
	}
	if (groop_size > 0)
	{
		vector<pair<int,int> > visit_rainbow;
		make_empty(map, n, -1 * (2 + map[position.second][position.first]), position.first, \
			position.second, map[position.second][position.first],size_tmp, cnt_rainbow, visit_rainbow);
	}
	return cnt_rainbow * cnt_rainbow;
}

int game(vector<vector<int> >&map,int n,int m){
	int tmp = 0;

	cout << "in game\n";
	print_map(map, n);
	tmp = delete_big_groop(map, n, m);
	cout << "after delete biggroop\n";
	print_map(map, n);
	if (!tmp)
		return (0);
	gravity(map, n);
	cout << "after gravity\n";
	print_map(map, n);
	rotate(map, n);
	cout << "after rotate\n";
	print_map(map, n);
	gravity(map, n);
	cout << "after gravity\n";
	print_map(map, n);
	return (tmp + game(map, n, m));
}

int main()
{
	int n, m;
	int ret = 0;

	cin >> n >> m;
	vector<vector<int> > map(n);
	init(map, n);
	ret = game(map, n, m);
	cout << ret;
}