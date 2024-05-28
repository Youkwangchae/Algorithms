#include <iostream>
#include <string>
using namespace std;

long long n, m, s, lf, rg;
char inputStr[1000005];
string str;

class myNode
{
public:
	long long fourNodes, sevenNodes;
	long long fromFourToSeven;
	long long fromSevenToFour;
	bool isReversed = false;
};

myNode myNodes[4000005];

void building(long long nd, long long left, long long right, char input[]) {
	if (left == right)
	{
		myNodes[nd].fromFourToSeven = 1;
		myNodes[nd].fromSevenToFour = 1;

		if (input[left - 1] == '4')
		{
			myNodes[nd].fourNodes = 1;
			myNodes[nd].sevenNodes = 0;
		}
		else if (input[left - 1] == '7')
		{
			myNodes[nd].fourNodes = 0;
			myNodes[nd].sevenNodes = 1;
		}

		return;
	}

	long long mid = (left + right) / 2;

	building(nd * 2, left, mid, input);
	building(nd * 2 + 1, mid + 1, right, input);

	myNodes[nd].fourNodes = myNodes[nd * 2].fourNodes + myNodes[nd * 2 + 1].fourNodes;
	myNodes[nd].sevenNodes = myNodes[nd * 2].sevenNodes + myNodes[nd * 2 + 1].sevenNodes;

	myNodes[nd].fromFourToSeven = max(myNodes[nd * 2].fourNodes + myNodes[nd * 2 + 1].sevenNodes, max(myNodes[nd * 2].fourNodes + myNodes[nd * 2 + 1].fromFourToSeven, myNodes[nd * 2].fromFourToSeven + myNodes[nd * 2 + 1].sevenNodes));
	myNodes[nd].fromSevenToFour = max(myNodes[nd * 2].sevenNodes + myNodes[nd * 2 + 1].fourNodes, max(myNodes[nd * 2].sevenNodes + myNodes[nd * 2 + 1].fromSevenToFour, myNodes[nd * 2].fromSevenToFour + myNodes[nd * 2 + 1].fourNodes));
}

void checkReverse(long long nd, long long left, long long right)
{
	if (myNodes[nd].isReversed)
	{
		swap(myNodes[nd * 2].fourNodes, myNodes[nd * 2].sevenNodes);
		swap(myNodes[nd * 2].fromFourToSeven, myNodes[nd * 2].fromSevenToFour);

		swap(myNodes[nd * 2 + 1].fourNodes, myNodes[nd * 2 + 1].sevenNodes);
		swap(myNodes[nd * 2 + 1].fromFourToSeven, myNodes[nd * 2 + 1].fromSevenToFour);

		myNodes[nd * 2].isReversed = !myNodes[nd * 2].isReversed;
		myNodes[nd * 2 + 1].isReversed = !myNodes[nd * 2 + 1].isReversed;

		myNodes[nd].isReversed = false;
	}
}

void update(long long nd, long long left, long long right, long long first, long long second)
{
	if (first <= left && second >= right)
	{
		swap(myNodes[nd].fourNodes, myNodes[nd].sevenNodes);
		swap(myNodes[nd].fromFourToSeven, myNodes[nd].fromSevenToFour);
		myNodes[nd].isReversed = !myNodes[nd].isReversed;

		return;
	}

	checkReverse(nd, left, right);
	long long mid = (left + right) / 2;

	if (first <= mid)
	{
		update(nd * 2, left, mid, first, second);
	}
	if (second > mid)
	{
		update(nd * 2 + 1, mid + 1, right, first, second);
	}

	myNodes[nd].fourNodes = myNodes[nd * 2].fourNodes + myNodes[nd * 2 + 1].fourNodes;
	myNodes[nd].sevenNodes = myNodes[nd * 2].sevenNodes + myNodes[nd * 2 + 1].sevenNodes;

	myNodes[nd].fromFourToSeven = max(myNodes[nd * 2].fourNodes + myNodes[nd * 2 + 1].fromFourToSeven, myNodes[nd * 2].fromFourToSeven + myNodes[nd * 2 + 1].sevenNodes);
	myNodes[nd].fromSevenToFour = max(myNodes[nd * 2].sevenNodes + myNodes[nd * 2 + 1].fromSevenToFour, myNodes[nd * 2].fromSevenToFour + myNodes[nd * 2 + 1].fourNodes);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> inputStr;

	building(1, 1, n, inputStr);

	for (int i = 1; i <= m; i++)
	{
		cin >> str;
		if (str == "count")
		{
			cout << myNodes[1].fromFourToSeven << '\n';
		}
		else
		{
			cin >> lf >> rg;
			update(1, 1, n, lf, rg);
		}
	}
	return 0;
}