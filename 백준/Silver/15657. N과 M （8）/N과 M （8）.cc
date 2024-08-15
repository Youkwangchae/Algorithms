#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n, m;
int arr[9];

void solve(string s, int count, int x)
{
	if (count == m)
	{
		cout << s << '\n';		
		return;
	}
	else
	{
		for (int i = x; i < n; i++)
		{			
			solve(s + to_string(arr[i]) + " ", count + 1, i);
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

	solve("", 0, 0);
}