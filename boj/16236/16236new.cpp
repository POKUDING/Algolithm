#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<vector<int> > ocean;
vector<vector<int> > tmp;
pair<int, int> shark;
pair<int, int> shark_size;
typedef struct fish {
	int x;
	int y;
	int cnt;
} fish;
fish beforefish;
int N;
int rtn = 0;

void init()
{
	cin >> N;
	int in;
	for(int i = 0; i < N; ++i)
	{
		vector<int> tmp_vec;
		for(int j = 0; j < N; ++j)
		{
			cin >> in;
			tmp_vec.push_back(in);
			if (in == 9)
				shark = make_pair(j, i);
		}
		ocean.push_back(tmp_vec);
	}
	shark_size = make_pair(2, 0);
}

bool canmove(int x, int y)
{
	if (x < 0 || y < 0 || x >= N || y >= N || tmp[y][x] > shark_size.first || tmp[y][x] < 0)
		return false;
	return true;
}

bool caneat(int x, int y, int cnt)
{
	if (tmp[y][x] > 0 && tmp[y][x] < shark_size.first && cnt <= beforefish.cnt &&\
		(cnt < beforefish.cnt || beforefish.x < 0 || y < beforefish.y || (y == beforefish.y && x < beforefish.x)))
		{
			tmp[y][x] = -1;
			return true;
		}
	return false;
}

bool eatfish()
{
	int x;
	int y;
	int cnt = 0;
	queue<pair<pair<int,int>,int> > que;
	tmp = ocean;
	beforefish.x = -1;
	beforefish.cnt = 2147483647;
	que.push(make_pair(shark, cnt));
	while(!que.empty())
	{
		pair<pair<int, int>, int> now;
		now = que.front();
		que.pop();
		x = now.first.first;
		y = now.first.second;
		cnt = now.second;
		if(tmp[y][x] < 0)
			continue;
		if (caneat(x, y, cnt))
		{
			beforefish.x = x;
			beforefish.y = y;
			beforefish.cnt = cnt;
		}
		tmp[y][x] = -1;
		if (canmove(x, y - 1))
			que.push(make_pair(make_pair(x, y - 1), cnt + 1));
		if (canmove(x - 1, y))
			que.push(make_pair(make_pair(x - 1, y), cnt + 1));
		if (canmove(x + 1, y))
			que.push(make_pair(make_pair(x + 1, y), cnt + 1));
		if (canmove(x, y + 1))
			que.push(make_pair(make_pair(x, y + 1), cnt + 1));
	}
	if (beforefish.x >= 0)
	{
		ocean[shark.second][shark.first] = 0;
		ocean[beforefish.y][beforefish.x] = 9;
		shark.first = beforefish.x;
		shark.second = beforefish.y;
		if (shark_size.first < 9 && shark_size.first == ++shark_size.second)
		{
			++shark_size.first;
			shark_size.second = 0;
		}
		rtn += beforefish.cnt;
		return true;
	}
	return false;
}

void printocean()
{
	cout << "==========\n";
	cout << "size : " << shark_size.first << "\n";
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
			cout << ocean[i][j] << " ";
		cout << "\n";
	}
	cout << "==========\n" << endl;
}

int main()
{
	init();
	while(eatfish())
		;
	cout << rtn;
	return 0;
}