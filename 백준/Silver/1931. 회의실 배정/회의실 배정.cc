#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

 vector<pair<int, int>> timeVec;
 vector<pair<int, int>> Q;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int start, total;

	for (int i = 0; i < n; i++)
	{
		cin >> start >> total;				
		timeVec.emplace_back(start, total);
	}

	sort(timeVec.begin(), timeVec.end(), [](pair<int, int> a, pair<int, int> b) {
		if (a.second == b.second)
			return a.first < b.first;
		else
			return a.second < b.second;
		});

	int maxCount = 0;
	int numCount = 0;

	int count = 0;
	numCount = 1;

	pair<int, int> current = timeVec[count];

	while (count < timeVec.size() - 1)
	{
		count++;		

		if (current.second <= timeVec[count].first)
		{
			numCount++;
			current = timeVec[count];
		}
		else if (timeVec[count].first == timeVec[count].second)
		{
			numCount++;
			current = timeVec[count];
		}
	}

	if (maxCount < numCount)
		maxCount = numCount;

	cout << maxCount;
}