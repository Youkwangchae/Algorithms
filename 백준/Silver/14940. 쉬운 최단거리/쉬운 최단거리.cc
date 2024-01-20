#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int V[1002][1002] = { 0, };
int ans[1002][1002] = { 0, };
int visited[1002][1002] = { false, };

queue<pair<int, int>> Q;
int n, m;

void bfs_Num()
{
	int a, b, parent;
	while (!Q.empty())
	{
		pair<int, int> mt = Q.front();
		Q.pop();

		a = mt.first;
		b = mt.second;
		parent = ans[a][b];		

		if (!visited[a][b])
		{
			visited[a][b] = true;

			if (a >= 1 && a <= n && b >= 1 && b <= m)
			{
				// cout << a << ", " << b << ", " << parent << endl;

				// 갈 수 없는 곳, 출발 지점
				if (V[a][b] != 1)
				{
					ans[a][b] = 0;
				}
				else // 갈 수 있는 곳
				{
					if (ans[a][b] > parent + 1)
						ans[a][b] = parent + 1;
				}

				if (V[a][b] != 0)
				{
					if (!visited[a][b + 1])
						ans[a][b + 1] = parent + 1;
					Q.emplace(a, b + 1);

					if (!visited[a + 1][b])
						ans[a + 1][b] = parent + 1;
					Q.emplace(a + 1, b);

					if (!visited[a][b - 1])
						ans[a][b - 1] = parent + 1;
					Q.emplace(a, b - 1);

					if (!visited[a - 1][b])
						ans[a - 1][b] = parent + 1;
					Q.emplace(a - 1, b);
				}				
			}
		}		
	}

	//// 네 방향 끝 줄을 탐색하면 바로 중지.
	//if (a < 1 || a > n || b < 1 || b > n) return;	

	//if (visited[a][b]) return;

	//visited[a][b] = true;

	//// 갈 수 없는 곳, 출발 지점
	//if (V[a][b] != 1)
	//{
	//	ans[a][b] = 0;				
	//}	
	//else// 갈 수 있는 곳
	//{
	//	ans[a][b] = parent + 1;
	//}

	//bfs_Num(a, b + 1, ans[a][b]);
	//bfs_Num(a, b - 1, ans[a][b]);
	//bfs_Num(a + 1, b, ans[a][b]);
	//bfs_Num(a - 1, b, ans[a][b]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);	

	cin >> n >> m;

	int x = 0;
	int y = 0;

	int num;
	for (int i = 1; i < n+1; i++)
	{
		for (int j = 1; j < m + 1; j++)
		{
			cin >> num;
			V[i][j] = num;

			if (num == 2)
			{
				x = i;
				y = j;
			}

			if(num == 0)
				ans[i][j] = 0;
			else
				ans[i][j] = -1;
		}
	}	

	ans[x][y] = 0;

	Q.emplace(x, y);
	bfs_Num();

	for (int i = 1; i < n+1; i++)
	{
		for (int j = 1; j < m+1; j++)
		{
			cout << ans[i][j] << " ";			
		}
		cout << "\n";
	}
}