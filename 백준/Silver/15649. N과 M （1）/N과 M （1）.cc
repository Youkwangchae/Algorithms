#include <iostream>
#include <string>
using namespace std;

int n, m;
bool Visit[10];
string str = "";

void solve()
{
	if (str.length() == m*2)
	{
		cout << str;
		cout << endl;
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			if (!Visit[i])
			{
				Visit[i] = true;
				str += (to_string(i) + " ");
				solve();
				str = str.substr(0, str.length() - 2);							
				Visit[i] = false;
			}
		}	
	}
}

int main()
{
	cin >> n >> m;	

	solve();
}