#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, sum, tempSum;
	vector<int> values;

	cin >> n;
	values.resize(n + 1, 0);

	sum = 0;

	for (int i = 0; i < n; i++)
	{
		cin >> values[i];
		sum += values[i];
	}

	// 상대방의 합보다 더 크게 가질 수 있는 최소한의 코인의 수
	sort(values.begin(), values.end(), greater<int>());

	tempSum = 0;

	if (sum % 2 != 1) sum = sum / 2;
	else sum = (sum - 1) / 2;

	for (int i = 0; i < n; i++)
	{
		tempSum += values[i];

		if (tempSum > sum)
		{
			cout << (i + 1);
			break;
		}		
	}
}