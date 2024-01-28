#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int tri[500][500] = { 0, };
int dp[500][500] = { 0, };

int main()
{
	int n;
	cin >> n;

	int num;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i + 1; j++) {
			cin >> num;
			tri[i][j] = num;
		}
	}

	dp[0][0] = tri[0][0];
	dp[1][0] = dp[0][0] + tri[1][0];
	dp[1][1] = dp[0][0] + tri[1][1];

	int maximum = 0;
	for (int i = 2; i < n; i++)
	{
		dp[i][0] = dp[i-1][0] + tri[i][0];		
		for (int j = 0; j < i - 1; j++)
		{
			maximum = max(dp[i - 1][j], dp[i - 1][j+1]);

			dp[i][j + 1] = maximum + tri[i][j + 1];
		}
		dp[i][i] = dp[i - 1][i - 1] + tri[i][i];
	}

	priority_queue<int, vector<int>> pq;

	for (int i = 0; i < n; i++)
		pq.emplace(dp[n-1][i]);

	cout << pq.top();
}