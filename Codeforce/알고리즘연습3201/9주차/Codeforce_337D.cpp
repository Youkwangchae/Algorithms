#include <iostream>
#include <vector>

using namespace std;

#define inf 1e9

class Node
{
public:
	vector<int> AD;
	int affectNum = inf;
	int tempNum = inf;
	int checkNum = inf;
	bool isAffected = false;
};

Node myNodes[100005];
int n, m, d, temp, a, b;

int dfs1(int nd, int PT)
{	
	myNodes[nd].affectNum = myNodes[nd].tempNum = -inf;

	for (int i = 0; i < myNodes[nd].AD.size(); i++) 
	{
		if (myNodes[nd].AD[i] != PT)
		{
			int retv = dfs1(myNodes[nd].AD[i], nd) + 1;

			if (retv > myNodes[nd].affectNum)
			{
				myNodes[nd].tempNum = myNodes[nd].affectNum;
				myNodes[nd].affectNum = retv;
			}
			else if (retv > myNodes[nd].tempNum)
			{
				myNodes[nd].tempNum = retv;
			}
		}		
	}

	if (myNodes[nd].isAffected)
	{
		if (myNodes[nd].affectNum < 0)
			myNodes[nd].affectNum = 0;
		else
			myNodes[nd].tempNum = max(myNodes[nd].tempNum, 0);
	}

	return myNodes[nd].affectNum;
}

void dfs2(int nd, int parent)
{
	myNodes[nd].checkNum = -inf;

	if (parent)
	{
		if (myNodes[parent].affectNum == myNodes[nd].affectNum + 1)
			myNodes[nd].checkNum = myNodes[parent].tempNum + 1;
		else
			myNodes[nd].checkNum = myNodes[parent].affectNum + 1;

		myNodes[nd].checkNum = max(myNodes[nd].checkNum, myNodes[parent].checkNum + 1);
	}

	for (int i = 0; i < myNodes[nd].AD.size(); i++)
	{
		if (myNodes[nd].AD[i] != parent)
			dfs2(myNodes[nd].AD[i], nd);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m >> d;

	for (int i = 0; i < m; i++)
	{
		cin >> temp;
		myNodes[temp].isAffected = true;
	}

	for (int i = 0; i < n - 1; i++)
	{
		cin >> a >> b;
		myNodes[a].AD.push_back(b);
		myNodes[b].AD.push_back(a);
	}

	dfs1(1, 0);
	dfs2(1, 0);

	int answer = 0;

	for (int i = 1; i <= n; i++)
	{
		if (myNodes[i].affectNum <= d && myNodes[i].checkNum <= d)
			answer++;
	}

	cout << answer;
}