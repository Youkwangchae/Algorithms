#include <iostream>
#include <vector>
#include <cstring>
#define INF 1e9

using namespace std;
int N, E, W;
vector<int> edge[3];
long long dist[510] = { 0, };

void bellman(int start) {
	for (int i = 1; i <= N; i++) dist[i] = INF;
	memset(dist, -1, sizeof(dist));

	dist[start] = 0;

	for (int i = 1; i <= N - 1; i++) {
		for (int j = 0; j < edge[0].size(); j++) {
			int cur = edge[0][j];
			int to = edge[1][j];
			int cost = edge[2][j];
			if (dist[cur] == INF) continue;
			if (dist[cur] + cost < dist[to]) {
				dist[to] = dist[cur] + cost;
			}
		}
	}
	for (int i = 0; i < edge[0].size(); i++) {
		int cur = edge[0][i];
		int to = edge[1][i];
		int cost = edge[2][i];
		if (dist[cur] == INF) continue;
		if (dist[cur] + cost < dist[to]) {
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> N >> E >> W;
		int str, end, val;
		for (int i = 0; i < E; i++) {
			cin >> str >> end >> val;
			edge[0].push_back(str); edge[0].push_back(end);
			edge[1].push_back(end);	edge[1].push_back(str);
			edge[2].push_back(val); edge[2].push_back(val);
		}
		for (int i = 0; i < W; i++) {
			cin >> str >> end >> val;
			edge[0].push_back(str);
			edge[1].push_back(end);
			edge[2].push_back(-val);
		}

		bellman(1);
		edge[0].clear();
		edge[1].clear();
		edge[2].clear();
	}
}