#include <iostream>

using namespace std;

int main()
{
	int k2, k3, k5, k6;

	cin >> k2;
	cin >> k3;
	cin >> k5;
	cin >> k6;

	long long sum = 0;

	int min256 = min(min(k2, k5), min(k5, k6));

	if (min256 == k2)
	{
		sum = min256 * 256;
	}
	else
	{
		int min32 = min(k2 - min256, k3);

		if (min32 == k3)
		{
			sum = min256 * 256 + min32 * 32;
		}
		else
		{
			sum = min256 * 256 + (k2 - min256) * 32;
		}
	}

	cout << sum;
}