#include <iostream>
#include <vector>
using namespace std;

int n, m, w;

class Edge
{
public:
	int a, b;
	int w = 1e9;
};

vector<Edge> Edges;

bool bellman_ford(int start)
{	
	vector<int> dist;
	dist.resize(n + m, 0);								// 모든 점에서 벨만-포드를 돌리기 위해 모든 거리를 INF 대신 0으로 초기화.

	for (int i = 0; i < n; i++)
	{
		for (const auto& e : Edges)
		{			
			if (dist[e.a] == 1e9) continue;
			dist[e.b] = min(dist[e.b], dist[e.a] + e.w);
		}
	}

	for (const auto& e : Edges)
	{
		if (dist[e.a] == 1e9) continue;

		if (dist[e.b] > dist[e.a] + e.w)
		{
			return true;
		}
	}

	return false;
}

//bool bellman_ford(int start)
//{
//	vector<int> dist;
//	dist.resize(n + m, 1e9);								
//
//	for (int i = 0; i < n; i++)
//	{
//		for (const auto& e : Edges)
//		{												// 모든 점이 INF인지 확인하지 않으므로, 모든 점에서 벨만-포드 구할 수 있음.
//			dist[e.b] = min(dist[e.b], dist[e.a] + e.w);
//		}
//	}
//
//	for (const auto& e : Edges)
//	{//													// 모든 점이 INF인지 확인하지 않으므로, 모든 점에서 벨만-포드 구할 수 있음.
//		if (dist[e.b] > dist[e.a] + e.w)
//		{
//			return true;
//		}
//	}
//
//	return false;
//}

void solve()
{
	cin >> n >> m >> w;

	Edges.clear();	

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

	if (bellman_ford(1))	
		cout << "YES" << '\n';			
	else
		cout << "NO" << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int tc;
	cin >> tc;

	for (int k = 1; k <= tc; k++)
	{
		solve();
	}
}