#include <iostream>
using namespace std;
int n, m;

long long L[105][105];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	int a, b;
	long long w;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			L[i][j] = 1e10;
	}

	for (int i = 1; i <= m; i++)
	{
		cin >> a >> b >> w;
		L[a][b] = min(L[a][b], w);
	}

	for (int k = 1; k <= n; k++)
	{
		L[k][k] = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{		
				L[i][j] = min(L[i][j], L[i][k] + L[k][j]);
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (L[i][j] == 1e10) L[i][j] = 0;				
			cout << L[i][j] << ' ';
		}
		cout << '\n';
	}
}