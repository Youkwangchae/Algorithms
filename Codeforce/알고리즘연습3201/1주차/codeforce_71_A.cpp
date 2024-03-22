#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<string> vec;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;

		if (str.length() > 10)
			str = str[0] + to_string(str.length() - 2) + str[str.length() - 1];
		vec.push_back(str);
	}

	for (int i = 0; i < n; i++)
	{
		cout << vec[i] << "\n";
	}
}