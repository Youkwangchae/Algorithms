#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	
	int n;
	cin >> n;

	if (n > 2)
	{
		if (n % 2 == 0)
			cout << "YES";
		else
			cout << "NO";
	}
	else
	{
		cout << "NO";
	}
}