#include <iostream>

using namespace std;

int myNums[1000005];
int LISRemember[1000005];

int binarySearch(int start, int end, int val) {
	while (start < end) {
		int mid = (start + end) / 2;

		if (LISRemember[mid] >= val)
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

	int temp;
	for (int i = 1; i <= n; i++)
	{
		cin >> temp;
		myNums[i] = temp;

		LISRemember[i] = 1000001;
	}

	int myLen = 1;

	for (int i = 1; i <= n; i++)
	{
		int len = binarySearch(1, n, myNums[i]);	

		LISRemember[len] = min(LISRemember[len], myNums[i]);				
		myLen = max(myLen, len);
	}

	cout << myLen;
}