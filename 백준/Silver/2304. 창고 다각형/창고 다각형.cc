#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int n;
vector<pair<int, int>> vec;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	int a, b;

	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		vec.push_back({ a, b });
	}

	sort(vec.begin(), vec.end());

	stack<pair<int, int>> S;

	S.push(vec[0]);

	int maxH = 0;

	for (int i = 0; i < n; i++)
	{
		int L = vec[i].first;
		int H = vec[i].second;

		if (!S.empty() && S.top().second < H)
		{
			if (maxH < H)
			{
				while (S.top().second != maxH)
				{
					S.pop();
				}				
			}
			else
			{
				while (S.top().second < H)
				{
					S.pop();
				}
			}
		}

		maxH = max(maxH, H);
		S.push(vec[i]);
	}

	int ans = 0;

	while (!S.empty())
	{
		auto cur = S.top();
		S.pop();

		ans += cur.second;

		if (S.empty()) break;

		if(cur.second < S.top().second)
			ans += (cur.first - S.top().first - 1) * cur.second;
		else
			ans += (cur.first - S.top().first - 1) * S.top().second;
	}

	cout << ans;
}