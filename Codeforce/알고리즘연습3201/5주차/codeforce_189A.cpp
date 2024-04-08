#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, L[3];
	int ans[3][5000];

	cin >> n >> L[0] >> L[1] >> L[2];

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i - L[j] < 0)
				ans[j][i] = -1;
			else if (i == L[j])
				ans[j][i] = 1;
			else
			{				
				if (max(max(ans[0][i - L[j]], ans[1][i - L[j]]), ans[2][i - L[j]]) == -1)
					ans[j][i] = -1;
				else
					ans[j][i] = max(max(ans[0][i - L[j]], ans[1][i - L[j]]), ans[2][i - L[j]]) + 1;
			}				
		}
	}

	cout << max(max(ans[0][n], ans[1][n]), ans[2][n]);
}