#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

vector<pair<int, int>> V[10001];
bool visited[10000] = { false, };

int res = 0;
int endPoint = 0;

void dfs(int start, int len) {
	if (visited[start]) return;

	visited[start] = true;

	if (res < len) {
		res = len;
		endPoint = start;
	}

	for (int i = 0; i < V[start].size(); i++)
	{
		dfs(V[start][i].first, len + V[start][i].second);
	}
}

int main()
{
	int n;
	cin >> n;

	if (n == 1)
	{
		cout << 0;
		return 0;
	}

	int parent, child, cost;

	// edge 수는 n-1.
	for (int i = 0; i < n - 1; i++)
	{
		cin >> parent >> child >> cost;

		V[parent].push_back({ child, cost });
		V[child].push_back({ parent, cost });
	}
	
	dfs(1, 0);

	memset(visited, false, sizeof(visited));

	dfs(endPoint, 0);

	cout << res;
}