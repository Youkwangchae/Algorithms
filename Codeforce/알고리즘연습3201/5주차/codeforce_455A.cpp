#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	long long n, Val[2][100001];
	vector<int> A;

	cin >> n;
	A.resize(n, 0);

	for (int i = 0; i < n; i++)
		cin >> A[i];

	sort(A.begin(), A.end());

	Val[0][0] = A[0]; Val[1][0] = 0;

	for (int i = 1; i < n; i++)
	{
		if (A[i] == A[i - 1])
		{
			Val[0][i] = Val[0][i - 1] + A[i];
			Val[1][i] = Val[1][i - 1];			
		}
		else
		{
			if (A[i] - A[i - 1] == 1)
			{
				Val[0][i] = Val[1][i - 1] + A[i];
			}
			else
				Val[0][i] = max(Val[0][i - 1], Val[1][i - 1]) + A[i];
			Val[1][i] = max(Val[0][i - 1], Val[1][i - 1]);
		}
	}

	cout << max(Val[0][n-1], Val[1][n - 1]);
}