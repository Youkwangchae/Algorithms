#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, x;
	cin >> n >> x;

	int tmp;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		if (tmp < x) cout << tmp << " ";					
	}

	return 0;
}