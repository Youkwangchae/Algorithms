#include <iostream>

using namespace std;

int n, a;

class Num
{
public:
	int input;
	int Len = 1;
	int DLen = 1;
	int result;
};


int LeftMax;
int RightMin;

Num myNums[100005];

int LISRemember[100005];	// 같은 LIS일 때 제일 작은 Input값. (기억할 Input값)
int LDSRemember[100005];

// 이분탐색logn
int binarySearch(int start, int end, int value) {
	while (start < end) {
		int mid = (start + end) / 2;
		if (LISRemember[mid] >= value)
			end = mid;
		else
			start = mid + 1;
	}

	return start;
}

// 이분탐색logn
int binaryLDSSearch(int start, int end, int value) {
	while (start < end) {
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

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> a;
		myNums[i].input = a;			

		LISRemember[i] = 100001;// 각 LIS 별 최소값 갖기 위해 미리 초기화.
	}	

	myNums[1].Len = 1;
	myNums[n].DLen = 1;

	LISRemember[1] = myNums[1].input;
	LDSRemember[1] = 1;

	int myLISLen = 1;			// 최종 해당 문제의 LIS의 길이.

	for (int i = 1; i <= n; i++)
	{
		int index = binarySearch(1, n, myNums[i].input);
		LISRemember[index] = min(LISRemember[index], myNums[i].input);

		myNums[i].Len = index;
		myLISLen = max(myLISLen, index);

		int DIndex = binaryLDSSearch(1, n, myNums[n - i + 1].input);
		LDSRemember[DIndex] = max(LDSRemember[DIndex], myNums[n - i + 1].input);

		myNums[n - i + 1].DLen = DIndex;
	}

	for (int i = 1; i <= n; i++)
	{
		if (myNums[i].Len + myNums[i].DLen == myLISLen + 1)
			myNums[i].result = 3;	// Len + DLen이 LIS 길이에 + 1이 아니면 LIS에 아예 포함이 안되는 것.		
		else
			myNums[i].result = 1;
	}

	LeftMax = 0;	

	for (int i = 1; i <= n; i++)
	{		
		if (myNums[i].result != 1) {
			if (myNums[i].input <= LeftMax)
				myNums[i].result = 2;

			LeftMax = max(LeftMax, myNums[i].input);
		}		
	}

	RightMin = 100001;
	for (int i = n; i >= 1; i--)
	{
		if (myNums[i].result != 1) {
			if (myNums[i].input >= RightMin)
				myNums[i].result = 2;

			RightMin = min(RightMin, myNums[i].input);
		}
	}

	for (int i = 1; i <= n; i++)
		cout << myNums[i].result;
}