#include <iostream>
#include <string>
using namespace std;

int dp[1001][1001] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str1, str2;
	cin >> str1 >> str2;

	int n = str1.length();	
	int m = str2.length();
	int maxNum = 0;

	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < m + 1; j++)
		{
			if (str1[i-1] == str2[j-1])
				dp[i][j] = dp[i-1][j-1] + 1;
			else
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);

			if (dp[i][j] > maxNum)
				maxNum = dp[i][j];
		}
	}

	cout << maxNum;
}