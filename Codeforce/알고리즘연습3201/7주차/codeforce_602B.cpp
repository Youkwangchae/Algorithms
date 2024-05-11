#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, i;
	cin >> n;

	int A[100001];

	for (i = 0; i < n; i++)
		cin >> A[i];

	
	for (i = 0; i < n; i++)	
		if (A[0] != A[i]) break;

	if (i == n) cout << n;
	else
	{
		int minN, maxN, minConsecutive, maxConsecutive;

		if (A[0] < A[i])
		{
			minN = A[0];
			maxN = A[i];

			minConsecutive = i - 1;
			maxConsecutive = i;
		}
		else
		{
			minN = A[i];
			maxN = A[0];

			minConsecutive = i;
			maxConsecutive = i - 1;
		}

		int consecutiveNum = i + 1;
		int consecutiveNumMax = consecutiveNum;

		for (i++; i < n; i++)
		{
			if (A[i] == minN)
			{
				minConsecutive = i;
				consecutiveNum++;
			}
			else if (A[i] == maxN)
			{
				maxConsecutive = i;
				consecutiveNum++;
			}
			else if (A[i] == minN - 1)
			{
				consecutiveNum = i - maxConsecutive;
				maxN = minN;
				minN = A[i];
				maxConsecutive = minConsecutive;
				minConsecutive = i;
			}
			else if (A[i] == maxN + 1)
			{
				consecutiveNum = i - minConsecutive;
				minN = maxN;
				maxN = A[i];
				minConsecutive = maxConsecutive;
				maxConsecutive = i;
			}

			consecutiveNumMax = max(consecutiveNumMax, consecutiveNum);
		}

		cout << consecutiveNumMax;
	}	
}