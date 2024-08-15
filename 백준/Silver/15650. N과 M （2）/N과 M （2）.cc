#include <iostream>
#include <string>
using namespace std;

int n, m;
bool Visit[10];
string str = "";

void solve(int x)
{
	if (str.length() == m*2)
	{
		cout << str;
		cout << endl;
	}
	else
	{
		for (int i = x; i <= n; i++)
		{
			if (!Visit[i])
			{
				Visit[i] = true;
				str += (to_string(i) + " ");
				solve(i + 1);
				str = str.substr(0, str.length() - 2);							
				Visit[i] = false;
			}
		}	
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;		

	solve(1);
}