#include <iostream>

using namespace std;

int n;

int LISRemember[1005];
int SumRemember[1005];

class Num
{
public:
	int N;
	int Len = 1;
	int Sum;
};

Num myNums[1005];

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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> myNums[i].N;
		LISRemember[i] = 1005;
		SumRemember[i] = 0;
	}

	myNums[1].Len = 1;

	LISRemember[1] = myNums[1].N;	

	for (int i = 1; i <= n; i++)
	{
		int index = binarySearch(1, n, myNums[i].N);
		LISRemember[index] = min(LISRemember[index], myNums[i].N);

		myNums[i].Len = index;		
		
		int k = i - 1;
		int kIndex = 0;
		int checkSum = 0;
		while (k >= 1)
		{
			if (myNums[k].Len < index)
			{
				if (myNums[k].N < myNums[i].N && checkSum < myNums[k].Sum)
				{
					checkSum = myNums[k].Sum;
					kIndex = k;
				}
			}
			k--;
		}

		SumRemember[i] = (myNums[i].N + SumRemember[kIndex]);
		myNums[i].Sum = SumRemember[i];
	}

	int answer = 0;

	for (int i = 1; i <= n; i++)
	{
		answer = max(answer, myNums[i].Sum);
	}

	cout << answer;
	return 0;
}