#include <iostream>
#include <string>
using namespace std;

int n, m;

void solve(string s)
{
	if (s.length() == m)
	{
		cout << s << '\n';		
		return;
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{			
			solve(s + to_string(i) + " ");			
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

	m += m;

	solve("");
}