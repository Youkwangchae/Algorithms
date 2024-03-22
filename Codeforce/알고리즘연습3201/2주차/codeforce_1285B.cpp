#include <iostream>
using namespace std;

long long A[100001];
long long P[100001];
long long M[100001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	long long n, i, j, t, total, MN, ans;

	cin >> t;

	while (t > 0) {
		cin >> n;

		for (int i = 1; i <= n; i++)
		{
			cin >> A[i];			
		}

		P[0] = 0;
		for (int i = 1; i <= n; i++)
		{
			P[i] = P[i - 1] + A[i];
		}

		total = P[n];

		ans = 1;
		MN = 0;

		for (int i = 1; i < n; i++)
		{
			M[i] = P[i] - MN;
			MN = min(MN, P[i]);

			if (M[i] >= total)
				ans = 0;
		}

		for (int i = 1; i <= n; i++)
			P[i] -= A[1];

		MN = 0;

		for (i = 2; i <= n; i++)
		{
			M[i] = P[i] - MN;
			MN = min(MN, P[i]);
			if (M[i] >= total)
				ans = 0;
		}

		if (ans == 1) cout << "YES\n";
		else cout << "NO\n";

		t--;
	}
}