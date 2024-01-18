#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	priority_queue<int, vector<int>, less<int>> pq;

	int commit;

	for (int i = 0; i < n; i++)
	{
		cin >> commit;

		if (commit == 0)
		{
			if (pq.size() == 0)
			{
				cout << 0 << "\n";
			}
			else
			{
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else
			pq.push(commit);
	}
}