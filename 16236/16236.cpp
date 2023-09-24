#include <iostream>
#include <vector>

using namespace std;

int N;
int fish_cnt = 0;
vector<vector<int> > map;
pair<int, int> shark;
pair<int, int> shark_size;
pair<pair<int, int>, int> fish;

void init()
{
	int tmp;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		vector<int> vectmp;
		for (int j = 0; j < N; ++j)
		{
			cin >> tmp;
			vectmp.push_back(tmp);
			if (tmp == 9)
				shark = make_pair(j, i);
			else if (tmp > 0)
				fish_cnt++;
		}
		map.push_back(vectmp);
	}
}

bool canmove(vector<vector<int> >& tmp, int x, int y)
{
	if (x < 0 || y < 0 || x >= N || y >= N || tmp[y][x] > shark_size.first || tmp[y][x] < 0)
		return false;
	return true;
}

void findfish(vector<vector<int> > tmp, int x, int y, int cnt)
{
	if (tmp[y][x] < 0 || (fish.second && cnt > fish.second))
		return;
	++cnt;
	if (map[y][x] > 0  && (map[y][x] < shark_size.first))
	{
		if (fish.first.first == -1 || fish.second > cnt || \
			(fish.second == cnt && fish.first.second >= y))
		{
			if (fish.first.second == y && fish.first.first < x)
				return ;
			fish.first = make_pair(x, y);
			fish.second = cnt;
			return ;
		}
	}
	tmp[y][x] = -1;
	if (canmove(tmp, x, y - 1))
		findfish(tmp, x, y - 1, cnt);
	if (canmove(tmp, x - 1, y))
		findfish(tmp, x - 1, y, cnt);
	if (canmove(tmp, x + 1, y))
		findfish(tmp, x + 1, y, cnt);
	if (canmove(tmp, x, y + 1))
		findfish(tmp, x, y + 1, cnt);
}

void printmap()
{
	cout << "==========\n";
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
			cout << map[i][j] << " ";
		cout << "\n";
	}
	cout << "==========\n" << endl;
}

int main()
{
	int rtn = 0;
	shark_size = make_pair(2 , 0);
	init();
	while (fish_cnt)
	{
		fish.first = make_pair(-1, -1);
		fish.second = 0;
		findfish(map, shark.first, shark.second, -1);
		if (fish.second == 0)
			break ;
		map[shark.second][shark.first] = 0;
		shark = fish.first;
		map[shark.second][shark.first] = 9;
		shark_size.second++;
		if (shark_size.first == shark_size.second)
		{
			shark_size.first++;
			shark_size.second = 0;
		}
		rtn += fish.second;
		printmap();
		cout << shark_size.first << " \n";
		--fish_cnt;
	}
	cout << rtn;
}