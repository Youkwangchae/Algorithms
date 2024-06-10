#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class triple {
public:
	int first, second, third;
};

class packet
{
public:
	long long l;
	int a, b, w, num;
	bool operator < (const packet& k) const
	{
		return l > k.l;
	}
};

int Visit[300005], ans[300005], wei[300005];
long long L[300005];

priority_queue<packet> Q;
vector<vector<triple>> Edges;

int n, m;

void dijkstra(int s)
{
	packet p, q;
	p.a = 0; p.w = 0; p.l = 0; p.num = 0;
	p.b = s;

	Q.push(p);

	while (!Q.empty())
	{
		p = Q.top();
		Q.pop();

		if (Visit[p.b])
		{
			if (L[p.b] == p.l)
			{
				if (wei[p.b] > p.w)
				{
					wei[p.b] = p.w;
					ans[p.b] = p.num;					
				}
			}
			continue;
		}

		Visit[p.b] = true;
		wei[p.b] = p.w;
		L[p.b] = p.l;
		ans[p.b] = p.num;

		for (int i = 0; i < Edges[p.b].size(); i++)
		{
			q.l = p.l + Edges[p.b][i].second;
			q.a = p.b;
			q.b = Edges[p.b][i].first;
			q.w = Edges[p.b][i].second;
			q.num = Edges[p.b][i].third;
			Q.push(q);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;

	Edges.resize(300005);

	int u, v, w;

	for (int i = 1; i <= m; i++)
	{
		cin >> u >> v >> w;

		Edges[u].push_back({ v, w, i });
		Edges[v].push_back({ u, w, i });
	}

	cin >> u;

	dijkstra(u);

	ans[u] = n;

	long long answer = 0;
	for (int i = 1; i <= n; i++)
	{
		answer += wei[i];
	}

	cout << answer << endl;
	for (int i = 1; i <= n; i++)
	{
		if (i != u)
			cout << ans[i] << ' ';
	}
}