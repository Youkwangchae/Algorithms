#include <iostream>

using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;

	long long A[5005];
	long long P[5005];

	A[0] = 0;
	long long a;

	P[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a;
		A[i] = a;	
		P[i] = P[i - 1] + A[i];
	}

	double ans = 0.0;

	for (int j = k; j <= n; j++)
	{
		for (int i = 1; i <= n - j + 1; i++)
		{
			ans = max(ans, (double)(P[i + j - 1] - P[i-1])/(double)j);
		}		
	}

	cout.precision(15);
	cout << ans;
}