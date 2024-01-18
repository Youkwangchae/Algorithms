#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;

	int commit;	
	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0; i < n; i++)
	{
		cin >> commit;

		if (commit == 0)
		{
			if (pq.size() == 0)
				cout << 0 << "\n";
			else
			{						
				cout << pq.top() << "\n";
				pq.pop();								
			}
		}		
		else
		{			
			pq.push(commit);			
		}		
	}
}