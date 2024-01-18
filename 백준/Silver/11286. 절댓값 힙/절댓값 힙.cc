#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	priority_queue<int, vector<int>, greater<int>> plus_pq;
	priority_queue<int, vector<int>, greater<int>> minus_pq;

	int commit;

	for (int i = 0; i < n; i++)
	{
		cin >> commit;

		if (commit == 0)
		{
			if (plus_pq.size() == 0 && minus_pq.size() == 0)
			{
				cout << 0 << "\n";
			}
			else
			{
				if (plus_pq.size() == 0)
				{
					cout << (-1) * (minus_pq.top()) << "\n";
					minus_pq.pop();
				}
				else if (minus_pq.size() == 0)
				{
					cout << plus_pq.top() << "\n";
					plus_pq.pop();
				}
				else {

					if (plus_pq.top() < minus_pq.top())
					{
						cout << plus_pq.top() << "\n";
						plus_pq.pop();
					}
					else
					{
						cout << (-1) * (minus_pq.top()) << "\n";
						minus_pq.pop();
					}
				}
			}
		}
		else
		{
			if (commit > 0)
				plus_pq.push(commit);
			else {
				commit *= -1;
				minus_pq.push(commit);
			}
		}
	}
}