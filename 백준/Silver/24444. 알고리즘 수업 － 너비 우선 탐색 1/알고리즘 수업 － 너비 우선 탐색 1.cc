#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> V;
bool isVisit[100001] = { false, };
queue<int> Q;
int visit[100001] = { 0, };
int visitCount = 1;

void bfs(int start)
{
	isVisit[start] = true;
	visit[start] = visitCount++;

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
				Q.push(mt);
				visit[mt] = visitCount++;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, r;

	cin >> n >> m >> r;

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

	Q.push(r);
	bfs(r);

	for (int i = 1; i < n+1; i++)
	{
		cout << visit[i] << "\n";
	}
}