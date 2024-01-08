#include <iostream>
#include <string>
using namespace std;

int queue[10000];
int queueCount = -1;
int lastIndex = -1;
int queueNums = 0;

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
			queue[++queueCount] = num;
			queueNums++;
			count--;
		}
		else if (commit == "pop")
		{
			if (queueCount == -1 || queueNums == 0)
				cout << -1 << "\n";
			else {
				queueNums--;
				cout << queue[++lastIndex] << "\n";
			}
			count--;
		}
		else if (commit == "size")
		{
			cout << queueNums << "\n";
			count--;
		}
		else if (commit == "empty")
		{
			cout << ((queueNums == 0) ? 1 : 0) << "\n";
			count--;
		}
		else if (commit == "front") {
			if (queueCount == -1 || queueNums == 0)
				cout << -1 << "\n";
			else {
				cout << queue[lastIndex + 1] << "\n";
			}
			count--;
		}
		else if (commit == "back") {
			if (queueCount == -1 || queueNums == 0)
				cout << -1 << "\n";
			else {
				cout << queue[queueCount] << "\n";
			}
			count--;
		}
	}
}