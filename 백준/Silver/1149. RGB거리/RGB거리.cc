#include <iostream>
using namespace std;

int Nums[1000][3] = { 0, };
int dp[1000][3] = { 0, };

int n;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	
	int num;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> num;
			Nums[i][j] = num;
		}
	}

	for (int i = 0; i < 3; i++)
		dp[0][i] = Nums[0][i];

	// 그냥 계속 계산을 3방향으로 해야함.	
	int minimum = 0;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 3; j++) {

			// 한 집 당 1000이 최댓값이고, n은 최대 1000이므로 가능한 최대인 값은 1000 * 1000
			minimum = 1000 * 1000;

			for (int k = 0; k < 3; k++)
			{
				if (j == k)
					continue;
				if (dp[i - 1][k] < minimum)
				{
					minimum = dp[i - 1][k];
				}				
			}

			// dp : n-1번째 계산이 맞다고 가정. => 현재 최솟값 + 각 칸의 비용으로 저장.
			// 저장한 값은 다음 칸 비용 계산 시 쓰임.
			dp[i][j] = minimum + Nums[i][j];
		}
	}

	minimum = dp[n - 1][0];
	int tmp = dp[n - 1][1];
	if (dp[n - 1][2] < dp[n - 1][1])
		tmp = dp[n - 1][2];

	if (tmp < minimum)
		minimum = tmp;

	cout << minimum;
}