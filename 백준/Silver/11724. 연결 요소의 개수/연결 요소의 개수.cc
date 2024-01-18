#include <iostream>
#include <vector>
using namespace std;

vector <vector<int>> pos;
vector<bool> visit;

void dfs(int start)
{
	if (visit[start]) return;

	visit[start] = true;

	for (int i : pos[start]) {
		if(!visit[i])
			dfs(i);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	if (m == 0)
	{
		cout << 1;		
	}
	else
	{
		int v1, v2;

		pos.resize(n + 1);
		visit.resize(n + 1, false);

		for (int i = 0; i < m; i++)
		{
			cin >> v1 >> v2;
			pos[v1].push_back(v2);
			pos[v2].push_back(v1);
		}

		int count = 0;
		for (int i = 1; i < n + 1; i++) {
			if (!visit[i]) {
				count++;
				dfs(i);
			}
		}

		cout << count;
	}
}