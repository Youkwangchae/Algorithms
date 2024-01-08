#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string str;
	int num;

	cin >> str;
	cin >> num;

	cout << str[num - 1];
}