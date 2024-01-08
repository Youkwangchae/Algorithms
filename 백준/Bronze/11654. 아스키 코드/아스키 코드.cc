#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	char s;
	cin >> s;
	cout << s - 'A' + 65;
}