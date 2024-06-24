#include <iostream>
#include <algorithm>
long long n, m;

using namespace std;

long long A[1000005];
long long total = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;

	long long temp;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		A[i] = temp;
		total += temp;
	}	

	if (m == total)
	{
		cout << 0;
		return 0;
	}

	sort(A, A + n);

	long long l = 0;
	long long r = A[n - 1];
	unsigned long long mid = 0;
	unsigned long long answer = 0;	

	while (l <= r)
	{
		mid = (l + r) / 2;

		long long lenSum = 0;

		for (int i = n - 1; i >= 0; i--)
		{
			if (A[i] <= mid) break;
			lenSum += A[i] - mid;
		}

		if (lenSum == 0)
		{
			for (int i = 1; i < A[0]; i++)
			{
				lenSum += n;
				if (lenSum >= m)
				{
					answer = A[0] - i;
					break;
				}
			}

			break;
		}

		if (lenSum > m)
		{
			if (answer < mid)
				answer = mid;
			l = mid + 1;
		}
		else if(lenSum < m)
		{				
			r = mid - 1;
		}
		else
		{
			answer = mid;
			break;
		}
	}	

	if (answer > A[n - 1]) answer = A[n - 1];
	else if (answer < 0) answer = 0;

	cout << answer;
}