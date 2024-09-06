#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string str;
	cin >> str;

	int len = str.length();

	vector<int> alphabet(26, 0);

	for (int i = 0; i < len; i++)
	{
		alphabet[str[i] - 'a']++;
	}

	for (int i = 0; i < 26; i++)
	{
		cout << alphabet[i] << ' ';
	}

	return 0;
}