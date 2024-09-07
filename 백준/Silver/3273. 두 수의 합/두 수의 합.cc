#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, x;
	cin >> n;

	vector<int> num;
	vector<int> vec(2000005, 0);

	int tmp;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		num.push_back(tmp);
	}

	cin >> x;

	int answer = 0;

	for (int i = 0; i < n; i++)
	{
		tmp = num[i];
		if (tmp >= x) continue;

		if (vec[tmp] % 2 == 1) answer++;
		vec[tmp]++;		

		if (abs(x - tmp) == tmp) continue;

		if (vec[abs(x - tmp)] % 2 == 1) answer++;
		vec[abs(x - tmp)]++;
	}

	cout << answer / 2;
	return 0;
}