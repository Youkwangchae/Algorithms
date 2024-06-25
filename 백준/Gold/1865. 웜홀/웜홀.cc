#include <iostream>
#include <vector>
using namespace std;

int n, m, w;

class Edge
{
public:
	int a, b, w;
};

bool bellman_ford(int start, vector<int> &dist, vector<Edge> & Edges)
{
	for (int i = 1; i < n; i++)
	{
		for (int j=0;j<Edges.size();j++)
		{
			int begin = Edges[j].a;
			int end = Edges[j].b;
			int cost = Edges[j].w;

			if (dist[end] > dist[begin] + cost)
			{
				dist[end] = dist[begin] + cost;				
			}
		}
	}	

	for (int j = 0; j < Edges.size(); j++)
	{
		int begin = Edges[j].a;
		int end = Edges[j].b;
		int cost = Edges[j].w;

		if (dist[end] > dist[begin] + cost)
		{			
			return true;
		}
	}

	return false;
}

void solve()
{
	cin >> n >> m >> w;

	vector<Edge> Edges;

	vector<int> dist;
	dist.resize(n + m, 1e9);

	int a, b, c;

	for (int i = 1; i <= m; i++)
	{
		cin >> a >> b >> c;
		Edges.push_back({ a, b, c });		
		Edges.push_back({ b, a, c });
	}

	for (int i = 1; i <= w; i++)
	{
		cin >> a >> b >> c;
		Edges.push_back({ a, b, -c });
	}

	if (bellman_ford(n, dist, Edges))
	{
		cout << "YES" << '\n';		
	}
	else
		cout << "NO" << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;

	for (int k = 1; k <= tc; k++)
	{
		solve();
	}
}