#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	int arr[4] = { 0, 0, 0, 0 };

	cin >> n;

	int childSize = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> childSize;

		arr[childSize - 1]++;
	}

	int sum = (arr[3] + arr[2]);

	arr[0] -= arr[2];
	if (arr[0] < 0) arr[0] = 0;

	if (arr[1] % 2 != 1)
	{
		sum += arr[1] / 2;
		arr[1] = 0;
	}
	else
	{
		sum += (arr[1] + 1) / 2;
		arr[0] -= 2;
	}
	if (arr[0] > 0)
	{
		if (arr[0] % 4 == 0)
		{
			sum += arr[0] / 4;
		}
		else
			sum += arr[0] / 4 + 1;
	}

	cout << sum;
}