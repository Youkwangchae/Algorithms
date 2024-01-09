#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	map<string, int> not_heard;
	map<int, string> check_heard;

	map<string, int> not_seen;
	map<int, string> check_seen;

	int n, m;

	cin >> n >> m;

	string str;

	for (int i = 0; i < n; i++)
	{
		cin >> str;

		not_heard.insert(pair<string, int>(str,i));
		check_heard.insert(pair<int, string>(i, str));
	}

	for (int i = 0; i < m; i++)
	{
		cin >> str;

		not_seen.insert(pair<string, int>(str, i));
		check_seen.insert(pair<int, string>(i, str));
	}

	int thingNum = 0;
	vector<string> ansVec;

	if (n > m)
	{
		for (int i = 0; i < m; i++)
		{
			if (not_heard.count(check_seen[i]) != 0)
			{
				thingNum++;
				ansVec.push_back(check_seen[i]);				
			}
		}
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			if (not_seen.count(check_heard[i]) != 0)
			{
				thingNum++;
				ansVec.push_back(check_heard[i]);
			}
		}
	}	

	cout << thingNum << "\n";

	sort(ansVec.begin(), ansVec.end());
	
	for (int i = 0; i < thingNum; i++)
		cout << ansVec[i] << "\n";
}