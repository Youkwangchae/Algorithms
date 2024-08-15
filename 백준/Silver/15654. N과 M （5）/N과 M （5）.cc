#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n, m;
int arr[9];
bool Visit[10000];

void solve(string s, int count)
{
	if (count == m)
	{
		cout << s << '\n';		
		return;
	}
	else
	{
		for (int i = 0; i < n; i++)
		{			
			if (!Visit[arr[i]])
			{
				Visit[arr[i]] = true;
				solve(s + to_string(arr[i]) + " ", count + 1);
				Visit[arr[i]] = false;
			}			
		}	
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;	

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);

	solve("", 0);
}