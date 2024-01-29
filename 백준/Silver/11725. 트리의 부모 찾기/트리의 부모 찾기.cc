#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

queue<int> Q;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, a, b;
	cin >> n;

	vector<vector<int>> V(n+1);
	vector<int> parent(n + 1, 0);	

	for (int i = 2; i < n + 1; i++)
	{
		cin >> a >> b;				
		V[a].push_back(b);
		V[b].push_back(a);
	}

	Q.emplace(1);

	int num;	
	while (!Q.empty())
	{
		num = Q.front();
		Q.pop();
	
		for (int cur : V[num])
		{
			if (parent[cur] == 0)
			{
				parent[cur] = num;
				Q.emplace(cur);				
			}
		}
	}

	for (int i = 2; i < n + 1; i++)
		cout << parent[i] << "\n";
}