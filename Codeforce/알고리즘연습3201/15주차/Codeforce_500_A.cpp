#include <iostream>

using namespace std;

int n, t;
int L[30005];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> t;

	for (int i = 1; i < n; i++)
	{
		cin >> L[i];
	}

	int s = 1;

	while (s < t)
	{
		s += L[s];
	}

	if (s == t)
		cout << "YES";
	else
		cout << "NO";
}