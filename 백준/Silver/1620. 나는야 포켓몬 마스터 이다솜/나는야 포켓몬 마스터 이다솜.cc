#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	map<string, int>names;
	map<int, string>numbers;
	string str;

	for (int i = 0; i < n; i++)
	{
		cin >> str;
		names.insert(pair<string, int>(str, i+1));
		numbers.insert(pair<int, string>(i + 1, str));
	}

	string quest;
	for (int i = 0; i < m; i++)
	{
		cin >> quest;

		// string 앞에 한 자리만 보고 정수인지 판단.
		if (isdigit(quest[0]))
			cout << numbers[stoi(quest)] << "\n";
		else
			cout << names[quest] << "\n";
	}
}