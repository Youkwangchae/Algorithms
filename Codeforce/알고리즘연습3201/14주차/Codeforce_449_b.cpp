#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m, k;
int answer = 0;
class packet
{
public:
	long long l;
	int a, b, w, isTrain;
	bool operator < (const packet& k) const
	{
		if (l != k.l)
			return l > k.l;
		else
		{

			return isTrain > k.isTrain;
		}
	}
};

priority_queue<packet> Q;
vector<vector<pair<int, int>>> Edges;
int Visit[100005];
long long L[100005];

void dijkstra(int s)
{
	packet p, q;
	p.l = 0; p.a = 0; p.w = 0;;
	p.b = s;

	Q.push(p);

	while (!Q.empty())
	{
		p = Q.top();
		Q.pop();

		if (Visit[p.b])
		{
			if (p.isTrain) answer++;
			continue;
		}
		Visit[p.b] = true;

		L[p.b] = p.l;

		for (int i = 0; i < Edges[p.b].size(); i++)
		{
			if (Edges[p.b][i].second < 0)	// train
			{
				q.isTrain = true;
				q.l = p.l - Edges[p.b][i].second;
				q.w = -Edges[p.b][i].second;
				q.a = p.b;
				q.b = Edges[p.b][i].first;
			}
			else
			{
				q.isTrain = false;
				q.l = p.l + Edges[p.b][i].second;
				q.w = Edges[p.b][i].second;
				q.a = p.b;
				q.b = Edges[p.b][i].first;
			}

			Q.push(q);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;

	Edges.resize(100005);

	int a, b, w;

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> w;
		Edges[a].push_back({ b, w });
		Edges[b].push_back({ a, w });
	}

	for (int i = 0; i < k; i++)
	{
		cin >> a >> b;
		Edges[1].push_back({ a, -b });
	}

	dijkstra(1);

	cout << answer;
	return 0;
}