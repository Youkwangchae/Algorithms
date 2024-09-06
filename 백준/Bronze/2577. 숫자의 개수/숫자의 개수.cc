#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int a, b, c;

	cin >> a >> b >> c;

	long long res = a * b * c;

	string str = to_string(res);
	vector <int> vec(10, 0);

	for (int i = 0; i < str.length(); i++)
	{
		vec[str[i] - '0']++;
	}

	for (int i = 0; i < 10; i++)
		cout << vec[i] << '\n';
}