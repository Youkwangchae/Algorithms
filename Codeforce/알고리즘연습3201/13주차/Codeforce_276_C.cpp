#include <iostream>
#include <algorithm>
using namespace std;

int n, q;

long long Nums[200005], Index[200005];

int main()
{
	cin >> n >> q;

	for (int i = 1; i <= n; i++)
	{
		cin >> Nums[i];
		Index[i] = 0;
	}

	int l, r;

	for (int i = 1; i <= q; i++)
	{
		cin >> l >> r;
		
		Index[l - 1]++; Index[r]--;
	}

	for (int i = 1; i <= n; i++)
		Index[i] += Index[i - 1];

	sort(Nums + 1, Nums + n + 1, greater<int>());
	sort(Index, Index + n + 1, greater<int>());
		
	long long answer = 0;

	for (int i = 1; i <= n; i++)
		answer += (Index[i-1] * Nums[i]);
	cout << answer;

	return 0;
}