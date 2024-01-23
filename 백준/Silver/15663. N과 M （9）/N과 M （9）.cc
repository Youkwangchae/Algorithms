#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n, m;
vector<int>vec;
vector<bool>visit;
vector<int>temp;

void brute()
{
	if (temp.size() == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << temp[i] << " ";
		}
		cout << "\n";
	}

	int check = 0;

	for (int i = 0; i < vec.size(); i++) {
		if (visit[i] || check == vec[i]) continue;
		visit[i] = true;
		temp.push_back(vec[i]);
		check = vec[i];
		brute();
		visit[i] = false;
		temp.pop_back();
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	int num;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		vec.push_back(num);
		visit.push_back(false);
	}

	sort(vec.begin(), vec.end());

	brute();
}