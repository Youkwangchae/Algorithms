#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isVisited[100001] = { false, };
vector<vector<int>> V;
int visit[100001] = { 0, };
int visitCount = 1;

void dfs(int start)
{
	isVisited[start] = true;
	visit[start] = visitCount++;

	for (int i = 1; i < V[start].size(); i++)
	{
		if (!isVisited[V[start].at(i)])
		{
			dfs(V[start].at(i));
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, r;

	cin >> n >> m >> r;

	V.resize(n+1, vector<int>(1, 0));

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

	dfs(r);

	vector<int>::iterator it;

	for (int i = 1; i < n + 1; i++)
	{
		cout << visit[i] << "\n";
	}
}