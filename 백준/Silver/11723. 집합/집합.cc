#include <iostream>
#include <string>
#include <cstring>
using namespace std;
bool set[20] = { false, };
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	

	int count;
	cin >> count;

	string commit = "";
	int num;	

	for(int i=0;i<count;i++)
	{
		cin >> commit;
		if (commit == "add")
		{
			cin >> num;

			if (!set[num - 1])
			{
				set[num - 1] = true;
			}
		}
		else if (commit == "remove")
		{
			cin >> num;

			if (set[num - 1])
			{
				set[num - 1] = false;
			}
		}
		else if (commit == "check")
		{
			cin >> num;

			cout << set[num - 1] << "\n";
		}
		else if (commit == "toggle")
		{
			cin >> num;		

			set[num - 1] = !set[num - 1];
		}
		else if (commit == "all")
		{
			fill(set, set + 20, true);
		}
		else if (commit == "empty")
		{
			fill(set, set + 20, false);
		}
	}

	fill(set, set + 20, false);
	return 0;
}