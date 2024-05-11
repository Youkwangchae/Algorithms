#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int destroyCount[100001];
vector<pair<int, int>> beacon;

// ÀÌºÐÅ½»ölogn
int binarySearch(int start, int end, long long value) {
	while (start < end) {
		int mid = (start + end) / 2;
		if (beacon[mid].first >= value)
			end = mid;
		else
			start = mid + 1;
	}

	return start;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	beacon.push_back({ 0, 0 });

	int A, B;
	for (int i = 1; i <= n; i++)
	{
		cin >> A >> B;
		beacon.push_back({ A, B });
	}		

	sort(beacon.begin(), beacon.end());
	
	// n * logn
	for (int i = 1; i <= n; i++)
	{		
		int power = beacon[i].first - beacon[i].second;	

		int nextPos = binarySearch(1, n, power) - 1;

		destroyCount[i] = (i - nextPos - 1 + destroyCount[nextPos]);
	}

	int answer = 87654321;
	for (int i = 1; i <= n; i++)
		answer = min(answer, destroyCount[i] + n - i);

	cout << answer;
}