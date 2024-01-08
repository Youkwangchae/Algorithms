#include <iostream>
#include <string>
using namespace std;

int stack[10000];
int stackCount = -1;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int count;
	cin >> count;

	string commit;
	int num;

	while (count > 0)
	{	
		cin >> commit;
		if (commit == "push")
		{
			cin >> num;
			stack[++stackCount] = num;
			count--;
		}
		else if (commit == "pop")
		{
			if (stackCount == -1)
				cout << -1 << "\n";
			else {
				cout << stack[stackCount--] << "\n";
			}
			count--;
		}
		else if (commit == "size")
		{
			cout << (stackCount + 1) << "\n";
			count--;
		}
		else if (commit == "empty")
		{
			cout << ((stackCount == -1) ? 1 : 0) << "\n";
			count--;
		}
		else if (commit == "top") {
			if (stackCount == -1)
				cout << -1 << "\n";
			else {
				cout << stack[stackCount] << "\n";
			}
			count--;
		}
	}	
}