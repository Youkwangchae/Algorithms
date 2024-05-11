#include <iostream>
#include <vector>
#include <set>
using namespace std;

#define inf 1e9

class Node
{
public:
	int ansNum;
	int checkNum;
	int tempNum;
	vector<int> AD;
	vector<int> Direction;
	vector<int> result;
};

int n, s, t;

Node myNodes[200001];

void dfs2(int nd, int PT, bool isGoTo)
{
	if (PT)
	{
		if(isGoTo)
			myNodes[nd].ansNum = myNodes[PT].ansNum - 1;
		else
			myNodes[nd].ansNum = myNodes[PT].ansNum + 1;
	}
	else
		myNodes[nd].ansNum = myNodes[nd].tempNum;

	for (int i = 0; i < myNodes[nd].AD.size(); i++)
	{
		if (myNodes[nd].AD[i] != PT)
		{
			dfs2(myNodes[nd].AD[i], nd, myNodes[nd].Direction[i]);
		}
	}
}

int dfs1(int nd, int PT)
{
	int retv = 0;

	for (int i = 0; i < myNodes[nd].AD.size(); i++)
	{
		if (myNodes[nd].AD[i] != PT)
		{
			myNodes[nd].result[i] = dfs1(myNodes[nd].AD[i], nd);			
		}
	}

	for (int i = 0; i < myNodes[nd].AD.size(); i++)
	{
		if (myNodes[nd].AD[i] != PT)
		{
			retv += myNodes[nd].result[i] + myNodes[nd].Direction[i];
		}
	}

	myNodes[nd].tempNum = retv;

	return retv;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n - 1; i++)
	{
		cin >> s >> t;

		myNodes[s].AD.push_back(t);
		myNodes[s].Direction.push_back(0);
		myNodes[s].result.push_back(0);

		myNodes[t].AD.push_back(s);
		myNodes[t].Direction.push_back(1);
		myNodes[t].result.push_back(0);
	}

	dfs1(1, 0);
	dfs2(1, 0, true);

	int answer = inf;

	for (int i = 1; i <= n; i++)
	{
		answer = min(answer, myNodes[i].ansNum);
	}

	cout << answer << endl;

	for (int i = 1; i <= n; i++)
	{
		if (answer == myNodes[i].ansNum)
			cout << i << " ";
	}
}