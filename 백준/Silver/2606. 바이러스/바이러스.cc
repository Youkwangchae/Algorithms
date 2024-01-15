#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> V;
queue<int> Q;

bool isVisit[101] = { false, };
int visitCount = 0;

void bfs()
{
	isVisit[1] = true;

	while (!Q.empty())
	{
		int pop = Q.front();
		Q.pop();

		for (int i = 1; i < V[pop].size(); i++)
		{
			int mt = V[pop].at(i);
			if (!isVisit[mt])
			{
				isVisit[mt] = true;
				visitCount++;
				Q.push(mt);
			}
		}
	}
}

int main()
{
	int n, m;

	cin >> n >> m;

	V.resize(n + 1, vector<int>(1, 0));

	int vert1, vert2;
	for (int i = 0; i < m; i++)
	{
		cin >> vert1 >> vert2;

		V[vert1].push_back(vert2);
		V[vert2].push_back(vert1);
	}

	for (int i = 1; i < n + 1; i++)
	{
		sort(V[i].begin(), V[i].end());
	}

	Q.push(1);
	bfs();
	cout << visitCount;
}