#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class packet
{
public:
	long long l;	// 여태까지 온 length.
	int a, b, w;	// a에서 b로 가는 엣지의 w.
	bool operator < (const packet& k) const	// prioiry queue에서 작은게 먼저 앞으로 오기 위한 operator overriding
	{
		return l > k.l;
	}
};

priority_queue<packet> Q;

int Visit[100005], pre[100005], wei[100005], ans[100005];
long long L[100005];
vector<vector<pair<int, int>>> Edges;

int n, m;

void dijkstra(int s)
{
	packet p, q;
	
	p.l = 0; p.w = 0; p.a = 0;
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
		wei[p.b] = p.w;

		for (int i = 0; i < Edges[p.b].size(); i++)
		{
			q.l = L[p.b] + Edges[p.b][i].second;
			q.w = Edges[p.b][i].second;
			q.a = p.b;
			q.b = Edges[p.b][i].first;
			Q.push(q);
		}
	}
}

int main()
{
	cin >> n >> m;

	int a, b, w;	

	Edges.resize(100005);

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> w;				
		Edges[a].push_back({ b, w });
		Edges[b].push_back({ a, w });
	}

	for (int i = 1; i <= n; i++) L[i] = 1e12;

	dijkstra(1);

	if (L[n] == 1e12) cout << "-1";
	else
	{
		int i = 1; ans[i] = n;
		while (ans[i] != 1)
		{
			i++;
			ans[i] = pre[ans[i - 1]];
		}

		while (i > 1)
		{
			cout << ans[i] << " ";
			i--;
		}

		cout << ans[1];		
	}

	return 0;
}