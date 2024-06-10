#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class packet
{
public:
	long long l;
	int w, a, b;
	bool operator < (const packet& k) const
	{
		return l > k.l;
	}
};

priority_queue<packet> Q;

vector<vector<pair<int, int>>> Edges;
int pre[100005], ans[100005], Visit[100005];
long long L[100005];
int n, m, dst1, dst2;

long long answer = 1000000000;

void dijkstra(int s)
{
	packet p, q;
	p.l = 0; p.a = 0; p.w = 0;
	p.b = s;
	Q.push(p);

	while (!Q.empty())
	{
		p = Q.top();
		Q.pop();

		if (Visit[p.b]) continue;
		Visit[p.b] = true;

		L[p.b] = p.l;
		pre[p.b] = p.a;

		for (int i = 0; i < Edges[p.b].size(); i++)
		{
			q.l = L[p.b] + Edges[p.b][i].second;
			q.w = Edges[p.b][i].second;
			q.a = p.b;
			q.b = Edges[p.b][i].first;

			if (q.b == dst2)
				answer = min(answer, q.l);
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

	Edges.resize(100005);

	int a, b, w;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> w;
		Edges[a].push_back({ b, w });
	}

	cin >> dst1 >> dst2;

	for (int i = 1; i <= n; i++)
		L[i] = 1e12;

	dijkstra(dst1);	

	cout << answer;
}