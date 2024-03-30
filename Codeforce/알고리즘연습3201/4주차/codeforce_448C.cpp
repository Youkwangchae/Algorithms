#include <iostream>
using namespace std;

int fence(int row[], int n) {
	int mini, ans;

	mini = 1000000005;
	for (int i = 0; i < n; i++)
		mini = min(mini, row[i]);
	for (int i = 0; i < n; i++)
		row[i] -= mini;
	ans = mini;
	
	int count = 0;
	int temp;

	while (count < n)
	{
		while (count < n && row[count] == 0) count++;
		if (count == n) break;
		temp = count;

		while (temp + 1 < n && row[temp + 1] > 0) temp++;
		ans += fence(row + count, temp - count + 1);
	}
	return min(n, ans);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;

	int row[5001];

	int mini = 1000000005;

	if (n == 1) {
		cout << 1;
	}
	else {

		for (int i = 0; i < n; i++)
		{
			cin >> row[i];
		}

		cout << fence(row, n);
	}
}