#include <iostream>
#include <map>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int	check_sit(vector<vector<int> >& sit, int n, int y, int x, vector<int> check)
{
	int ret = 0;

	if (y - 1 > 0 && find(check.begin(), check.end(), sit[y - 1][x]) != check.end())
		++ret;
	if (x - 1 > 0 && find(check.begin(), check.end(), sit[y][x - 1]) != check.end())
		++ret;
	if (y + 1 < n + 1 &&find(check.begin(), check.end(), sit[y + 1][x]) != check.end())
		++ret;
	if (x + 1 < n + 1 && find(check.begin(), check.end(), sit[y][x + 1]) != check.end())
		++ret;
	return ret;
}

void	sit_student(vector<vector<int> >& sit,int n, int student,vector<int>friends)
{
	int cntFriends = 0;
	int cntEmpty = 0;
	int tmpFriends;
	int tmpEmpty;
	pair<int, int> sits = {0, 0};

	for(int i = 1; i < n + 1; ++i) {
		for (int j = 1; j < n + 1; ++j) {
			tmpFriends =  check_sit(sit, n, i, j, friends);
			if(sit[i][j] == 0 && tmpFriends >= cntFriends)
			{
				tmpEmpty = check_sit(sit,n,i,j,{0});
				if (tmpFriends == cntFriends && tmpEmpty <= cntEmpty && sits.first != 0)
					continue;
				sits = {i, j};
				cntFriends = tmpFriends;
				cntEmpty = tmpEmpty;
			}
		}
	}
	sit[sits.first][sits.second] = student;
}

int main()
{
	int n;
	int ret = 0;
	vector<int> input;
	unordered_map<int,vector<int> > student;
	vector<int>::iterator it;

	cin >> n;
	vector<vector<int> > sit(n + 2, vector<int>(n+2));
	for(int i = 0, num,like; i < n * n; ++i) {
		cin >> num;
		input.push_back(num);
		for(int j = 0; j < 4; ++j) {
			cin >> like;
			student[num].push_back(like);
		}
	}
	it = input.begin();
	sit[2][2]= *(it++);
	for(vector<int>::iterator end = input.end(); it != end; ++it)
		sit_student(sit, n, *it, student[*it]);
	for (int i = 1, score; i < n + 1; ++i)
	{
		for (int j = 1; j < n + 1; ++j)
		{
			score = check_sit(sit, n, i, j, student[sit[i][j]]);
			if (score == 1)
				ret += 1;
			else if (score == 2)
				ret += 10;
			else if (score == 3)
				ret += 100;
			else if (score == 4)
				ret += 1000;
		}
	}
	cout << ret;
}