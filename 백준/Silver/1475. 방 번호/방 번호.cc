#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vector<int> vec(10, 0);

	int n; cin >> n;
	string str = to_string(n);

	for (int i = 0; i < str.length(); i++)
	{
		vec[str[i] - '0']++;
	}	

	int maxCount = vec[6] + vec[9] - (vec[6] + vec[9]) / 2;

	for (int i = 0; i < 10; i++)
	{
		if (i == 6 || i == 9) continue;
		maxCount = max(maxCount, vec[i]);
	}

	cout << maxCount;
	return 0;
}