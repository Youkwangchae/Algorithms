#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> arr;
vector<int> dp;
priority_queue<int, vector<int>> Q;

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;

	dp.assign(n, 1);

	int num;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		arr.push_back(num);
	}

	int check = 0;
	int count = 1;

	for (int i = 0; i < n; i++)
	{
		count = 0;
		check = arr[i];

		for (int j = 0; j < i; j++)
		{
			if (arr[j] < check)
			{
				if(count < dp[j])
				count = dp[j];
			}
		}

		dp[i] = count + 1;
	}

	cout << *max_element(dp.begin(), dp.end());
}