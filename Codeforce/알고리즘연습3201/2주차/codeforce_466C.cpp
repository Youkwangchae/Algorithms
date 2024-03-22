#include <iostream>
using namespace std;

long long P[500005];
long long A[500005];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;

	cin >> n;

	P[0] = 0;
	A[0] = 0;

	long long a = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a;
		A[i] = a;
		P[i] = P[i - 1] + A[i];
	}

	long long ans = 0;

	if (P[n] % 3 != 0) cout << 0;
	else
	{
		long long total3 = P[n] / 3;
		long long ans2 = 0;
		for (int i = 1; i < n; i++)
		{
			if (P[i] == total3 * 2)
			{
				ans += ans2;
			}
			if (P[i] == total3)
			{
				ans2++;
			}			
		}
		//for (int j = 1; j < n; j++)
		//{
		//	for (int i = 1; i < n - j; i++)
		//	{
		//		//  哭率 P[j]
		//		//  啊款单 P[j+i] - P[j]
		//		//  坷弗率 P[n] - P[j+i]
		//		if (P[j] == (P[j + i] - P[j]) && P[j] == (P[n] - P[j + i]))
		//			ans++;				
		//	}
		//}

		cout << ans;
	}		
}