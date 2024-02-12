#include <iostream>
#include <queue>
#include <vector>

#define INF 987654321
using namespace std;

vector<pair<int, int>> V[20005];
int dst[20005];

void dijkstra(int startNode)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	pq.push({ 0, startNode });
	dst[startNode] = 0;

	while (!pq.empty())
	{
		pair<int, int> p = pq.top();
		pq.pop();

		for (int i = 0; i < V[p.second].size(); i++)
		{
			int cost = V[p.second][i].first;
			int next = V[p.second][i].second;

			if (p.first + cost < dst[next])
			{
				dst[next] = p.first + cost;
				pq.push({ dst[next], next });
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int v, e, start;
	cin >> v >> e >> start;

	int a, b, c;
	
	for (int i = 0; i < e; i++)
	{
		cin >> a >> b >> c;
		V[a].push_back({ c, b });
	}

	for (int i = 1; i < v + 1; i++)
	{
		dst[i] = INF;
	}

	dijkstra(start);

	for (int i = 1; i < v + 1; i++)
	{
		if (dst[i] == INF)
			cout << "INF\n";
		else
			cout << dst[i] << "\n";
	}
}