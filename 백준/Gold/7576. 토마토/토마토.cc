#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

int V[1002][1002];

queue<pair<int, int>> Q;
int totalCount = 0;
int minusCount = 0;
int dayCount = 0;
int beforeTotal = 0;

int main()
{
	memset(V, -1, sizeof(V));

	int n, m;
	cin >> m >> n;

	int num;

	for (int i = 1; i < n+1; i++)
	{
		for (int j = 1; j < m+1; j++)
		{
			cin >> num;
			V[i][j] = num;			

			if (num == 1)
			{
				Q.emplace(i, j);	
				totalCount++;
			}
			else if (num == -1)
			{
				minusCount++;
			}
		}
	}	

	// 저장될 때부터 모든 토마토가 익어있음.
	if (Q.size() == n * m - minusCount)
		cout << 0;
	else if (Q.size() == 0)	// 익은 토마토 없이 익지 않은 토마토만 있음.
		cout << -1;
	else
	{
		while (!Q.empty())
		{
			dayCount++;
			queue<pair<int, int>> nowQ;

			while (!Q.empty())
			{								
				pair<int, int> mt = Q.front();
				Q.pop();

				int a = mt.first;
				int b = mt.second;

				if (a >= 1 && a <= n && b >= 1 && b <= m)
				{
					if (V[a + 1][b] == 0)
					{					
						V[a + 1][b] = 1;
						nowQ.emplace(a + 1, b);
						totalCount++;
					}

					if (V[a - 1][b] == 0)
					{
						V[a - 1][b] = 1;
						nowQ.emplace(a - 1, b);
						totalCount++;
					}

					if (V[a][b + 1] == 0)
					{
						V[a][b + 1] = 1;
						nowQ.emplace(a, b + 1);
						totalCount++;
					}

					if (V[a][b - 1] == 0)
					{
						V[a][b - 1] = 1;
						nowQ.emplace(a, b - 1);
						totalCount++;
					}
				}
			}			
			if (totalCount == n * m - minusCount)
				break;
			else if (totalCount == beforeTotal) {
				dayCount = -1;
				break;
			}
			else {
				beforeTotal = totalCount;
				while (!nowQ.empty())
				{
					Q.push(nowQ.front());
					nowQ.pop();
				}
			}			
		}		

		cout << dayCount;
	}
}