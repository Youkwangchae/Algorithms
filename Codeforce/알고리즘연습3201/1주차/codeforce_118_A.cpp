#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	string str;
	
	cin >> str;

	// convert as lowercase
	for (int i = 0; i < str.length(); i++)
	{
		if (str.at(i) < 'a')
			str.at(i) = str.at(i) + 32;
	}

	string vowel = "aoyeui";

	string ans = "";
	for (int i = 0; i < str.length(); i++)
	{
		if (find(vowel.begin(), vowel.end(), str.at(i)) == vowel.end())
		{
			ans += ".";
			ans += str.at(i);
		}
	}
	
	cout << ans;
}