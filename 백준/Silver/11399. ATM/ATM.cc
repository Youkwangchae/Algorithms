#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int count;
	cin >> count;

	vector<int> times;
	int time;

	for (int i = 0; i < count; i++)
	{
		cin >> time;
		times.push_back(time);
	}

	sort(times.begin(), times.end());

	int total = 0;
	for (int i = 0; i < count; i++)
	{
		total += times[i] * (count - i);
	}

	cout << total;
}