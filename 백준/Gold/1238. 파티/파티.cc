#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class pkt
{
public:
	long long l;
	int w, a, b;
	bool operator < (const pkt& p) const
	{
		return l > p.l;
	}
};

int n, m, x;

vector<vector<pair<int, int>>> Edges;
priority_queue<pkt> PQ;

int dijkstra(int s)
{
	int Visit[10005] = { 0, };
	int L[10005] = { 0, };
	pkt p, q;
	p.l = 0; p.w = 0; p.a = 0;
	p.b = s;

	PQ.push(p);

	while (!PQ.empty())
	{
		p = PQ.top();
		PQ.pop();

		if (Visit[p.b]) continue;
		Visit[p.b] = true;
		L[p.b] = p.l;

		for (int i = 0; i < Edges[p.b].size(); i++)
		{
			q.l = p.l + Edges[p.b][i].second;
			q.w = Edges[p.b][i].second;
			q.b = Edges[p.b][i].first;
			q.a = p.b;
			PQ.push(q);
		}
	}

	return L[x];
}

int source_Visit[10005], source_L[10005];

void dijkstraForSource(int s)
{
	pkt p, q;
	p.l = 0; p.w = 0; p.a = 0;
	p.b = s;

	PQ.push(p);

	while (!PQ.empty())
	{
		p = PQ.top();
		PQ.pop();

		if (source_Visit[p.b]) continue;
		source_Visit[p.b] = true;
		source_L[p.b] = p.l;

		for (int i = 0; i < Edges[p.b].size(); i++)
		{
			q.l = p.l + Edges[p.b][i].second;
			q.w = Edges[p.b][i].second;
			q.b = Edges[p.b][i].first;
			q.a = p.b;
			PQ.push(q);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m >> x;

	Edges.resize(10005);

	int a, b, t;
	for (int i = 1; i <= m; i++)
	{
		cin >> a >> b >> t;
		Edges[a].push_back({ b, t });
	}

	int answer = 0;

	dijkstraForSource(x);

	for (int i = 1; i <= n; i++)
	{
		if (i == x) continue;
		answer = max(answer, dijkstra(i) + source_L[i]);
	}

	cout << answer;
	return 0;
}