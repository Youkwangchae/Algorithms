#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include <algorithm>
using namespace std;
vector<pair<pair<int, int>, bool>> pos;
queue<pair<pair<int, int>, bool>> Q;

int bfs()
{
	int bugCount = 0;

	while (!pos.empty())
	{
		if(Q.size() == 0)
		{
			Q.push(pos.front());
			pos.erase(pos.begin());
			bugCount++;			
		}

		pair<pair<int, int>, bool> point = Q.front();
		Q.pop();			
		if(find(pos.begin(), pos.end(), point) != pos.end())
		pos.erase(remove(pos.begin(), pos.end(), point));

		for (int i = 0; i < pos.size(); i++)
		{
			if (pos[i].second) continue;

			if (point.first.first == pos[i].first.first)
			{
				if (abs(point.first.second - pos[i].first.second) == 1)
				{
					pos[i].second = true;
					Q.push(pos[i]);
					// pos.erase(remove(pos.begin(), pos.end(), pos[i]));
				}
			}
			else if (point.first.second == pos[i].first.second)
			{
				if (abs(point.first.first - pos[i].first.first) == 1)
				{
					pos[i].second = true;
					Q.push(pos[i]);					
					// pos.erase(remove(pos.begin(), pos.end(), pos[i]));					
				}
			}
		}
	}

	return bugCount;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;	

	cin >> t;	
	
	int m, n, k;

	int posX, posY;
	pair<pair<int, int>, bool> vec;

	for (int i = 0; i < t; i++)
	{
		cin >> m >> n >> k;

		for (int j = 0; j < k; j++)
		{
			cin >> posX >> posY;
			vec.first.first = posX;
			vec.first.second = posY;
			vec.second = false;
			pos.push_back(vec);
		}

		cout << bfs() << "\n";
	}
}