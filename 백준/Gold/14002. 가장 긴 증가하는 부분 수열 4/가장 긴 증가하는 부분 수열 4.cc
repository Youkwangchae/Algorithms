#include <iostream>

using namespace std;

int n;

class Num
{
public:
	int N;
	int Len = 0;
	int DLen = 0;
};

Num myNums[1005];

int LISRemember[1005];
int LDSRemember[1005];

int myAnswer[1005];

int binarySearch(int start, int end, int value)
{
	while (start < end)
	{
		int mid = (start + end) / 2;
		if (LISRemember[mid] >= value)
			end = mid;
		else
			start = mid + 1;
	}

	return start;
}

int binaryLDSSearch(int start, int end, int value)
{
	while (start < end)
	{
		int mid = (start + end) / 2;
		if (LDSRemember[mid] <= value)
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
	cout.tie(0);

	cin >> n;

	int maxNum = 0;

	for (int i = 1; i <= n; i++)
	{
		cin >> myNums[i].N;
		LISRemember[i] = 1005;

		maxNum = max(maxNum, myNums[i].N);
	}

	LISRemember[1] = myNums[1].N;
	LDSRemember[1] = 1;

	/*myNums[1].Len = 1;
	myNums[n].DLen = 1;*/

	int myLISLen = 1;

	for (int i = 1; i <= n; i++)
	{
		int index = binarySearch(1, n, myNums[i].N);
		LISRemember[index] = min(LISRemember[index], myNums[i].N);

		myLISLen = max(myLISLen, index);
		myNums[i].Len = index;

		int DIndex = binaryLDSSearch(1, n, myNums[n - i + 1].N);
		LDSRemember[DIndex] = max(LDSRemember[DIndex], myNums[n - i + 1].N);

		myNums[n - i + 1].DLen = DIndex;
	}

	cout << myLISLen << '\n';
	
	int tempLen = 1;

	for (int i = 1; i <= n; i++)
	{
		if (myNums[i].Len + myNums[i].DLen == myLISLen + 1 && myNums[i].Len == tempLen)
		{
			cout << myNums[i].N << ' ';
			tempLen++;
		}
	}	
}