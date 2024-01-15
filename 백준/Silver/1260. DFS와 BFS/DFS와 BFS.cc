#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> V;
vector<vector<int>> Q;
vector<int> q_bfs;

// V[0].push_back(3);

bool isVisitedDFS[1001] = { false, };
bool isVisitedBFS[1001] = { false, };

void DFS(int start)
{
	isVisitedDFS[start] = true;

	cout << start << " ";

	for (int i = 1; i < V[start].size(); i++)
	{
		if (!isVisitedDFS[V[start].at(i)])
		{
			DFS(V[start].at(i));
		}
	}
}

void BFS(int start, int index)
{
	while (!q_bfs.empty())
	{
		int pop = q_bfs[0];

		if (!isVisitedBFS[pop])
		{
			isVisitedBFS[pop] = true;
		}		

		q_bfs.erase(q_bfs.begin());

		for (int i = 1; i < Q[pop].size(); i++)
		{
			int mt = Q[pop].at(i);

			if (!isVisitedBFS[mt])
			{
				q_bfs.push_back(mt);
				// Q[pop].erase(remove(Q[pop].begin(), Q[pop].end(), mt));
				isVisitedBFS[mt] = true;
			}
		}		

		cout << pop << " ";
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	

	int n, m, v;

	cin >> n >> m >> v;

	// n+1 개의 벡터를 각각 0으로 초기화.
	V.resize(n + 1, vector<int>(1, 0));
	Q.resize(n + 1, vector<int>(1, 0));	

	int vertice1, vertice2;	

	for (int i = 0; i < m; i++)
	{
		cin >> vertice1 >> vertice2;

		V[vertice1].push_back(vertice2);
		V[vertice2].push_back(vertice1);

		Q[vertice1].push_back(vertice2);
		Q[vertice2].push_back(vertice1);
	}

	// 각 벡터 Sort.
	for (int i = 1; i < n + 1; i++)
	{
		if (V[i].size() > 0)
			sort(V[i].begin(), V[i].end());

		if (Q[i].size() > 0)
			sort(Q[i].begin(), Q[i].end());
	}

	DFS(v);
	cout << endl;
	q_bfs.push_back(v);
	BFS(v, 1);
}